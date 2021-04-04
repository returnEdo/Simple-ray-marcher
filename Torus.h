#pragma once

#include "Object.h"
#include "Vector.h"
#include "Matrix.h"


class Torus: public Object{

	private:

	float bigRadius 	= 3.0f;
	float smallRadius	= 1.0f;

	Vector position;
	Matrix attitude;

	public:

	Torus(float bigRadius_, float smallRadius_,
	      const Vector& position_, const Matrix& attitude_);


	/* getters */

	inline float getBigRaidus(void)		const { return bigRadius; }
	inline float getSmallRadius(void)	const { return smallRadius; }

	inline virtual Torus* copy(void) const override	{ return (new Torus(bigRadius, smallRadius, position, attitude)); }

	virtual float sdf(const Vector& x) const override;
};
