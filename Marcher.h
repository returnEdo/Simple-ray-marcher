#pragma once

#include <vector>
#include <memory>

#include "Object.h"
#include "Light.h"
#include "Scene.h"
#include "Camera.h"
#include "Vector.h"
#include "Ray.h"



class Marcher{

	private:

	int width;
	int height;

	Scene scene;
	
	Vector march(const Ray& ray);
	//Vector findColor(const Vector& position, const Vector& direction, std::shared_ptr<Object>& pobject);

	public:

	Marcher(Scene& scene_, int width_, int height_);

	void render(const Camera& camera, std::vector<Vector>& colors);
};
