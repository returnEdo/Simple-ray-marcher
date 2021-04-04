#include "Marcher.h"

#include <cmath>
#include <limits>
#include <algorithm>
#include <iostream>

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

	Vector origin;
	Vector direction;

	/* rays are casted from top left */
	for (int j = 0; j < height; j++){

		for (int i = 0; i < width; i++){

			Vector color;
			
			/* antialiasing loop */
			for (int k = 0; k < antiAliasingSamples; k++){
				
				float dx = randf(-step / 2.0f, step / 2.0f);
				float dy = randf(-step / 2.0f, step / 2.0f);

				/* ray direction */
				if (projection == Projection::PERSPECTIVE){

					direction =  Vector(-deltax / 2.0f + step * i + dx,
							    deltay / 2.0f - step * j + dy,
							    -camera.getPlaneDistance());
					direction.normalize();

					origin = camera.getPosition();
				}
				else {
					/* ORTHOGRAPHIC projection */

					direction = Vector(.0f, .0f, -1.0f);

					origin = Vector(-deltax / 2.0f + step * i + dx,
							deltay / 2.0f - step * j + dy,
							.0f);
					origin = camera.getPosition() + camera.getCamToWorld() * origin;
				}

				direction = camera.getCamToWorld() * direction;

				Ray ray(origin, direction);

				color += clamp(255.0f * findColor(ray), Vector(.0f), Vector(255.0f));

			}

			color /= static_cast<float>(antiAliasingSamples);

			colors.push_back(color);
		}
	}
}



void Marcher::march(const Ray& ray, Collision& collision){
	/* checks collisions for the ray */
	
	Vector position = ray.getOrigin();
	
	for (int i = 0; i < Constants::ITER_MAX; i++){
		
		float t = std::numeric_limits<float>::max();

		std::shared_ptr<Object> closest;
	
		/* find the closest object and shorter distance */
		for (auto pobject: scene.objects){

			float tt = pobject -> sdf(position);
			
			if (tt < t){
			
				closest = pobject;
				t = tt;
			}
		}
		
		/* record the distance for ambient occlusion / volumetric effects */
		collision.queue.enque(t);

		if (t >= Constants::SUPREMUM_TOLL){
			
			collision.hasCollided = false;

			return;
		}
		else if (t <= Constants::INFIMUM_TOLL){
			
			collision.position 		= position;
			collision.collidedObject 	= closest;
			collision.hasCollided		= true;

			return;
		}
		
		/* marching step */
		position += t * ray.getDirection();
	}

	collision.hasCollided = false;
	
	return;
}


Vector Marcher::findColor(const Ray& ray){
	/* marches a ray and find the corresponding color */
	
	Collision collision;
	
	march(ray, collision);

	if (collision.hasCollided){
		/* basic shading and shadowing */

		float intensity = .0f;

		Vector normal;
		collision.collidedObject -> getNormalAt(collision.position, normal);

		for (auto plight: scene.lights){

			Vector lightVector = plight -> getPosition() - collision.position;	
			lightVector.normalize();
			
			/* shadowing */
			Ray feeler(collision.position + normal * Constants::OFFSET_DISTANCE, lightVector);

			Collision feelerCollision;
			march(feeler, feelerCollision);
	
			if (not feelerCollision.hasCollided){
				
				intensity += std::max(.0f, lightVector * normal);
			}
		}

		return (collision.collidedObject -> getColor()) *
			(Constants::AMBIENT_INTENSITY + (1.0f - Constants::AMBIENT_INTENSITY) * intensity);

	}
	else{

		return Constants::BACKGROUND_COLOR;
	}

}





