// PowerUp.hpp
#pragma once
#include "Point.hpp"
#include <SFML/Graphics.hpp>

class PowerUp {
public:
    enum class Type {
        SPEED_BOOST,
        WALL_BREAK,
        TELEPORT,
        REVEAL_PATH,
        TIME_SLOW
    };

    PowerUp(Type type, Point pos);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window, float cellSize) const;

    Type type;
    Point position;
    bool active;
    float duration;
};