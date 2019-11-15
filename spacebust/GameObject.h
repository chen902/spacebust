#pragma once
#include <glm/glm.hpp>
#include "RawModel.h"

class GameObject
{
public:
	GameObject(RawModel& model, const glm::vec2 pos, const float scale) : model(model), position(pos), scale(scale) {};
	~GameObject() {};
	float getPosX() const { return this->position.x; };
	float getPosY() const { return this->position.y; };
	float getScale() const { return this->scale; };

	RawModel& getModel() const { return this->model; };

	static glm::mat3 getModelMatrix() {

	}

private:
	RawModel& model;
	glm::vec2 position;
	float scale;
};

