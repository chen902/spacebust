#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

#include "DisplayManager.h"
#include "ShaderProgram.h"
#include "GameObject.h"
#include "loader.h"
#include "RawModel.h"

void render(const GameObject& object, const ShaderProgram& shader, GLFWwindow* window);
void update();
void handleInput(GameObject& obj, GLFWwindow* window);


int main(void) {
	// handles window opening
	DisplayManager display;
	GLFWwindow* window = display.createDisplay();

	// initialize glew
	GLenum err = glewInit();

	ShaderProgram shader;

	shader.startShader();

	glm::mat4 projection = glm::mat4(1.0f);
	projection = glm::ortho(0.0f, 800.0f, 600.0f, 0.0f, -1.0f, 1.0f);
	shader.loadProjectionMatrix(projection);

	Loader loader;

	//const float g_vertex_buffer_data[] = {
	//	-0.1f, -0.3f, 1.0f, // LEFT
	//	0.1f, -0.3f, 1.0f, // RIGHT
	//	0.0f,  0.4f, 1.0f, // TOP
	//};

	const float g_vertex_buffer_data[] = {
		0.0f, 0.5f, // LEFT
		0.5f, 1.0f, // RIGHT
		1.0f,  0.0f // TOP
	};

	RawModel& m1 = loader.loadToVAO(g_vertex_buffer_data, sizeof(g_vertex_buffer_data));
	GameObject* go1 = new GameObject(m1, glm::vec2(500.0, 400.0), 100.0f);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		handleInput(*go1, window);
		update();
		render(*go1, shader, window);
	}

	
	display.destroyDisplay();
	loader.cleanUp();

	return 0;
}

void render(const GameObject& object, const ShaderProgram& shader, GLFWwindow* window) {
	glClear(GL_COLOR_BUFFER_BIT);

	shader.startShader();
	
	shader.loadModelMatrix(object.getModelMatrix());
	
	// bind VAO
	glBindVertexArray(object.getModel().getID());

	// draw currently bound VAO
	glDrawArrays(GL_TRIANGLES, 0, 3);
	
	// unbind VAO
	glBindVertexArray(0);
	
	glfwPollEvents();

	glfwSwapBuffers(window);

	shader.stopShader();
}

void update() {

}

void handleInput(GameObject& obj, GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_RIGHT)) {
		obj.increaseXPos(1.0);
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT)) {
		obj.increaseXPos(-1.0);
	}
	if (glfwGetKey(window, GLFW_KEY_UP)) {
		obj.increaseYPos(-1.0);
	}
	if (glfwGetKey(window, GLFW_KEY_DOWN)) {
		obj.increaseYPos(1.0);
	}

}