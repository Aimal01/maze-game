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

MazeGame::MazeGame()
    : state(GameState::MENU)
    , difficulty(Difficulty::MEDIUM)
    , showSolution(false) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    initialize();
}

void MazeGame::initialize() {
    // Create window
    window.create(sf::VideoMode(GameConstants::SCREEN_WIDTH, GameConstants::SCREEN_HEIGHT),
                 "Maze Game - " + GameInfo::CURRENT_USER);
    window.setFramerateLimit(60);

    // Initialize views
    gameView = window.getDefaultView();
    minimapView = sf::View(sf::FloatRect(0, 0, GameConstants::SCREEN_WIDTH, GameConstants::SCREEN_HEIGHT));
    minimapView.setViewport(sf::FloatRect(0.75f, 0.0f, 0.25f, 0.25f));

    // Initialize game state
    state = GameState::PLAYING;
    difficulty = Difficulty::MEDIUM;
    stats = GameStats();
    showSolution = false;

    // Generate initial maze
    generateMaze();

    // Initialize UI
    statusText.setFont(ResourceManager::getInstance().getFont());
    statusText.setCharacterSize(20);
    statusText.setFillColor(sf::Color::White);
    statusText.setPosition(10.f, 10.f);

    GameInfo::printGameInfo();
}

void MazeGame::run() {
    while (window.isOpen()) {
        float deltaTime = gameClock.restart().asSeconds();
        handleInput();
        update(deltaTime);
        render();
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

void MazeGame::update(float deltaTime) {
    if (state != GameState::PLAYING) return;

    stats.timeElapsed += deltaTime;
    
    // Update game entities
    for (auto& powerup : powerUps) {
        powerup.update(deltaTime);
    }
    
    for (auto& enemy : enemies) {
        enemy.update(deltaTime);
        if (enemy.checkCollision(playerPos)) {
            handleGameOver();
        }
    }
}

void MazeGame::render() {
    window.clear(sf::Color(30, 30, 30));

    if (state == GameState::PLAYING) {
        window.setView(gameView);
        drawMaze();
        
        // Draw entities
        for (const auto& powerup : powerUps) {
            powerup.draw(window, cellSize);
        }
        
        for (const auto& enemy : enemies) {
            enemy.draw(window, cellSize);
        }

        // Draw UI
        std::stringstream ss;
        ss << "Score: " << stats.score << "\n"
           << "Time: " << static_cast<int>(stats.timeElapsed) << "s\n"
           << "Moves: " << stats.moveCount;
        statusText.setString(ss.str());
        window.draw(statusText);

        // Draw minimap
        window.setView(minimapView);
        drawMaze();
    }

    window.display();
}
void MazeGame::drawMaze() {
    float cellSize = GameConstants::BASE_CELL_SIZE;
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

void MazeGame::handleKeyPress(sf::Keyboard::Key key) {
    if (state != GameState::PLAYING) return;

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
        default: break;
    }

    if (moved && isValidMove(newPos)) {
        movePlayer(newPos);
        
        // Check if reached end
        if (newPos == endPos) {
            stats.score += 1000;
            stats.score -= static_cast<int>(stats.timeElapsed * 10);
            stats.score -= stats.moveCount * 5;
            if (stats.score < 0) stats.score = 0;
            
            // Generate new maze
            generateMaze();
        }
    }
}

void MazeGame::generateMaze() {
    // Create a maze with proper paths using a simple algorithm
    int width = 21, height = 21;
    maze = std::vector<std::vector<char>>(height, std::vector<char>(width, '#'));
    
    // Start and end positions
    playerPos = Point(1, 1);
    endPos = Point(width - 2, height - 2);
    
    // Create a path from start to end using recursive backtracking
    std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));
    std::stack<Point> stack;
    Point current = playerPos;
    
    while (current != endPos) {
        visited[current.y][current.x] = true;
        maze[current.y][current.x] = ' ';  // Clear current cell
        
        // Get possible directions
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
            // Choose random neighbor
            int idx = std::rand() % neighbors.size();
            Point next = neighbors[idx];
            
            // Clear the wall between current and next
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
    
    // Make sure start and end are clear
    maze[playerPos.y][playerPos.x] = ' ';
    maze[endPos.y][endPos.x] = ' ';
    
    // Add a few random paths for variety
    for (int i = 0; i < width * height / 10; i++) {
        int x = 1 + std::rand() % (width - 2);
        int y = 1 + std::rand() % (height - 2);
        if (Point(x, y) != playerPos && Point(x, y) != endPos) {
            maze[y][x] = ' ';
        }
    }
}
// ... (keep the rest of your existing code, including generateMaze())