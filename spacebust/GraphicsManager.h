#pragma once

#include "loader.h"
#include "ShaderProgram.h"
#include "GameObject.h"
#include "DisplayManager.h"

class GraphicsManager
{
public:
	GraphicsManager(DisplayManager* display);
	~GraphicsManager();

private:
	DisplayManager* display;
	ShaderProgram* shader;
	Loader* loader;
};

