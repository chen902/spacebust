#include "SpaceShip.h"

SpaceShip::SpaceShip(const RawModel& model, glm::vec2 position) : 
	GameObject(model, position, 30.0f, 0.0f, 0.0f)
{
	
}


SpaceShip::~SpaceShip()
{
}

void SpaceShip::update(float dt)
{
	this->position.x += glm::cos(this->angle - ANGLE_OFFSET) * this->speed * dt;
	this->position.y += glm::sin(this->angle - ANGLE_OFFSET) * this->speed * dt;
}

void SpaceShip::increaseSpeed(float val)
{
	if (this->speed + val >= TOP_SPEED) {
		this->speed = TOP_SPEED;
	}
	else if(this->speed + val <= 0) {
		this->speed = 0;
	}
	else {
		this->speed += val;
	}
}
