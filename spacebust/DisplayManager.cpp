#include "DisplayManager.h"

DisplayManager::DisplayManager()
{
}


DisplayManager::~DisplayManager()
{
	
}

void DisplayManager::createDisplay(unsigned int width, unsigned int height)
{
	this->displayWidth = width;
	this->displayHeight = height;

	/* Initialize the library */
	if (!glfwInit())
		throw std::exception();

	/* Create a windowed mode window and its OpenGL context */
	this->window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!this->window)
	{
		glfwTerminate();
		throw std::exception("GLFW was unable to create a window!");
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glViewport(0, 0, width, height);

	//glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

void DisplayManager::destroyDisplay()
{
	glfwTerminate();
}

GLFWwindow * DisplayManager::getGLFWWindow()
{
	return this->window;
}

bool DisplayManager::shouldClose()
{
	return glfwWindowShouldClose(this->window);
}
