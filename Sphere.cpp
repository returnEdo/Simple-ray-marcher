#include "Sphere.h"



Sphere::Sphere(const Vector& center_, float radius_):
		center(center_),
		radius(radius_){

}

Sphere* Sphere::copy(void) const{

	return (new Sphere(center, radius));
}


float Sphere::sdf(const Vector& x) const{

	Vector d = x - center;

	return (norm(d) - radius);
}
