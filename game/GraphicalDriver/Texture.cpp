#include "Texture.h"

using namespace se;

Texture::Texture() : texture_ (new sf::Texture) {}

Texture::~Texture() {
	delete texture_;
}

void Texture::loadFromFile(const std::string& path) {
	texture_->loadFromFile(path);
}