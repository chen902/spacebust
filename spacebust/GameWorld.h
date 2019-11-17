#pragma once

#include <vector>
#include <iostream>

#include "GameObject.h"
#include "loader.h"
#include "Renderer.h"
#include "DisplayManager.h"

class GameWorld
{
public:
	GameWorld(DisplayManager& dm);
	~GameWorld();
	void init();
	void start();

private:
	std::vector<GameObject> objects;
	GameObject* spaceship;

	void renderAll();
	void updateAll();
	void handleUserInput();
	void gameLoop();

	Loader* loader;
	Renderer* renderer;	
	DisplayManager& display;
	

};

