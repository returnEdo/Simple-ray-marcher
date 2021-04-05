
#include <vector>
#include <memory>
#include <string>
#include <cmath>

#include "Vector.h"
#include "Vector2.h"
#include "Matrix.h"
#include "Geometry.h"
#include "Scene.h"
#include "Light.h"
#include "Camera.h"
#include "Marcher.h"
#include "JPGTools.h"


int main(int n, char ** val){

	int width	= 600; 
	if (n > 1){

		width = atoi(val[1]);
	}
	int height	= width;

	std::string addr = "renderings/march.jpg";
	std::vector<std::shared_ptr<Object>> pobjects;
	
	pobjects.push_back(std::shared_ptr<Object>(new Box(Vector(10.0f, .1f, 10.0f), Vector(.0f, -0.1f, .0f), Matrix(Vector(1.0f, .0f, .0f), .0f))));
	pobjects.push_back(std::shared_ptr<Object>(new Box(Vector(1.0f), Vector(.0f, .5f, .0f), Matrix(Vector(1.0f, .0f, .0f), .0f))));

//	pobjects[0] -> setColor(Vector(.3f, .7f, .3f));

	std::vector<std::shared_ptr<Light>> lights;
	lights.push_back(std::shared_ptr<Light>(new Light(Vector(10.0f, 10.0f, -10.0f))));
	
	Scene scene;
	scene.objects = pobjects;
	scene.lights = lights;

	Camera camera(Vector(2.1f), Vector());
//	camera.setFOV(M_PI / 1.4f);

	std::vector<Vector> colors;
	Marcher marcher(scene, width, height);

	marcher.setAntiAliasingSamples(8);
	marcher.setProjection(Projection::ORTHOGRAPHIC);

	marcher.render(camera, colors);

	saveJpg(addr, width, height, colors);
}	

