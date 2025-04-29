// ResourceManager.hpp
#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>

class ResourceManager {
public:
    static ResourceManager& getInstance() {
        static ResourceManager instance;
        return instance;
    }

    const sf::Font& getFont() {
        if (!fontLoaded) {
            // Try different common font paths
            const std::vector<std::string> fontPaths = {
                "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf",
                "/usr/share/fonts/TTF/DejaVuSans.ttf",
                "/usr/share/fonts/dejavu/DejaVuSans.ttf",
                "DejaVuSans.ttf",
                "/usr/share/fonts/truetype/liberation/LiberationSans-Regular.ttf",
                "/usr/share/fonts/TTF/Arial.ttf"
            };

            for (const auto& path : fontPaths) {
                if (font.loadFromFile(path)) {
                    fontLoaded = true;
                    std::cout << "Loaded font from: " << path << std::endl;
                    break;
                }
            }

            if (!fontLoaded) {
                std::cerr << "Warning: Could not load any font!" << std::endl;
                // Create a simple font as fallback
                font = sf::Font();
            }
        }
        return font;
    }

private:
    ResourceManager() : fontLoaded(false) {} // Private constructor
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;

    sf::Font font;
    bool fontLoaded;
};