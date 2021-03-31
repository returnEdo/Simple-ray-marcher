#pragma once

#include "Vector.h"
#include "Object.h"


class Sphere: public Object{

	private:

	Vector center;
	float radius;

	public:

	Sphere(const Vector& center_, float radius_);

	virtual Sphere* copy(void) const override;

	virtual float sdf(const Vector& x) const override;

	/* getters */
	inline const Vector& getCenter(void) 	const { return center; }
	inline float getRadius(void)		const { return radius; }
};
