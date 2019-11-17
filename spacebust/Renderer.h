#pragma once
#include "DisplayManager.h"
#include "ShaderProgram.h"
#include "GameObject.h"

class Renderer
{
public:
	Renderer(DisplayManager& display);
	~Renderer();
	void render(const GameObject& obj);
	void init();


private:
	DisplayManager& display;
	ShaderProgram* shader;

};

