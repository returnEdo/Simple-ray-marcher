
#include <vector>
#include <memory>
#include <string>

#include "Vector.h"
#include "Geometry.h"
#include "Scene.h"
#include "Light.h"
#include "Camera.h"
#include "Marcher.h"
#include "JPGTools.h"


int main(){

	std::string addr = "renderings/march.jpg";

	int width	= 1000; 
	int height	= width;

	std::vector<std::shared_ptr<Object>> pobjects;
	pobjects.push_back(std::shared_ptr<Sphere>(new Sphere(Vector(), 1.0f)));

	std::vector<Light> lights;
	lights.push_back({Vector()});
	
	Scene scene;
	scene.objects = pobjects;
	scene.lights = lights;

	Camera camera(Vector(.0f, .0f, 3.0f), Vector());

	std::vector<Vector> colors;
	Marcher marcher(scene, width, height);

	marcher.render(camera, colors);

	saveJpg(addr, width, height, colors);
}	
