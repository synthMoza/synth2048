#include "BasicSketch.h"
#include "SketchDriver.h"
#include "../GameSketch.h"

using namespace se;

BasicSketch::BasicSketch() {
    std::cout << "BasicSketch created!" << std::endl;
}

BasicSketch::~BasicSketch() {
    std::cout << "BasicSketch destroyed!" << std::endl;
}

void BasicSketch::update() {
    SketchAssistant::addSketch(new GameSketch);
    SketchAssistant::removeSketch(this);
}

void BasicSketch::draw() {}