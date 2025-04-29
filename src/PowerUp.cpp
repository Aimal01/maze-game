// PowerUp.cpp
#include "PowerUp.hpp"
#include "Constants.hpp"

PowerUp::PowerUp(Type type, Point pos)
    : type(type), position(pos), active(true), duration(GameConstants::POWERUP_DURATION) {}

void PowerUp::update(float deltaTime) {
    if (active && duration > 0) {
        duration -= deltaTime;
        if (duration <= 0) {
            active = false;
        }
    }
}

void PowerUp::draw(sf::RenderWindow& window, float cellSize) const {
    if (!active) return;

    sf::CircleShape shape(cellSize / 3.f);
    shape.setPosition(position.x * cellSize + cellSize / 3.f,
                     position.y * cellSize + cellSize / 3.f);
    
    switch (type) {
        case Type::SPEED_BOOST:
            shape.setFillColor(sf::Color::Yellow);
            break;
        case Type::WALL_BREAK:
            shape.setFillColor(sf::Color::Red);
            break;
        case Type::TELEPORT:
            shape.setFillColor(sf::Color::Blue);
            break;
        case Type::REVEAL_PATH:
            shape.setFillColor(sf::Color::Green);
            break;
        case Type::TIME_SLOW:
            shape.setFillColor(sf::Color::Magenta);
            break;
    }

    window.draw(shape);
}