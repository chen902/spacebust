#pragma once
#include "DisplayManager.h"

class InputManager
{
public:
	InputManager(DisplayManager& display);
	~InputManager();

private:
	DisplayManager& display;
};

