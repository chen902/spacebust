#pragma once
class RawModel
{
public:
	RawModel(unsigned int id, size_t verticeCount);
	~RawModel();
	unsigned int getID() const { return this->vaoID; };
	unsigned int getVerticeCount() const { return this->verticesCount; };

private:
	unsigned int vaoID;
	size_t verticesCount;
};

