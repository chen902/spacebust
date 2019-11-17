#pragma once

#include <vector>

#include "GameObject.h"
#include "GraphicsManager.h"

class GameWorld
{
public:
	GameWorld(GraphicsManager& gm);
	~GameWorld();
	void init();
	void start();

private:
	std::vector<GameObject*> objects;
	void renderAll();
	void updateAll();
	void handleUserInput();

};

