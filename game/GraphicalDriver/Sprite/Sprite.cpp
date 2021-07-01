#include "Sprite.h"

using namespace se;

Sprite::Sprite() :  sprite_(new sf::Sprite) {
	object_ = sprite_; // initialize sf::Drawable pointer
	size_object_ = sprite_; // initialize sf::Transformable pointer
}

void Sprite::setTexture(unsigned int ID) {
	sprite_->setTexture(*(GraphicalAssistant::getTexture(ID)->texture_));
}

Sprite::~Sprite() {
	delete sprite_;
}