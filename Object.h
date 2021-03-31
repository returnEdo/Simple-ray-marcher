#pragma once

#include "Vector.h"
#include "MathMisc.h"
#include "RayMarcherConstants.h"

#include <cmath>

class Object{

	protected:

	Vector color = Constants::WHITE;

	public:
	
	/* needed in scene */
	virtual Object* copy(void) const = 0;

	virtual float sdf(const Vector& x) const = 0;
	
	/* setters */
	inline void setColor(const Vector& color_)	{ color = color_; }

	/* getters */
	void getNormalAt(const Vector& x, Vector& n);
	inline const Vector& getColor(void) 		const { return color; }
	
	/* equality is a float equality test */
	inline bool isOnSurface(const Vector& x)	const { return comparef(sdf(x), .0f); }
	inline bool isOutside(const Vector& x)		const { return (sdf(x) > Constants::EPSILON); }
	inline bool isInside(const Vector& x)		const { return (sdf(x) < -Constants::EPSILON); }
	
	/* operators */

	friend float min(const Object& a, const Object& b, const Vector& x);
	friend float max(const Object& a, const Object& b, const Vector& x);

	inline friend float round(const Object& a, float r, const Vector& x)	{ return (a.sdf(x) - r); }
	inline friend float shell(const Object& a, float t, const Vector& x)	{ return (abs(a.sdf(x)) - t); }
};
