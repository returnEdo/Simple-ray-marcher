
#include <vector>
#include <memory>
#include <string>

#include "Vector.h"
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

	Box box(Vector(1.0f, 1.0f, 1.0f), Vector(), Matrix(Vector(1.0f, .0f, .0f), .0f)); 
	InfiniteCylinder cyl(Vector(), Matrix(Vector(1.0f, .0f, .0f), .0f), 0.6f);

	Node root, left, right;

	root.setOperation(Operation::DIFFERENCE);

	root.setLeftChild(left);
	left.setObject(box);

	root.setRightChild(right);
	right.setObject(cyl);


	CSG csg(root);


	std::vector<std::shared_ptr<Object>> pobjects;
//	Box box(Vector(1.0f, 1.0f, 1.0f), Vector(1.0f, .0f, .0f), Matrix(Vector(1.0f, .0f, .0f), 0.2f));
//	pobjects.push_back(std::shared_ptr<Smoother>(new Smoother(&box, 0.1f)));
	
	pobjects.push_back(std::shared_ptr<CSG>(new CSG(root)));

	pobjects[0] -> setColor(Vector(.3f, .7f, .3f));

	std::vector<std::shared_ptr<Light>> lights;
	lights.push_back(std::shared_ptr<Light>(new Light(Vector(1.5f, 4.0f, .0f))));
	
	Scene scene;
	scene.objects = pobjects;
	scene.lights = lights;

	Camera camera(Vector(3.0f, .5f, .0f), Vector());

	std::vector<Vector> colors;
	Marcher marcher(scene, width, height);

	marcher.render(camera, colors);

	saveJpg(addr, width, height, colors);
}	

