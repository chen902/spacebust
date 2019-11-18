#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "RawModel.h"
#include <iostream>

class GameObject
{
public:
	GameObject(RawModel& model, const glm::vec2 pos, float scale, float angle, float speed) : 
		model(model), position(pos), scale(scale), angle(angle), speed(speed) {};

	~GameObject() {};

	float getPosX() const { return this->position.x; };
	float getPosY() const { return this->position.y; };
	float getScale() const { return this->scale; };

	void increaseXPos(float val) { this->position.x += val; };
	void increaseYPos(float val) { this->position.y += val; };
	void increaseAngle(float val) { this->angle += val; };

	void update(float dt) {
		this->position.x += glm::cos(this->angle-ANGLE_OFFSET) * this->speed * dt;
		this->position.y += glm::sin(this->angle-ANGLE_OFFSET) * this->speed * dt;
	};

	RawModel& getModel() const { return this->model; };

	glm::mat4 getModelMatrix() const {

		// identity matrix
		glm::mat4 model = glm::mat4(1.0f);

		// translate to object position
		model = glm::translate(model, glm::vec3(this->position.x,this->position.y, 0.0f));

		
		model = glm::translate(model, glm::vec3(0.5f * this->scale, 0.5f * this->scale, 0.0f)); // Move origin of rotation to center of quad
		model = glm::rotate(model, this->angle, glm::vec3(0.0f, 0.0f, 1.0f)); // Then rotate
		model = glm::translate(model, glm::vec3(-0.5f * this->scale, -0.5f * this->scale, 0.0f)); // Move origin back


		// scale to object size
		model = glm::scale(model, glm::vec3(glm::vec2(this->scale,this->scale), 1.0f));

		return model;
	}

private:
	RawModel& model;
	glm::vec2 position;
	float scale;
	float angle;
	float speed;
	const float ANGLE_OFFSET = glm::pi<float>() / 2.0f;
};

