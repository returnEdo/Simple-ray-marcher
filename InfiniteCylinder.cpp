#include "InfiniteCylinder.h"


InfiniteCylinder::InfiniteCylinder(const Vector& passingThrough_, const Matrix& attitude_, float radius_):
	passingThrough(passingThrough_),
	attitude(attitude_),
	radius(radius_)	{}

float InfiniteCylinder::sdf(const Vector& x) const{

	Vector xl = attitude * (x - passingThrough);

	return (sqrt(xl.y * xl.y + xl.z * xl.z) - radius);
}
