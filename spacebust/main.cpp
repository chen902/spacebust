#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "DisplayManager.h"
#include "ShaderProgram.h"
#include "GameObject.h"
#include "loader.h"
#include "RawModel.h"
#include "GameWorld.h"

void render(const GameObject& object, const ShaderProgram& shader, GLFWwindow* window);
void update();
void handleInput(GameObject& obj, GLFWwindow* window);


int main(void) {
	// handles window opening
	DisplayManager display;
	display.createDisplay(1024,768);
	
	// initialize glew
	GLenum err = glewInit();

	GameWorld world(display);
	world.init();
	world.start();

	return 0;
}