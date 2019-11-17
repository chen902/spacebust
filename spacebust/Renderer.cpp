#include "Renderer.h"


Renderer::Renderer(DisplayManager & display) : display(display)
{
	this->shader = new ShaderProgram();
}

Renderer::~Renderer()
{
	delete this->shader;
}

void Renderer::render(const GameObject & obj)
{
	glClear(GL_COLOR_BUFFER_BIT);

	shader->startShader();

	shader->loadModelMatrix(obj.getModelMatrix());

	// bind VAO
	glBindVertexArray(obj.getModel().getID());

	// draw currently bound VAO
	glDrawArrays(GL_TRIANGLES, 0, obj.getModel().getVerticeCount());

	// unbind VAO
	glBindVertexArray(0);

	shader->stopShader();
}

void Renderer::init()
{
	this->shader->startShader();
	
	glm::mat4 projection = glm::mat4(1.0f);
	projection = glm::ortho(0.0f, (float)this->display.getWidth(), (float)this->display.getHeight(), 0.0f, -1.0f, 1.0f);
	shader->loadProjectionMatrix(projection);

	this->shader->loadProjectionMatrix(projection);

	shader->stopShader();
	// stop shader?
}
