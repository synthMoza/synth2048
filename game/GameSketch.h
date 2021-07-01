#pragma once

#include "TimeDriver/TimeDriver.h"
#include "SketchDriver/Sketch.h"
#include "GraphicalDriver/Shapes/CircleShape.h"
#include "InputDriver/InputDriver.h"
#include "GraphicalDriver/Sprite/Sprite.h"

#include <vector>
#include <map>

using namespace se;

class GameSketch : public Sketch {
    Sprite* background_;
    Sprite* tiles_[4][4]; // sprites that are put to cells
    unsigned int tiles_values_[4][4]; // values to be stored in cells
    std::vector<unsigned int> free_tiles_; // all free tiles
    std::map<unsigned int, unsigned int> textures_;
    unsigned long score_;

    // Show current score
    void showScore();

    // Update free tiles on the filed
    void updateFree();

    // Spawn a random tile on the field
    void spawnTile();

    // Methods for moving tiles
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();

    // Check for victory
    bool victoryCheck();

    // Associate textures with tiles with proper numbers
    void associateTextures();
    // Load all tiles textures
    void loadTextures();
public:
    GameSketch();

    void update() override;
    void draw() override;

    virtual ~GameSketch();
};
