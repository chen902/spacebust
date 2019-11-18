#include "GameWorld.h"


GameWorld::GameWorld(DisplayManager& dm) : display(dm)
{
	std::cout << "Gameworld ctor!" << std::endl;

	this->renderer = new Renderer(this->display);
	this->renderer->init();
	this->loader = new Loader();
}

GameWorld::~GameWorld()
{
	std::cout << "GameWorld dtor!" << std::endl;

	delete this->renderer;
	delete this->loader;
	delete this->spaceship;
}

void GameWorld::init()
{
	std::cout << "GameWorld init!" << std::endl;

	const float g_vertex_buffer_data[] = {
	0.8f, 1.0f, // RIGHT
	0.2f, 1.0f, // LEFT
	0.5f,  0.0f // TOP
	};

	RawModel& m1 = this->loader->loadToVAO(g_vertex_buffer_data, sizeof(g_vertex_buffer_data));
	this->spaceship = new SpaceShip(m1, glm::vec2(400.0f, 300.0f));
	this->objects.push_back(this->spaceship);
}

void GameWorld::start()
{
	this->gameLoop();
	this->display.destroyDisplay();
	this->loader->cleanUp();
}

void GameWorld::renderAll()
{
	for (GameObject* obj : this->objects) {
		this->renderer->render(*obj);
	}
	//this->renderer->render(*(this->spaceship));
	
	glfwSwapBuffers(display.getGLFWWindow());

}

void GameWorld::updateAll()
{
	this->spaceship->update(0.01);
}

void GameWorld::handleUserInput()
{
	glfwPollEvents();

	GLFWwindow* window = this->display.getGLFWWindow();

	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT)) {
		this->spaceship->increaseSpeed(0.1f);
	}
	else {
		this->spaceship->increaseSpeed(-0.1f);
	}

	if (glfwGetKey(window, GLFW_KEY_RIGHT)) {
		this->spaceship->increaseAngle(0.01);
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT)) {
		this->spaceship->increaseAngle(-0.01);
	}
	//if (glfwGetKey(window, GLFW_KEY_UP)) {
	//	this->spaceship->increaseYPos(-1.0);
	//}
	//if (glfwGetKey(window, GLFW_KEY_DOWN)) {
	//	this->spaceship->increaseYPos(1.0);
	//}

}

void GameWorld::gameLoop()
{
	std::cout << "Starting gameloop" << std::endl;
	while (!this->display.shouldClose()) {
		this->handleUserInput();
		this->updateAll();
		this->renderAll();
	}
}
