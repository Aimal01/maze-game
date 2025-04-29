// ParticleSystem.cpp
#include "ParticleSystem.hpp"
#include <cmath>

ParticleSystem::ParticleSystem() {}

void ParticleSystem::addParticle(const sf::Vector2f& position, const sf::Color& color) {
    Particle particle;
    particle.position = position;
    particle.color = color;
    particle.lifetime = 1.0f;
    
    float angle = static_cast<float>(rand()) / RAND_MAX * 2 * 3.14159f;
    float speed = 50.0f + static_cast<float>(rand()) / RAND_MAX * 50.0f;
    particle.velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
    
    particles.push_back(particle);
}

void ParticleSystem::update(float deltaTime) {
    for (auto& particle : particles) {
        particle.position += particle.velocity * deltaTime;
        particle.velocity.y += 200.0f * deltaTime; // Gravity
        particle.lifetime -= deltaTime;
        particle.color.a = static_cast<sf::Uint8>(255 * particle.lifetime);
    }

    particles.erase(
        std::remove_if(particles.begin(), particles.end(),
            [](const Particle& p) { return p.lifetime <= 0; }),
        particles.end()
    );
}

void ParticleSystem::draw(sf::RenderWindow& window) const {
    sf::CircleShape shape(2.0f);
    for (const auto& particle : particles) {
        shape.setPosition(particle.position);
        shape.setFillColor(particle.color);
        window.draw(shape);
    }
}