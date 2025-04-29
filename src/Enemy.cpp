// Enemy.cpp
#include "Enemy.hpp"
#include <cmath>

Enemy::Enemy(Point startPos, float speed)
    : position(startPos), speed(speed), currentPathIndex(0.0f) {
    generatePatrolPath();
}

void Enemy::update(float deltaTime) {
    if (patrolPath.size() < 2) return;

    currentPathIndex += speed * deltaTime;
    while (currentPathIndex >= patrolPath.size()) {
        currentPathIndex -= patrolPath.size();
    }

    int currentIndex = static_cast<int>(currentPathIndex);
    int nextIndex = (currentIndex + 1) % patrolPath.size();
    float fraction = currentPathIndex - currentIndex;

    position = Point(
        patrolPath[currentIndex].x + 
            (patrolPath[nextIndex].x - patrolPath[currentIndex].x) * fraction,
        patrolPath[currentIndex].y + 
            (patrolPath[nextIndex].y - patrolPath[currentIndex].y) * fraction
    );
}

void Enemy::draw(sf::RenderWindow& window, float cellSize) const {
    sf::CircleShape shape(cellSize * 0.4f);
    shape.setPosition(position.x * cellSize + cellSize * 0.1f,
                     position.y * cellSize + cellSize * 0.1f);
    shape.setFillColor(sf::Color::Red);
    window.draw(shape);
}

bool Enemy::checkCollision(const Point& playerPos) const {
    return std::abs(position.x - playerPos.x) < 1.0f &&
           std::abs(position.y - playerPos.y) < 1.0f;
}

void Enemy::generatePatrolPath() {
    patrolPath = {
        position,
        Point(position.x + 3, position.y),
        Point(position.x + 3, position.y + 3),
        Point(position.x, position.y + 3)
    };
}