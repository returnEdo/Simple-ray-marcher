#pragma once

#include "Vector.h"

namespace Constants{
	
	/* Object constants */
	const float 	DELTA 			= .00001f;		// used for increments in central difference
	const float 	EPSILON 		= .000001f;		// used for comparison

	const Vector 	WHITE(1.0f);

	/* Marcher constants */
	const int	ITER_MAX		= 100;			// marching iterations 
	const float 	SUPREMUM_TOLL		= 100.0f;		// max radius allowed
	const float	INFIMUM_TOLL		= .0001f;		// min radius allowed
	const float	OFFSET_DISTANCE 	= .001f;		// offset fromsurfaces
	const float 	AMBIENT_INTENSITY	= .1f;
	
	const Vector	BACKGROUND_COLOR(.3f, .3f, .3f);

	/* Collision constants */
	const int 	RADIUS_QUEUE_SIZE	= 10;			// buffer of radius size (for ambient occlusion)
}
