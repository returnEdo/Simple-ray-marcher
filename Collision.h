#pragma once

#include <memory>

#include "Vector.h"
#include "Object.h"
#include "Queue.h"
#include "RayMarcherConstants.h"


class Collision{

	public:

	Vector position;

	std::shared_ptr<Object> collidedObject;

	Queue<float> queue;

	bool hasCollided 	= false;
};
