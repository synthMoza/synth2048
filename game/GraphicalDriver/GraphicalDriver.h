#pragma once

#include "../GraphicalLibrary.h"
#include "GraphicalObject.h"
#include "../Utilities/Vector2.h"
#include "../Application/Application.h"
#include "../GraphicalDriver/Texture.h"

#include <unordered_map>

namespace se {
    // Maximum number of layers
    const int max_layers = 32;
    class Application;

    class GraphicalDriver {
        sf::RenderWindow* window_; // the pointer to the opened window
        std::vector<Texture*> textures_; // the vector of all opened textures
        // Vector of layers with objects to be drawn during this frame
        std::vector<std::vector<GraphicalObject*>> to_draw_;
    public:
        GraphicalDriver(sf::RenderWindow* window);

        // Draw all objects on the screen by layers
        void drawObjects();
        // Add object to be the vector
        void addObject(GraphicalObject* object);
        // Clears all objects from the vector
        void clearObjects();
        // Load the texture to the graphical driver
        // Returns the unique ID that will identify this texture
        unsigned int loadTexture(std::string path);
        // Returns the pointer to the given texture
        Texture* getTexture(unsigned int ID);

        ~GraphicalDriver();
    };

    class GraphicalAssistant {
        static GraphicalDriver* graphical_driver;
    public:
        // Draw the given object
        static void drawObject(GraphicalObject& object);
        // Get the current resolution of the opened window
        static Vector2u getResolution();
        // Load the texture to the graphical driver
        // Returns the unique ID that will identify this texture
        static unsigned int loadTexture(std::string path);
        // Returns the pointer to the given texture
        static Texture* getTexture(unsigned int ID);
        
        friend class Application;
    };
}