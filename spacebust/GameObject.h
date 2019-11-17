#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "RawModel.h"
#include <iostream>

class GameObject
{
public:
	GameObject(RawModel& model, const glm::vec2 pos, const float scale) : model(model), position(pos), scale(scale) {};
	~GameObject() {};
	float getPosX() const { return this->position.x; };
	float getPosY() const { return this->position.y; };
	float getScale() const { return this->scale; };

	void increaseXPos(float val) {
		std::cout << "x:" << this->position.x << std::endl;
		std::cout << "val:" << val << std::endl;
		

		this->position.x += val; 
		std::cout << "x:" << this->position.x << std::endl;
	};
	void increaseYPos(float val) { this->position.y += val; };

	RawModel& getModel() const { return this->model; };

	glm::mat4 getModelMatrix() const {

		// identity matrix
		glm::mat4 model = glm::mat4(1.0f);

		// translate to object position
		model = glm::translate(model, glm::vec3(this->position.x,this->position.y, 0.0f));

		// scale to object size
		model = glm::scale(model, glm::vec3(glm::vec2(this->scale,this->scale), 1.0f));

		return model;
	}

private:
	RawModel& model;
	glm::vec2 position;
	float scale;
};

