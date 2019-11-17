#include "GraphicsManager.h"

GraphicsManager::GraphicsManager(DisplayManager* display)
{
	this->display = display;
	this->shader = new ShaderProgram();
	this->loader = new Loader();
}

GraphicsManager::~GraphicsManager()
{
	delete this->shader;
	delete this->loader;
}
