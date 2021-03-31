#pragma once

#include <vector>
#include <memory>

#include "Object.h"
#include "Collision.h"
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
	
	void march(const Ray& ray, Collision& collision);
	Vector findColor(const Ray& ray);

	public:

	Marcher(Scene& scene_, int width_, int height_);

	void render(const Camera& camera, std::vector<Vector>& colors);
};
