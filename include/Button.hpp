// Button.hpp
#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <functional>

class Button {
public:
    // Constructor
    Button(const std::string& buttonText, const sf::Vector2f& position,
           const sf::Vector2f& size, const sf::Color& normal, const sf::Color& hover);

    // Core functionality
    void draw(sf::RenderWindow& window) const;
    void update(const sf::RenderWindow& window);
    bool isClicked(const sf::Event& event, const sf::RenderWindow& window) const;
    
    // Getters
    bool contains(const sf::Vector2f& point) const;
    const sf::Vector2f& getPosition() const { return shape.getPosition(); }
    const sf::Vector2f& getSize() const { return shape.getSize(); }
    const sf::Color& getNormalColor() const { return normalColor; }
    const sf::Color& getHoverColor() const { return hoverColor; }
    bool isHovering() const { return isHovered; }

    // Setters
    void setPosition(const sf::Vector2f& position);
    void setSize(const sf::Vector2f& size);
    void setColors(const sf::Color& normal, const sf::Color& hover);
    void setText(const std::string& text);
    void setCharacterSize(unsigned int size);
    void setTextColor(const sf::Color& color);

private:
    // Visual components
    sf::RectangleShape shape;
    sf::Text text;
    
    // State tracking
    bool isHovered;
    sf::Color normalColor;
    sf::Color hoverColor;

    // Helper functions
    void centerText();
    void updateHoverState(const sf::Vector2f& mousePosition);
};