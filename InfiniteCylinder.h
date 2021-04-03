#pragma once

#include "Object.h"
#include "Vector.h"
#include "Matrix.h"


class InfiniteCylinder: public Object{

	private:

	Vector passingThrough;

	Matrix attitude;			// world to local rotation matrix

	float radius;

	public:

	InfiniteCylinder(const Vector& passingThrough_, const Matrix& attitude_, float radius_);

	virtual InfiniteCylinder* copy(void) const override 	{ return (new InfiniteCylinder(passingThrough, attitude, radius)); }

	virtual float sdf(const Vector& x) const override;
};

