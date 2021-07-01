#include "GraphicalDriver.h"
#include "Sprite/Sprite.h"

using namespace se;

// Initialize static variable for the graphical assistant
GraphicalDriver* GraphicalAssistant::graphical_driver = nullptr;

GraphicalDriver::GraphicalDriver(sf::RenderWindow* window) : window_ (window) {
    to_draw_.resize(max_layers);
}

GraphicalDriver::~GraphicalDriver() {
    // Delete all loaded textures
    for (auto& texture : textures_) {
        delete texture;
    }
}

void GraphicalDriver::addObject(GraphicalObject* object) {
    if (object == nullptr)
        throw std::runtime_error("Unexpected nullptr as an object!");
    
    to_draw_.at(object->layer_).push_back(object);
}

void GraphicalDriver::drawObjects() {
    Sprite* sprite_tmp = NULL;
    for (auto&& layer : to_draw_) {
        for (auto&& object : layer) {
            if ((sprite_tmp = dynamic_cast<Sprite*>(object)) != NULL) {
                window_->draw(*(sprite_tmp->sprite_));
            } else {
                sf::RenderStates states{ object->size_object_->getTransform() };
                window_->draw(*(object->object_), states);
            }
        }
    }
}

void GraphicalDriver::clearObjects() {
    for (auto&& layer : to_draw_) {
        layer.clear();
    }
}

unsigned int GraphicalDriver::loadTexture(std::string path) {
    Texture* texture = new Texture;
    texture->loadFromFile(path);
    textures_.push_back(texture);
    
    return textures_.size() - 1;
}

Texture* GraphicalDriver::getTexture(unsigned int ID) {
    return textures_.at(ID);
}

Vector2u GraphicalAssistant::getResolution() {
    return Application::getResolution();
}

unsigned int GraphicalAssistant::loadTexture(std::string path) {
    return graphical_driver->loadTexture(path);
}

void GraphicalAssistant::drawObject(GraphicalObject& object) {
    graphical_driver->addObject(&object);
}

Texture* GraphicalAssistant::getTexture(unsigned int ID) {
    return graphical_driver->getTexture(ID);
}