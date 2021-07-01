#pragma once

#include "../GraphicalDriver.h"
#include "../GraphicalObject.h"
#include "../../GraphicalLibrary.h"
#include "../Color.h"
#include "../../Utilities/Vector2.h"

namespace se {

    // Class for drawing simple circle shapes. To construct this class,
    // CircleShapeData must be given.
    class CircleShape final : public GraphicalObject {
        sf::CircleShape* circle_shape_; // the pointer to SFML circlr shape object
    public:
        CircleShape();

        // Set circle's radius
        void setRadius(float radius);
        // Set circle's filling color
        void setFillColor(const Color& color);
        // Set circle's outline color
        void setOutlineColor(const Color& color);
        // Set circle's outline thickness
        void setOutlineThickness(float thickness);

        // Getters for parameters of circle shape
        
        float getRadius();
        Color getFillColor();
        Color getOutlineColor();
        float getOutlineThickness();

        // TODO Getters

        ~CircleShape();
    };
}