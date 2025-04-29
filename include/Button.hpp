// Button.hpp
#pragma once
#include <SFML/Graphics.hpp>

class Button {
public:
    Button(const std::string& buttonText, const sf::Vector2f& position,
           const sf::Vector2f& size, const sf::Color& normal, const sf::Color& hover);
    void draw(sf::RenderWindow& window) const;
    bool contains(const sf::Vector2f& point) const;
    void update(const sf::RenderWindow& window);
    bool isClicked(const sf::Event& event, const sf::RenderWindow& window) const;

private:
    sf::RectangleShape shape;
    sf::Text text;
    bool isHovered;
    sf::Color normalColor;
    sf::Color hoverColor;
};