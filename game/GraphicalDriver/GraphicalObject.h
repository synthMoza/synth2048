#pragma once

#include "../GraphicalLibrary.h"
#include "../Utilities/Vector2.h"

namespace se {
    // Base class for all objects in the game that can be drawn, resized and updated. Determines
    // basic interface for such objects. All such objects should be inherited from this base class.

    // TODO
    class GraphicalObject {
    protected:
        sf::Drawable* object_; // the pointer to SFML drawable object for GraphicalDriver
        sf::Transformable* size_object_; // the pointer to SFML transformable object for GraphicalDriver
        std::size_t layer_; // the layer on which the object will be drawn
    public:
        GraphicalObject();

        // Set position of the graphical object's origin
        void setPosition(Vector2f pos);
        // Set graphical object's origin
        void setOrigin(Vector2f origin);
        // Set the scale of the circle shape
        void setScale(Vector2f scale);
        // Move the graphical object by the given offset
        void move(Vector2f offset);

        // Getters
        Vector2f getPosition();
        Vector2f getOrigin();
        Vector2f getScale();

        virtual ~GraphicalObject();

        friend class GraphicalDriver;
    };
}