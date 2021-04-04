#include "Torus.h"

#include <cmath>

#include "MathMisc.h"

Torus::Torus(float bigRadius_, float smallRadius_,
	      const Vector& position_, const Matrix& attitude_):
		bigRadius(bigRadius_),
		smallRadius(smallRadius_),
		position(position_),
		attitude(attitude_)	{}

float Torus::sdf(const Vector& x) const{

	Vector xl = attitude * (x - position);
	
	return sqrt(pow2(sqrt(pow2(xl.x) + pow2(xl.z)) - bigRadius) + pow2(xl.y)) - smallRadius;
}
