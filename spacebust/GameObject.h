#pragma once
class GameObject
{
public:
	GameObject(unsigned int id, size_t verticeCount) : vaoID(id), verticeCount(verticeCount) {};
	~GameObject() {};
	unsigned int getID() const { return this->vaoID; };
	unsigned int getVerticeCount() const { return this->verticeCount; };

private:
	unsigned int vaoID;
	size_t verticeCount;
};

