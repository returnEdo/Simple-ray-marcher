
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

	int width	= 400; 
	int height	= width;

	std::vector<std::shared_ptr<Object>> pobjects;
	pobjects.push_back(std::shared_ptr<Sphere>(new Sphere(Vector(), 1.0f)));
	pobjects.push_back(std::shared_ptr<Sphere>(new Sphere(Vector(1.0f, -2.0f, -2.0f), 1.0f)));

	pobjects[0] -> setColor(Vector(.2f, .7f, .2f));

	std::vector<std::shared_ptr<Light>> lights;
	lights.push_back(std::shared_ptr<Light>(new Light(Vector(10.0f))));
	
	Scene scene;
	scene.objects = pobjects;
	scene.lights = lights;

	Camera camera(Vector(.0f, .0f, 3.0f), Vector());

	std::vector<Vector> colors;
	Marcher marcher(scene, width, height);

	marcher.render(camera, colors);

	saveJpg(addr, width, height, colors);
}	
