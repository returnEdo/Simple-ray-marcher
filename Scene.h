#pragma once


#include "Object.h"
#include "Light.h"

#include <vector>
#include <memory>

class Scene{

	public:

	std::vector<std::shared_ptr<Object>>	objects;
	std::vector<std::shared_ptr<Light>>	lights;
	
};
	

