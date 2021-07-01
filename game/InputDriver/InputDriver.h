#pragma once

#include <vector>

#include "../GraphicalLibrary.h"
#include "../Utilities/Vector2.h"

namespace se {
	// The list of all keys on the keyboard 
	enum class keys {
		Unknown = -1, A = 0, B, C,
		D, E, F, G,
		H, I, J, K,
		L, M, N, O,
		P, Q, R, S,
		T, U, V, W,
		X, Y, Z, Num0,
		Num1, Num2, Num3, Num4,
		Num5, Num6, Num7, Num8,
		Num9, Escape, LControl, LShift,
		LAlt, LSystem, RControl, RShift,
		RAlt, RSystem, Menu, LBracket,
		RBracket, Semicolon, Comma, Period,
		Quote, Slash, Backslash, Tilde,
		Equal, Hyphen, Space, Enter,
		Backspace, Tab, PageUp, PageDown,
		End, Home, Insert, Delete,
		Add, Subtract, Multiply, Divide,
		Left, Right, Up, Down,
		Numpad0, Numpad1, Numpad2, Numpad3,
		Numpad4, Numpad5, Numpad6, Numpad7,
		Numpad8, Numpad9, F1, F2,
		F3, F4, F5, F6,
		F7, F8, F9, F10,
		F11, F12, F13, F14,
		F15, Pause, KeyCount
	};

	// Structure that describes the state of the specific key
	struct keyInfo {
		keys code; // the code of the key
		bool released; // true if the key was released in this frame, otherwise false
		bool pressed; // true if the key is pressed in this frame, otherwise false
		bool held; // true if the key is held, false if not

		// Default constroctor for keyInfo
		keyInfo() : code(keys::Unknown), released(false), pressed(false), held(false) {}
	};

	// List of all mouse keys
	enum class mkeys {Unknown = -1, LMouse = 0, RMouse, Middle, MKeyCount};

	struct mkeyInfo {
		mkeys code; // the code of the mouse key
		bool held; // true if the mouse key is held
		bool released; // true if the mouse key is released in this frame
		bool pressed; // true if the mouse key is pressed in this frame

		mkeyInfo() : code(mkeys::Unknown), released(false), pressed(false), held(false) {}
	};

	const int keys_number = static_cast<unsigned int>(keys::KeyCount);
	const int mkeys_number = static_cast<unsigned int>(mkeys::MKeyCount);

	// The class to control keyboard and mouse
	class InputDriver {
		// Information about each key in the vector
		std::vector<keyInfo> keys_info;
		// Keys to be unpressed in the next frame
		std::vector<keys> keys_unpress;
		// Keys to be unreleased in the next frame
		std::vector<keys> keys_unrelease;

		// Information about each mouse key in the vector
		std::vector<mkeyInfo> mkeys_info;
		// MKeys to be unpressed in the next frame
		std::vector<mkeys> mkeys_unpress;
		// MKeys to be unreleased in the next frame
		std::vector<mkeys> mkeys_unrelease;
	public:
		// Default constructor for initializing all keys properly
		InputDriver();
		// Handle the given event to extract information about keys
		void handleEvent(sf::Event& event);
		// Update release/press state of ceratin keys
		void updateKeys();

		// Returns true if the key is held
		bool isKeyHeld(keys key);
		// Returns true if the key is pressed
		bool isKeyPressed(keys key);
		// Returns true if the key is released
		bool isKeyReleased(keys key);

		// Return the current mouse position
		Vector2i getMousePosition();

		// Returns true if the mkey is held
		bool isMKeyHeld(mkeys mkey);
		// Returns true if the mkey is pressed
		bool isMKeyPressed(mkeys mkey);
		// Returns true if the mkey is released
		bool isMKeyReleased(mkeys mkey);
	};

	// The class for user interface to keyboard and mouse
	class InputAssistant {
		static InputDriver* input_driver;
	public:
		// Returns true if the key is held
		static bool isKeyHeld(keys key);
		// Returns true if the key is pressed
		static bool isKeyPressed(keys key);
		// Returns true if the key is released
		static bool isKeyReleased(keys key);
		// Return the current mouse position
		static Vector2i getMousePosition();

		// Returns true if the mkey is held
		static bool isMKeyHeld(mkeys mkey);
		// Returns true if the mkey is pressed
		static bool isMKeyPressed(mkeys mkey);
		// Returns true if the mkey is released
		static bool isMKeyReleased(mkeys mkey);

		friend class Application;
	};
}