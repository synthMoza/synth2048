#pragma once

#include "../Utilities/Vector2.h"
#include "../SketchDriver/SketchDriver.h"
#include "../GraphicalDriver/GraphicalDriver.h"

#include "../GraphicalLibrary.h"
#include "../TimeDriver/TimeDriver.h"
#include "../InputDriver/InputDriver.h"

namespace se {
    // The main class for launching the app
    class Application {
        // The resolution of the window
        static Vector2u resolution_;
        // unsigned int resolution_height_; // the height of the window
        // unsigned int resolution_width_; // the width of the window
        sf::RenderWindow* window_; // the pointer to the main window 
    public:
        Application(unsigned int resolution_width, unsigned int resolution_height, const std::string& title);
        
        // Returns the current resolution of the opened window
        static Vector2u getResolution() {
            return resolution_;
        }
        // Launch the application - the main loop of the application
        void launch();

        ~Application();
    };
}