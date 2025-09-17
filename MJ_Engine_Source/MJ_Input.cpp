#include "MJ_Input.h"
namespace MJ {
	std::vector<Input::Key> Input::Keys = {};

	char ASCII[(int)eKeyCode::End] = {
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
	};

	void Input::Initailize() {
		createKeys();
	}

	void Input::Update() {
		updateKeys();
	}

	void Input::createKeys() {
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++) {
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			Keys.push_back(key);
		}
	}

	void Input::updateKeys() {
		for (size_t i = 0; i < Keys.size(); i++) {
			updateKey(Keys[i]);
		}
	}
	void Input::updateKey(Input::Key& key){
		//키가 눌린 경우
		if (isKeyDown(key.keyCode)) {
			updateKeyDown(key);
		}
		//키가 안눌린 경우
		else {
			updateKeyUp(key);
		}
	}
	bool Input::isKeyDown(eKeyCode code){
		return GetAsyncKeyState(ASCII[(int)code]) & 0x8000;
	}
	void Input::updateKeyDown(Input::Key& key){
		if (key.bPressed == true) {
			key.state = eKeyState::Pressed;
		}
		else {
			key.state = eKeyState::Down;
		}

		key.bPressed = true;
	}
	void Input::updateKeyUp(Input::Key& key){
		if (key.bPressed == true) {
			key.state = eKeyState::Up;
		}
		else {
			key.state = eKeyState::None;
		}

		key.bPressed = false;
	}
}