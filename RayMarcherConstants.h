#pragma once

#include "Vector.h"

namespace Constants{
	
	/* Object constants */
	const float 	DELTA 			= .00001f;		// used for increments in central difference
	const float 	EPSILON 		= .000001f;		// used for comparison

	const Vector 	WHITE(1.0f);

	/* Marcher constants */
	const int	ITER_MAX		= 1000;			// marching iterations 
	const int	ANTI_ALIASING_SAMPLES	= 3;
	const float 	SUPREMUM_TOLL		= 100.0f;		// max radius allowed
	const float	INFIMUM_TOLL		= .000001f;		// min radius allowed
	const float	OFFSET_DISTANCE 	= .00001f;		// offset fromsurfaces
	const float 	AMBIENT_INTENSITY	= .1f;
	
	const Vector	BACKGROUND_COLOR(.3f, .3f, .3f);

	const int	AMBIENT_OCCLUSION_SAMPLES 	= 50;		// samples necessary for AO index
	const float	AMBIENT_OCCLUSION_STEP		= .01f;		// step size along normal @ collisionPosition
	const float	AMBIENT_OCCLUSION_EXPONENT	= .7f;		// step size along normal @ collisionPosition
	const float	AMBIENT_OCCLUSION_INTENSITY	= .08f;	

	/* Collision constants */
	const int 	RADIUS_QUEUE_SIZE	= 10;			// buffer of radius size (for ambient occlusion)
}
