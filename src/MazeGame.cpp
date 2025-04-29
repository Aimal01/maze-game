#include "MazeGame.hpp"
#include "GameInfo.hpp"
#include "Constants.hpp"
#include "ResourceManager.hpp"
#include <vector>
#include <stack>
#include <random>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <fstream>

MazeGame::MazeGame()
    : state(GameState::DIFFICULTY_SELECT)
    , difficulty(Difficulty::MEDIUM)
    , showSolution(false)
    , cellSize(GameConstants::BASE_CELL_SIZE)
    , stats() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    initialize();
}

void MazeGame::saveHighScore() {
    try {
        std::ofstream file("highscore.dat", std::ios::binary);
        if (file.is_open()) {
            file.write(reinterpret_cast<const char*>(&stats.highScore), sizeof(stats.highScore));
            file.close();
        }
    } catch (const std::exception& e) {
        // Silently fail if we can't save the high score
    }
}

void MazeGame::loadHighScore() {
    try {
        std::ifstream file("highscore.dat", std::ios::binary);
        if (file.is_open()) {
            file.read(reinterpret_cast<char*>(&stats.highScore), sizeof(stats.highScore));
            file.close();
        } else {
            stats.highScore = 0;  // Default value if file doesn't exist
        }
    } catch (const std::exception& e) {
        stats.highScore = 0;  // Default value if there's an error
    }
}

void MazeGame::initialize() {
    window.create(sf::VideoMode(GameConstants::SCREEN_WIDTH, GameConstants::SCREEN_HEIGHT),
                 "Maze Game - " + GameInfo::CURRENT_USER);
    window.setFramerateLimit(60);

    gameView = window.getDefaultView();
    minimapView = sf::View(sf::FloatRect(0, 0, GameConstants::SCREEN_WIDTH, GameConstants::SCREEN_HEIGHT));
    minimapView.setViewport(sf::FloatRect(0.75f, 0.0f, 0.25f, 0.25f));

    createButtons();
    
    statusText.setFont(ResourceManager::getInstance().getFont());
    statusText.setCharacterSize(20);
    statusText.setFillColor(sf::Color::White);
    statusText.setPosition(10.f, 10.f);

    loadHighScore();
    GameInfo::printGameInfo();
}

void MazeGame::startNewGame() {
    stats.resetForNewGame();
    generateMaze();
}

void MazeGame::createButtons() {
    const float buttonWidth = 200.f;
    const float buttonHeight = 50.f;
    const float spacing = 20.f;
    const float startY = GameConstants::SCREEN_HEIGHT * 0.3f;

    std::vector<std::pair<std::string, sf::Color>> difficultyInfo = {
        {"Easy", sf::Color(76, 175, 80)},      // Green
        {"Medium", sf::Color(255, 152, 0)},    // Orange
        {"Hard", sf::Color(244, 67, 54)}       // Red
    };

    float currentY = startY;
    for (const auto& info : difficultyInfo) {
        sf::Vector2f position((GameConstants::SCREEN_WIDTH - buttonWidth) / 2.f, currentY);
        sf::Vector2f size(buttonWidth, buttonHeight);
        
        auto button = std::make_unique<Button>(
            info.first,
            position,
            size,
            info.second,
            sf::Color(info.second.r * 0.8, info.second.g * 0.8, info.second.b * 0.8)
        );
        buttons.push_back(std::move(button));
        currentY += buttonHeight + spacing;
    }
}

void MazeGame::run() {
    while (window.isOpen()) {
        float deltaTime = gameClock.restart().asSeconds();
        
        switch (state) {
            case GameState::DIFFICULTY_SELECT:
                handleDifficultySelection();
                drawDifficultyMenu();
                break;
                
            case GameState::PLAYING:
                handleInput();
                update(deltaTime);
                render();
                break;
                
            case GameState::PAUSED:
                handleInput();
                render();
                break;
                
            case GameState::GAME_OVER:
                handleInput();
                render();
                break;
                
            default:
                break;
        }
    }
}

void MazeGame::handleDifficultySelection() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            return;
        }

        for (size_t i = 0; i < buttons.size(); i++) {
            if (buttons[i]->isClicked(event, window)) {
                switch(i) {
                    case 0: difficulty = Difficulty::EASY; break;
                    case 1: difficulty = Difficulty::MEDIUM; break;
                    case 2: difficulty = Difficulty::HARD; break;
                }
                state = GameState::PLAYING;
                startNewGame();
                return;
            }
        }
    }

    for (auto& button : buttons) {
        button->update(window);
    }
}

void MazeGame::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        else if (event.type == sf::Event::KeyPressed) {
            handleKeyPress(event.key.code);
        }
    }
}

void MazeGame::handleKeyPress(sf::Keyboard::Key key) {
    if (state == GameState::GAME_OVER) {
        if (key == sf::Keyboard::Escape) {
            state = GameState::DIFFICULTY_SELECT;
            stats.resetForNewGame();
            return;
        }
        return;
    }

    if (state == GameState::PAUSED) {
        if (key == sf::Keyboard::Escape) {
            state = GameState::PLAYING;
        }
        return;
    }

    if (state != GameState::PLAYING) {
        return;
    }

    Point newPos = playerPos;
    bool moved = false;

    switch (key) {
        case sf::Keyboard::W:
        case sf::Keyboard::Up:    newPos.y--; moved = true; break;
        case sf::Keyboard::S:
        case sf::Keyboard::Down:  newPos.y++; moved = true; break;
        case sf::Keyboard::A:
        case sf::Keyboard::Left:  newPos.x--; moved = true; break;
        case sf::Keyboard::D:
        case sf::Keyboard::Right: newPos.x++; moved = true; break;
        case sf::Keyboard::Space: showSolution = !showSolution; break;
        case sf::Keyboard::Escape: state = GameState::PAUSED; break;
        case sf::Keyboard::R: 
            startNewGame();
            break;
        default: break;
    }

    if (moved && isValidMove(newPos)) {
        movePlayer(newPos);
        if (newPos == endPos) {
            updateScore();
            generateMaze();
            stats.moveCount = 0;
            stats.timeElapsed = 0.0f;
        }
    }
}

void MazeGame::update(float deltaTime) {
    if (state != GameState::PLAYING) return;

    stats.timeElapsed += deltaTime;
    
    float speedMultiplier;
    switch (difficulty) {
        case Difficulty::EASY: speedMultiplier = 1.0f; break;
        case Difficulty::MEDIUM: speedMultiplier = 1.5f; break;
        case Difficulty::HARD: speedMultiplier = 2.0f; break;
    }
    
    for (auto& enemy : enemies) {
        enemy.update(deltaTime * speedMultiplier);
        if (enemy.checkCollision(playerPos)) {
            handleGameOver();
            return;
        }
    }

    for (auto& powerup : powerUps) {
        powerup.update(deltaTime);
    }
}

void MazeGame::render() {
    window.clear(sf::Color(30, 30, 30));

    if (state == GameState::PLAYING || state == GameState::PAUSED) {
        window.setView(gameView);
        drawMaze();
        
        for (const auto& powerup : powerUps) {
            powerup.draw(window, cellSize);
        }
        
        for (const auto& enemy : enemies) {
            enemy.draw(window, cellSize);
        }

        std::stringstream ss;
        ss << "Score: " << stats.score << "\n"
           << "Time: " << static_cast<int>(stats.timeElapsed) << "s\n"
           << "Moves: " << stats.moveCount << "\n"
           << "High Score: " << stats.highScore;
        
        if (state == GameState::PAUSED) {
            ss << "\n\nPAUSED";
        }
        
        statusText.setString(ss.str());
        window.draw(statusText);

        window.setView(minimapView);
        drawMaze();
    }
    else if (state == GameState::GAME_OVER) {
        drawGameOver();
    }

    window.display();
}

void MazeGame::drawGameOver() {
    sf::Text gameOverText;
    gameOverText.setFont(ResourceManager::getInstance().getFont());
    gameOverText.setString("Game Over!\nFinal Score: " + std::to_string(stats.score) + 
                          "\nPress ESC to return to menu");
    gameOverText.setCharacterSize(30);
    gameOverText.setFillColor(sf::Color::White);
    
    sf::FloatRect textBounds = gameOverText.getLocalBounds();
    gameOverText.setPosition(
        (GameConstants::SCREEN_WIDTH - textBounds.width) / 2.f,
        (GameConstants::SCREEN_HEIGHT - textBounds.height) / 2.f
    );
    
    window.draw(gameOverText);
}

void MazeGame::drawDifficultyMenu() {
    window.clear(sf::Color(30, 30, 30));

    sf::Text title;
    title.setFont(ResourceManager::getInstance().getFont());
    title.setString("Select Difficulty");
    title.setCharacterSize(40);
    title.setFillColor(sf::Color::White);
    
    sf::FloatRect titleBounds = title.getLocalBounds();
    title.setPosition(
        (GameConstants::SCREEN_WIDTH - titleBounds.width) / 2.f,
        GameConstants::SCREEN_HEIGHT * 0.15f
    );

    window.draw(title);

    for (const auto& button : buttons) {
        button->draw(window);
    }

    window.display();
}

void MazeGame::drawMaze() {
    sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));

    for (size_t y = 0; y < maze.size(); ++y) {
        for (size_t x = 0; x < maze[y].size(); ++x) {
            cell.setPosition(x * cellSize, y * cellSize);
            
            if (Point(x, y) == playerPos) {
                cell.setFillColor(sf::Color::Cyan);
            }
            else if (Point(x, y) == endPos) {
                cell.setFillColor(sf::Color::Green);
            }
            else if (maze[y][x] == '#') {
                cell.setFillColor(sf::Color(50, 50, 50));
            }
            else {
                cell.setFillColor(sf::Color(200, 200, 200));
            }

            window.draw(cell);
        }
    }
}

void MazeGame::generateMaze() {
    int width, height;
    switch (difficulty) {
        case Difficulty::EASY:
            width = height = 15;
            break;
        case Difficulty::MEDIUM:
            width = height = 21;
            break;
        case Difficulty::HARD:
            width = height = 31;
            break;
    }
    
    maze = std::vector<std::vector<char>>(height, std::vector<char>(width, '#'));
    
    playerPos = Point(1, 1);
    endPos = Point(width - 2, height - 2);
    
    std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));
    std::stack<Point> stack;
    Point current = playerPos;
    
    while (current != endPos) {
        visited[current.y][current.x] = true;
        maze[current.y][current.x] = ' ';
        
        std::vector<Point> neighbors;
        std::vector<Point> directions = {
            Point(0, -2), // Up
            Point(0, 2),  // Down
            Point(-2, 0), // Left
            Point(2, 0)   // Right
        };
        
        for (const auto& dir : directions) {
            Point next(current.x + dir.x, current.y + dir.y);
            if (next.x > 0 && next.x < width - 1 && 
                next.y > 0 && next.y < height - 1 && 
                !visited[next.y][next.x]) {
                neighbors.push_back(next);
            }
        }
        
        if (!neighbors.empty()) {
            int idx = std::rand() % neighbors.size();
            Point next = neighbors[idx];
            maze[(current.y + next.y) / 2][(current.x + next.x) / 2] = ' ';
            stack.push(current);
            current = next;
        } else if (!stack.empty()) {
            current = stack.top();
            stack.pop();
        } else {
            break;
        }
    }
    
    maze[playerPos.y][playerPos.x] = ' ';
    maze[endPos.y][endPos.x] = ' ';
    
    int pathCount;
    switch (difficulty) {
        case Difficulty::EASY:
            pathCount = width * height / 8;  // More paths = easier
            break;
        case Difficulty::MEDIUM:
            pathCount = width * height / 10;
            break;
        case Difficulty::HARD:
            pathCount = width * height / 15; // Fewer paths = harder
            break;
    }
    
    for (int i = 0; i < pathCount; i++) {
        int x = 1 + std::rand() % (width - 2);
        int y = 1 + std::rand() % (height - 2);
        if (Point(x, y) != playerPos && Point(x, y) != endPos) {
            maze[y][x] = ' ';
        }
    }

    enemies.clear();
    int enemyCount;
    float enemySpeed;
    switch (difficulty) {
        case Difficulty::EASY:
            enemyCount = 2;
            enemySpeed = 1.0f;
            break;
        case Difficulty::MEDIUM:
            enemyCount = 4;
            enemySpeed = 1.5f;
            break;
        case Difficulty::HARD:
            enemyCount = 6;
            enemySpeed = 2.0f;
            break;
    }

    for (int i = 0; i < enemyCount; i++) {
        Point pos;
        do {
            pos.x = 1 + std::rand() % (width - 2);
            pos.y = 1 + std::rand() % (height - 2);
        } while (pos == playerPos || pos == endPos || maze[pos.y][pos.x] != ' ');
        
        enemies.emplace_back(pos, enemySpeed);
    }
}

void MazeGame::updateScore() {
    float multiplier;
    switch (difficulty) {
        case Difficulty::EASY:
            multiplier = 1.0f;
            break;
        case Difficulty::MEDIUM:
            multiplier = 1.5f;
            break;
        case Difficulty::HARD:
            multiplier = 2.0f;
            break;
    }
    
    int mazeScore = static_cast<int>(1000 * multiplier);
    mazeScore -= static_cast<int>(stats.timeElapsed * (10 * multiplier));
    mazeScore -= static_cast<int>(stats.moveCount * (5 * multiplier));
    
    if (mazeScore < 0) mazeScore = 0;
    stats.score += mazeScore;
    
    if (stats.score > stats.highScore) {
        stats.highScore = stats.score;
        saveHighScore();
    }
}

void MazeGame::handleGameOver() {
    if (stats.score > stats.highScore) {
        stats.highScore = stats.score;
        saveHighScore();
    }
    state = GameState::GAME_OVER;
}

bool MazeGame::isValidMove(const Point& pos) const {
    if (pos.x < 0 || pos.x >= static_cast<int>(maze[0].size()) ||
        pos.y < 0 || pos.y >= static_cast<int>(maze.size())) {
        return false;
    }
    return maze[pos.y][pos.x] == ' ';
}

void MazeGame::movePlayer(const Point& newPos) {
    playerPos = newPos;
    stats.moveCount++;
}