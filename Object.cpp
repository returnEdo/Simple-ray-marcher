#include "Object.h"



void Object::getNormalAt(const Vector& x, Vector& n){
	/* normal estimation with central difference */

	n.x = (sdf(Vector(x.x + Constants::DELTA, x.y, x.z)) - 
	       sdf(Vector(x.x - Constants::DELTA, x.y, x.z))) / Constants::DELTA;
	
	n.y = (sdf(Vector(x.x, x.y + Constants::DELTA, x.z)) - 
	       sdf(Vector(x.x, x.y - Constants::DELTA, x.z))) / Constants::DELTA;

	n.z = (sdf(Vector(x.x, x.y, x.z + Constants::DELTA)) - 
	       sdf(Vector(x.x, x.y, x.z - Constants::DELTA))) / Constants::DELTA;

	n.normalize();
}


float min(const Object& a, const Object& b, const Vector& x){

	float sdfa = a.sdf(x);
	float sdfb = b.sdf(x);

	return (sdfa > sdfb? sdfb: sdfa);
}

float max(const Object& a, const Object& b, const Vector& x){

	float sdfa = a.sdf(x);
	float sdfb = b.sdf(x);

	return (sdfa < sdfb? sdfb: sdfa);
}
