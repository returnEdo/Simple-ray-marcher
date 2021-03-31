#include "Marcher.h"

#include <cmath>
#include <limits>
#include <iostream>

#include "RayMarcherConstants.h"
#include "MathMisc.h"

Marcher::Marcher(Scene& scene_, int width_, int height_):
		scene(scene_),
		width(width_),
		height(height_)	{}



void Marcher::render(const Camera& camera, std::vector<Vector>& colors){
	
	/* some view constants */
	float alpha = static_cast<float>(width - 1) / static_cast<float>(height - 1);

	float deltax = 2.0f * camera.getPlaneDistance() * tan(camera.getFOV() / 2.0f);
	float deltay = deltax / alpha;

	float step = deltax / static_cast<float>(width - 1);

	/* rays are casted from top left */
	for (int j = 0; j < height; j++){

		for (int i = 0; i < width; i++){

			/* ray direction */
			Vector d(-deltax / 2.0f + step * i,
				 deltay / 2.0f - step * j,
				 -camera.getPlaneDistance());

			d.normalize();
			d = camera.getCamToWorld() * d;

			Ray ray(camera.getPosition(), d);

			colors.push_back(clamp(255.0f * march(ray), Vector(.0f), Vector(255.0f)));
		}
	}
}




Vector Marcher::march(const Ray& ray){
	/* marches a ray and find the corresponding color */
	/* TODO: accumulation for amb occlu */

	Vector position = ray.getOrigin();		// current position
	
	std::shared_ptr<Object> closest;

	for (int i = 0; i < Constants::ITER_MAX; i++){	

		/* find the closest Object */
		float t = std::numeric_limits<float>::max();
		for (auto pobject: scene.objects){

			if (pobject -> sdf(position) < t){
				
				closest = pobject;
				t = pobject -> sdf(position);
			}

		}

		/* the ray is getting too far */
		if (t > Constants::SUPREMUM_TOLL)	{ return Constants::BACKGROUND_COLOR; }

		/* the ray is close enough to a surface */
		else if (t < Constants::INFIMUM_TOLL)	{ return Vector(.2f, .7f, .2f); }
		/* march along the ray */

		position += t * ray.getDirection();

	}
	/* may happen when the ray is parallel to a surface */

	return Constants::BACKGROUND_COLOR;

}

//
//Vector Marcher::findColor(const Vector& position, const Vector& direction, std::shared_ptr<Object>& pobject){
//
//
//	Vector normal;
//	pobject -> getNormalAt(position, normal);
//
//	Vector color = pobject -> getColor();
//
//	float 
//
//}







