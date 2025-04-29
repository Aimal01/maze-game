// ParticleSystem.hpp
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class ParticleSystem {
public:
    ParticleSystem();
    void addParticle(const sf::Vector2f& position, const sf::Color& color);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window) const;

private:
    struct Particle {
        sf::Vector2f position;
        sf::Vector2f velocity;
        sf::Color color;
        float lifetime;
    };
    std::vector<Particle> particles;
};