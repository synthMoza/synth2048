#include "GameSketch.h"

using namespace se;

const int TILE_SIZE = 120;

bool GameSketch::victoryCheck() {
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (tiles_values_[i][j] >= 2048)
                return true;

    return false;
}

void GameSketch::showScore() {
    std::cout << "[SCORE] " << score_ << std::endl;
}

void GameSketch::loadTextures() {
    // Open all tiles textures
    std::string extension = ".png";
    std::string name;
    std::string path;
    unsigned int value = 0;
    unsigned int id = 0;

    // Load textures with numbers
    for (int i = 0; i < 11; ++i) {
        value = pow(2, i);
        name = std::to_string(value);
        path = "Game_Sprites/" + name + extension;
        id = GraphicalAssistant::loadTexture(path);
        textures_[value] = id;
    }
}

GameSketch::GameSketch() {
    // Background
    unsigned int id = GraphicalAssistant::loadTexture("Game_Sprites/background.png");
    // std::cout << "BACKGROUND ID: " << id << std::endl;
    background_ = new Sprite;
    background_->setTexture(id);
    background_->setPosition({0, 0});

    score_ = 0;
    // Init all values to zero
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            tiles_values_[i][j] = 0;
        }
    }

    // Load tiles' textures
    loadTextures();

    // Set all free tiles
    free_tiles_.reserve(16);
    for (int i = 0; i < 16; ++i)
        free_tiles_.push_back(i);

    // Create array of tiles
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            tiles_[i][j] = new Sprite;
            tiles_[i][j]->setScale({0.25, 0.25});
        }
    }

    spawnTile();
    std::cout << "GameSketch created!" << std::endl;
}

GameSketch::~GameSketch() {
    std::cout << "GameSketch destroyed!" << std::endl;
}

void GameSketch::draw() {
    GraphicalAssistant::drawObject(*(background_));

    associateTextures();
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            GraphicalAssistant::drawObject(*(tiles_[i][j]));
        }
    }
}

void GameSketch::update() {
    if (victoryCheck()) {
        std::cout << "You won! Your score: " << score_ << std::endl;
        SketchAssistant::removeSketch(this);
        return;
    }

    if (InputAssistant::isKeyPressed(keys::Escape)) {
        SketchAssistant::removeSketch(this);
        return;
    }

    if (InputAssistant::isKeyPressed(keys::R)) {
        SketchAssistant::addSketch(new GameSketch);
        SketchAssistant::removeSketch(this);
        return;
    }

    // Move tiles using keyboard arrows
    if (InputAssistant::isKeyPressed(keys::Right)) {
        moveRight();
        showScore();
    }

    if (InputAssistant::isKeyPressed(keys::Left)) {
        moveLeft();
        showScore();
    }

    if (InputAssistant::isKeyPressed(keys::Up)) {
        moveUp();
        showScore();
    }

    if (InputAssistant::isKeyPressed(keys::Down)) {
        moveDown();
        showScore();
    }

    // Set tiles' positions
    float x = 0, y = 0;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) {
            x = 70 + TILE_SIZE * j;
            y = 300 + TILE_SIZE * i;
            tiles_[i][j]->setPosition(Vector2f{ x, y });
        }
}

void GameSketch::moveRight() {
    int fit_index = -1;
    bool spawn = false;
    bool swap = true;
    
    for (int i = 0; i < 4; ++i) {
        for (int j = 2; j >= 0; --j) {
            swap = true;

            if (tiles_values_[i][j] == 0)
                continue;

            fit_index = -1;
            // Find the fit index for this element
            for (int k = j; k < 3; ++k)
                if (tiles_values_[i][k + 1] == 0)
                    fit_index = k + 1;

            // std::cout << "Fit index: " << fit_index << std::endl;
            if (fit_index == -1) {
                swap = false;
                fit_index = j;
            } else
                spawn = true;

            if (fit_index != 3) {
                if (tiles_values_[i][j] == tiles_values_[i][fit_index + 1]) {
                    // Connect tiles
                    tiles_values_[i][fit_index + 1] *= 2;
                    tiles_values_[i][fit_index] = 0;
                    tiles_values_[i][j] = 0;
                    spawn = true;
                    score_ += tiles_values_[i][fit_index + 1];

                    continue;
                }
            }

            // Swap tilesëëäæ
            if (swap)
                std::swap(tiles_values_[i][j], tiles_values_[i][fit_index]);
        }
    }

    if (spawn)
        spawnTile();
}

void GameSketch::moveLeft() {
    int fit_index = -1;
    bool spawn = false;
    bool swap = true;

    for (int i = 0; i < 4; ++i) {
        for (int j = 1; j < 4; ++j) {
            swap = true;

            if (tiles_values_[i][j] == 0)
                continue;

            fit_index = -1;
            // Find the fit index for this element
            for (int k = j; k > 0; --k)
                if (tiles_values_[i][k - 1] == 0)
                    fit_index = k - 1;

            // std::cout << "Fit index: " << fit_index << std::endl;
            if (fit_index == -1) {
                swap = false;
                fit_index = j;
            }
            else
                spawn = true;

            if (fit_index != 0) {
                if (tiles_values_[i][j] == tiles_values_[i][fit_index - 1]) {
                    // Connect tiles
                    tiles_values_[i][fit_index - 1] *= 2;
                    tiles_values_[i][fit_index] = 0;
                    tiles_values_[i][j] = 0;
                    spawn = true;
                    score_ += tiles_values_[i][fit_index - 1];

                    continue;
                }
            }

            // Swap tiles
            if (swap)
                std::swap(tiles_values_[i][j], tiles_values_[i][fit_index]);
        }
    }

    if (spawn)
        spawnTile();
}

void GameSketch::moveUp() {
    int fit_index = -1;
    bool spawn = false;
    bool swap = true;

    for (int j = 0; j < 4; ++j) {
        for (int i = 1; i < 4; ++i) {
            swap = true;

            if (tiles_values_[i][j] == 0)
                continue;

            fit_index = -1;
            // Find the fit index for this element
            for (int k = i; k > 0; --k)
                if (tiles_values_[k - 1][j] == 0)
                    fit_index = k - 1;

            // std::cout << "Fit index: " << fit_index << std::endl;
            if (fit_index == -1) {
                swap = false;
                fit_index = i;
            }
            else
                spawn = true;

            if (fit_index != 0) {
                if (tiles_values_[i][j] == tiles_values_[fit_index - 1][j]) {
                    // Connect tiles
                    tiles_values_[fit_index - 1][j] *= 2;
                    tiles_values_[fit_index][j] = 0;
                    tiles_values_[i][j] = 0;
                    spawn = true;
                    score_ += tiles_values_[fit_index - 1][j];

                    continue;
                }
            }

            // Swap tiles
            if (swap)
                std::swap(tiles_values_[i][j], tiles_values_[fit_index][j]);
        }
    }

    if (spawn)
        spawnTile();
}

void GameSketch::moveDown() {
    int fit_index = -1;
    bool spawn = false;
    bool swap = true;

    for (int j = 0; j < 4; ++j) {
        for (int i = 3; i >= 0; --i) {
            swap = true;

            if (tiles_values_[i][j] == 0)
                continue;

            fit_index = -1;
            // Find the fit index for this element
            for (int k = i; k < 3; ++k)
                if (tiles_values_[k + 1][j] == 0)
                    fit_index = k + 1;

            // std::cout << "Fit index: " << fit_index << std::endl;
            if (fit_index == -1) {
                swap = false;
                fit_index = i;
            }
            else
                spawn = true;

            if (fit_index != 3) {
                if (tiles_values_[i][j] == tiles_values_[fit_index + 1][j]) {
                    // Connect tiles
                    tiles_values_[fit_index + 1][j] *= 2;
                    tiles_values_[fit_index][j] = 0;
                    tiles_values_[i][j] = 0;
                    spawn = true;
                    score_ += tiles_values_[fit_index + 1][j];

                    continue;
                }
            }

            // Swap tiles
            if (swap)
                std::swap(tiles_values_[i][j], tiles_values_[fit_index][j]);
        }
    }

    if (spawn)
        spawnTile();
}

void GameSketch::spawnTile() {
    updateFree();

    // Generate a random tile from the free vector
    srand(time(NULL));
    int index = rand() % free_tiles_.size();
    int i = free_tiles_.at(index) / 4;
    int j = free_tiles_.at(index) % 4;
    
    // New tile value
    int value = 2;
    if ((rand() % 100) >= 90)
        value = 4;

    // std::cout << "Spawn here: " << i << " " << j << std::endl;
    tiles_values_[i][j] = value;
}

void GameSketch::updateFree() {
    free_tiles_.clear();

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (tiles_values_[i][j] == 0)
                free_tiles_.push_back(i * 4 + j);
}

void GameSketch::associateTextures() {
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) {
            if (tiles_values_[i][j] != 0)
                tiles_[i][j]->setTexture(textures_[tiles_values_[i][j]]);
            else
                tiles_[i][j]->setTexture(textures_[1]);
        }
}