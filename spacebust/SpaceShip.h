#pragma once
#include "GameObject.h"
class SpaceShip :
	public GameObject
{
public:
	SpaceShip(const RawModel& model, glm::vec2 position);
	~SpaceShip();
	virtual void update(float dt);
	virtual void increaseSpeed(float val);
	private:
		const float TOP_SPEED = 30.0;
};

