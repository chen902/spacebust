#pragma once
// whenever an error like gl.h included before glew.h arises, look for places where glfw3 is included alone, and include glew above it.
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <iostream>

class DisplayManager
{
public:
	DisplayManager();
	~DisplayManager();
	void createDisplay(unsigned int width, unsigned int height);
	void destroyDisplay();
	GLFWwindow* getGLFWWindow();
	bool shouldClose();
	unsigned int getWidth() { return this->displayWidth; };
	unsigned int getHeight() { return this->displayHeight; };

	

private:
	GLFWwindow* window;
	unsigned int displayWidth;
	unsigned int displayHeight;
};