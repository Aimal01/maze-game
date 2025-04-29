#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Point.hpp"
#include "Enemy.hpp"
#include "PowerUp.hpp"
#include "Button.hpp"

class MazeGame {
public:
    enum class GameState {
        DIFFICULTY_SELECT,
        PLAYING,
        PAUSED,
        GAME_OVER
    };

    enum class Difficulty {
        EASY,
        MEDIUM,
        HARD
    };

    struct GameStats {
        int score;          // Current game score
        int moveCount;      // Number of moves in current game
        float timeElapsed;  // Time elapsed in current game
        int highScore;      // All-time high score
        int powerUpsCollected;

        GameStats() : score(0), moveCount(0), timeElapsed(0.0f), highScore(0), powerUpsCollected(0) {}
        
        void resetForNewGame() {
            score = 0;
            moveCount = 0;
            timeElapsed = 0.0f;
            powerUpsCollected = 0;
        }
    };

    MazeGame();
    void run();

private:
    void initialize();
    void createButtons();
    void handleDifficultySelection();
    void handleInput();
    void handleKeyPress(sf::Keyboard::Key key);
    void update(float deltaTime);
    void render();
    void drawGameOver();
    void drawDifficultyMenu();
    void drawMaze();
    void generateMaze();
    void updateScore();
    void loadHighScore();
    void saveHighScore();
    bool isValidMove(const Point& pos) const;
    void movePlayer(const Point& newPos);
    void handleGameOver();
    void startNewGame();

    sf::RenderWindow window;
    sf::View gameView;
    sf::View minimapView;
    sf::Text statusText;
    sf::Clock gameClock;

    std::vector<std::vector<char>> maze;
    std::vector<std::unique_ptr<Button>> buttons;
    std::vector<Enemy> enemies;
    std::vector<PowerUp> powerUps;

    GameState state;
    Difficulty difficulty;
    GameStats stats;
    Point playerPos;
    Point endPos;
    float cellSize;
    bool showSolution;
};