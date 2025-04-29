// Enemy.hpp
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Point.hpp"  // Add this include!

class Enemy {
public:
    Enemy(Point startPos, float speed);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window, float cellSize) const;
    bool checkCollision(const Point& playerPos) const;

private:
    Point position;
    std::vector<Point> patrolPath;
    float speed;
    float currentPathIndex;
    void generatePatrolPath();
};