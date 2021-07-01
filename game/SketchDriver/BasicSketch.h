#pragma once

#include "Sketch.h"
#include "../GameSketch.h"

namespace se {

    class BasicSketch : public Sketch {
    public:  
        BasicSketch();

        void update() override;
        void draw() override;

        virtual ~BasicSketch();
    };
}