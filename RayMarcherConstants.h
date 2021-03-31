#pragma once

#include "Vector.h"

namespace Constants{
	
	/* Object constants */
	const float 	DELTA 		= .00001f;		// used for increments in central difference
	const float 	EPSILON 	= .000001f;		// used for comparison

	const Vector 	WHITE(1.0f);

	/* Marcher constants */
	const int	ITER_MAX	= 100;
	const float 	SUPREMUM_TOLL	= 100.0f;
	const float	INFIMUM_TOLL	= .0001f;
	
	const Vector	BACKGROUND_COLOR(.3f, .3f, .3f);
}
