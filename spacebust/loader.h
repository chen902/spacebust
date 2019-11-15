#pragma once
#include <vector>
#include "GL/glew.h"

#include "RawModel.h"

class Loader
{
public:
	Loader();
	~Loader();
	RawModel& loadToVAO(const float* index_buffer, size_t indexBufferSize);
	void cleanUp();

private:
	std::vector<unsigned int> vaos;
	std::vector<unsigned int> vbos;

	unsigned int createVAO();
	void storeDataInArrayBuffer(const float* buffer, size_t size);
	void unbindVAO();
};

