#pragma once


#include "Object.h"


class Smoother: public Object{

	private:

	Object* object;

	float r = 1.0f;

	public:

	Smoother(Object* object_, float r_);

	inline float getSmootherConstants(void)		const { return r; }

	inline virtual Smoother* copy(void) 		const override { return (new Smoother(object, r)); }
	
	inline virtual float sdf(const Vector& x) 	const override { return (object -> sdf(x) - r); }
};
