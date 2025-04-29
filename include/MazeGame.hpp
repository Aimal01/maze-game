// MazeGame.hpp
#pragma once
#include <SFML/Graphics.hpp>
#include "Point.hpp"
#include "PowerUp.hpp"
#include "Enemy.hpp"
#include "ParticleSystem.hpp"
#include "Button.hpp"
#include <vector>
#include <memory>

class MazeGame {
public:
    MazeGame();
    void run();

private:
    enum class GameState { 
        MENU, 
        PLAYING, 
        PAUSED, 
        GAME_OVER, 
        EDITOR, 
        DIFFICULTY_SELECT  // Added this state
    };
    
    enum class Difficulty { 
        EASY, 
        MEDIUM, 
        HARD, 
        CUSTOM 
    };

    struct GameStats {
        int moveCount = 0;
        float timeElapsed = 0.0f;
        int score = 0;
        int powerUpsCollected = 0;
        int highScore = 0;
    };

    // Game state
    GameState state;
    Difficulty difficulty;
    GameStats stats;
    bool showSolution;
    std::vector<std::vector<char>> maze;
    Point playerPos;
    Point endPos;
    std::vector<PowerUp> powerUps;
    std::vector<Enemy> enemies;
    ParticleSystem particles;
    float cellSize;

    // SFML objects
    sf::RenderWindow window;
    sf::View gameView;
    sf::View minimapView;
    sf::Clock gameClock;
    sf::Text statusText;
    std::vector<std::unique_ptr<Button>> buttons;

    // Initialize functions
    void initialize();
    void initializeSettings();
    void createButtons();
    void initializeText();

    // Input handling
    void handleInput();
    void handleKeyPress(sf::Keyboard::Key key);
    void handleDifficultySelection();

    // Update functions
    void update(float deltaTime);
    void updateAchievements();
    void updateScore();

    // Render functions
    void render();
    void drawMaze();
    void drawUI();
    void drawMinimap();
    void drawEntities();
    void drawDifficultyMenu();
    void drawGameOver();

    // Game logic
    void generateMaze();
    void loadHighScore();
    void saveHighScore();
    
    bool isValidMove(const Point& pos) const {
        return pos.x >= 0 && pos.x < maze[0].size() &&
               pos.y >= 0 && pos.y < maze.size() &&
               maze[pos.y][pos.x] == ' ';
    }

    void movePlayer(const Point& newPos) {
        playerPos = newPos;
        stats.moveCount++;
    }

    void toggleSolution() {
        showSolution = !showSolution;
    }

    void handleGameOver() {
        state = GameState::GAME_OVER;
    }
};