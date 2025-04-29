// Button.cpp
#include "Button.hpp"
#include "ResourceManager.hpp"

Button::Button(const std::string& buttonText, const sf::Vector2f& position,
               const sf::Vector2f& size, const sf::Color& normal, const sf::Color& hover)
    : isHovered(false)
    , normalColor(normal)
    , hoverColor(hover)
{
    // Setup shape
    shape.setPosition(position);
    shape.setSize(size);
    shape.setFillColor(normalColor);

    // Setup text
    text.setFont(ResourceManager::getInstance().getFont());
    text.setString(buttonText);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    
    centerText();
}

void Button::draw(sf::RenderWindow& window) const {
    window.draw(shape);
    window.draw(text);
}

void Button::update(const sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    updateHoverState(window.mapPixelToCoords(mousePos));
}

bool Button::isClicked(const sf::Event& event, const sf::RenderWindow& window) const {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        return contains(window.mapPixelToCoords(mousePos));
    }
    return false;
}

bool Button::contains(const sf::Vector2f& point) const {
    return shape.getGlobalBounds().contains(point);
}

void Button::setPosition(const sf::Vector2f& position) {
    shape.setPosition(position);
    centerText();
}

void Button::setSize(const sf::Vector2f& size) {
    shape.setSize(size);
    centerText();
}

void Button::setColors(const sf::Color& normal, const sf::Color& hover) {
    normalColor = normal;
    hoverColor = hover;
    if (!isHovered) {
        shape.setFillColor(normalColor);
    }
}

void Button::setText(const std::string& newText) {
    text.setString(newText);
    centerText();
}

void Button::setCharacterSize(unsigned int size) {
    text.setCharacterSize(size);
    centerText();
}

void Button::setTextColor(const sf::Color& color) {
    text.setFillColor(color);
}

void Button::centerText() {
    sf::FloatRect textBounds = text.getLocalBounds();
    sf::Vector2f shapePos = shape.getPosition();
    sf::Vector2f shapeSize = shape.getSize();
    
    float xPos = shapePos.x + (shapeSize.x - textBounds.width) / 2.f - textBounds.left;
    float yPos = shapePos.y + (shapeSize.y - textBounds.height) / 2.f - textBounds.top;
    
    text.setPosition(xPos, yPos);
}

void Button::updateHoverState(const sf::Vector2f& mousePosition) {
    bool wasHovered = isHovered;
    isHovered = contains(mousePosition);
    
    if (wasHovered != isHovered) {
        shape.setFillColor(isHovered ? hoverColor : normalColor);
    }
}