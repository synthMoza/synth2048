#pragma once

#include "../GraphicalLibrary.h"
#include <string>

namespace se {
	// Class that represent textures
	class Texture final {
		sf::Texture* texture_;
	public:
		Texture();

		// Load the texture from the file on the computer
		void loadFromFile(const std::string& path);

		~Texture();

		friend class Sprite;
	};
}