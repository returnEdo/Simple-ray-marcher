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
#include "RayMarcherConstants.h"


enum class Projection{

	PERSPECTIVE,
	ORTHOGRAPHIC
};


class Marcher{

	private:

	Projection projection	= Projection::PERSPECTIVE;

	int antiAliasingSamples = Constants::ANTI_ALIASING_SAMPLES;

	int width;
	int height;

	Scene scene;
	
	void march(const Ray& ray, Collision& collision);
	Vector findColor(const Ray& ray);

	float findAmbientOcclusion(const Vector& collisionPosition,
				   const Vector& collisionNormal) const;

	public:

	Marcher(Scene& scene_, int width_, int height_);

	/* setters */
	inline void setAntiAliasingSamples(int samp)			{ antiAliasingSamples = samp; }
	inline void setProjection(const Projection& probjection_)	{ projection = probjection_; }

	void render(const Camera& camera, std::vector<Vector>& colors);

	float sdf(const Vector& x) const;
};
