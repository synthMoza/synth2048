#include "GraphicalObject.h"

using namespace se;

GraphicalObject::GraphicalObject() : 
	object_ (nullptr), size_object_ (nullptr), layer_ (0) {}

GraphicalObject::~GraphicalObject() {}

void GraphicalObject::setPosition(Vector2f pos) {
	size_object_->setPosition({pos.x_, pos.y_});
}

void GraphicalObject::setOrigin(Vector2f origin) {
	size_object_->setOrigin({origin.x_, origin.y_});
}

void GraphicalObject::setScale(Vector2f scale) {
	size_object_->setScale({scale.x_, scale.y_});
}

void GraphicalObject::move(Vector2f offset) {
	size_object_->move({ offset.x_, offset.y_ });
}

Vector2f GraphicalObject::getPosition() {
	sf::Vector2f pos = size_object_->getPosition();
	return Vector2f{pos.x, pos.y};
}

Vector2f GraphicalObject::getOrigin() {
	sf::Vector2f origin = size_object_->getOrigin();
	return Vector2f{origin.x, origin.y};
}

Vector2f GraphicalObject::getScale() {
	sf::Vector2f scale = size_object_->getScale();
	return Vector2f{scale.x, scale.y};
}