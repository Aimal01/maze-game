// Button.cpp
#include "Button.hpp"

Button::Button(const std::string& buttonText, const sf::Vector2f& position,
               const sf::Vector2f& size, const sf::Color& normal, const sf::Color& hover)
    : isHovered(false), normalColor(normal), hoverColor(hover) {
    
    shape.setSize(size);
    shape.setPosition(position);
    shape.setFillColor(normalColor);

    text.setString(buttonText);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);

    sf::FloatRect textBounds = text.getLocalBounds();
    text.setOrigin(textBounds.left + textBounds.width / 2.0f,
                   textBounds.top + textBounds.height / 2.0f);
    text.setPosition(position.x + size.x / 2.0f,
                    position.y + size.y / 2.0f);
}

void Button::draw(sf::RenderWindow& window) const {
    window.draw(shape);
    window.draw(text);
}

bool Button::contains(const sf::Vector2f& point) const {
    return shape.getGlobalBounds().contains(point);
}

void Button::update(const sf::RenderWindow& window) {
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    bool wasHovered = isHovered;
    isHovered = contains(mousePos);
    
    if (wasHovered != isHovered) {
        shape.setFillColor(isHovered ? hoverColor : normalColor);
    }
}

bool Button::isClicked(const sf::Event& event, const sf::RenderWindow& window) const {
    if (event.type == sf::Event::MouseButtonPressed && 
        event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f mousePos = window.mapPixelToCoords(
            sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
        return contains(mousePos);
    }
    return false;
}