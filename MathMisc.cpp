#include "MathMisc.h"

#include <algorithm>
#include <cstdlib>

#include "RayMarcherConstants.h"


#define MAXF static_cast<float>(RAND_MAX)


bool comparef(float a, float b){

	float absDiff = (a- b > .0f? a - b: b - a);

	return absDiff <= Constants::EPSILON;
}

float clamp(float val, float lower, float upper){
	
	return std::min(upper, std::max(lower, val));
}

Vector clamp(Vector val, const Vector& lower, const Vector& upper){
	
	return Vector(clamp(val.x, lower.x, upper.x),
		      clamp(val.y, lower.y, upper.y),
		      clamp(val.z, lower.z, upper.z));
}

float randf(float a, float b){
	
	return ((static_cast<float>(rand()) / MAXF) * (b - a) + a); 

}
