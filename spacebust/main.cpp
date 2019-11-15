#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "DisplayManager.h"
#include "ShaderProgram.h"
#include "GameObject.h"
#include "loader.h"
#include "RawModel.h"

void render(const GameObject& object, const ShaderProgram& shader, GLFWwindow* window);
void update();
void handleInput();


int main(void) {
	// handles window opening
	DisplayManager display;
	GLFWwindow* window = display.createDisplay();

	// initialize glew
	GLenum err = glewInit();

	ShaderProgram shader;

	shader.startShader();

	Loader loader;

	const float g_vertex_buffer_data[] = {
		-0.1f, -0.3f, 0.0f, // LEFT
		0.1f, -0.3f, 0.0f, // RIGHT
		0.0f,  0.4f, 0.0f, // TOP
	};

	RawModel& m1 = loader.loadToVAO(g_vertex_buffer_data, sizeof(g_vertex_buffer_data));
	GameObject* go1 = new GameObject(m1, glm::vec2(0.0), 0.5);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		handleInput();
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

	glBindVertexArray(object.getModel().getID());

	glEnableVertexAttribArray(0);
	
	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);
	
	glDrawArrays(GL_TRIANGLES, 0, object.getModel().getVerticeCount() * sizeof(float) * 3);
	
	glDisableVertexAttribArray(0);

	
	glfwPollEvents();

	glfwSwapBuffers(window);

	shader.stopShader();
}

void update() {

}

void handleInput() {

}