#pragma once

#include "../GraphicalLibrary.h"

// The structure that represents colors for sprites, shapes and etc. Transforms them
// into colors from SFML
struct Color {
    uint8_t red_;
    uint8_t green_;
    uint8_t blue_;

    // Default consturctor for creating black color
    Color() : red_ (0), green_ (0), blue_ (0) {}

    // Constructor to specify the color
    Color(uint8_t red, uint8_t green, uint8_t blue) : red_ (red), green_ (green), blue_ (blue) {}
    // Returns the color transormed to SFML
    sf::Color getColor() const {
        return sf::Color(red_, green_, blue_);
    }
};