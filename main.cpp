
#include <vector>
#include <memory>
#include <string>
#include <cmath>

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

	float cylRadius = .6f;
	float sphereRadius = 1.3f;
	float boxSide = 1.0f;

	Box box(Vector(boxSide), Vector(), Matrix(Vector(1.0f, .0f, .0f), .0f)); 
	Sphere sphere(Vector(), sphereRadius);
	InfiniteCylinder cylx(Vector(), Matrix(Vector(1.0f, .0f, .0f), .0f), cylRadius);
	InfiniteCylinder cyly(Vector(), Matrix(Vector(.0f, .0f, 1.0f), M_PI / 2.0f), cylRadius);
	InfiniteCylinder cylz(Vector(), Matrix(Vector(.0f, 1.0f, .0f), M_PI / 2.0f), cylRadius);

	box.setColor(Vector(.7f, .2f, .2f));

	Node root, node1, node2, node3, node4, node5, node6, node7, node8;

	root.setOperation(Operation::DIFFERENCE);
	node1.setOperation(Operation::INTERSECTION);
	node4.setOperation(Operation::UNION);
	node6.setOperation(Operation::UNION);

	root.setLeftChild(node1);
	root.setRightChild(node4);

	node1.setLeftChild(node2);
	node2.setObject(box);
	node1.setRightChild(node3);
	node3.setObject(sphere);

	node4.setLeftChild(node5);
	node5.setObject(cylz);
	node4.setRightChild(node6);

	node6.setLeftChild(node7);
	node7.setObject(cyly);
	node6.setRightChild(node8);
	node8.setObject(cylx);




	CSG csg(root);


	std::vector<std::shared_ptr<Object>> pobjects;
	
	pobjects.push_back(std::shared_ptr<CSG>(new CSG(root)));

//	pobjects[0] -> setColor(Vector(.3f, .7f, .3f));

	std::vector<std::shared_ptr<Light>> lights;
	lights.push_back(std::shared_ptr<Light>(new Light(Vector(1.5f, 4.0f, .0f))));
	
	Scene scene;
	scene.objects = pobjects;
	scene.lights = lights;

	Camera camera(Vector(2.0f), Vector());

	std::vector<Vector> colors;
	Marcher marcher(scene, width, height);

	marcher.setAntiAliasingSamples(5);
//	marcher.setProjection(Projection::ORTHOGRAPHIC);

	marcher.render(camera, colors);

	saveJpg(addr, width, height, colors);
}	

