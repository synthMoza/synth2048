#pragma once

#include "../GraphicalDriver/GraphicalDriver.h"

#include <cstddef>
#include <iostream>
#include <vector>

namespace se {
    // Forward declaration of the skecth driver
    class SketchDriver;

    // The scetch class for designing the certain part of the application
    class Sketch {
    public:
        Sketch() {}

        // Update and draw the objects of this sketch
        virtual void update() = 0;
        virtual void draw() = 0;

        virtual ~Sketch();
    };
}