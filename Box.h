#pragma once

#include "Object.h"
#include "Vector.h"
#include "Matrix.h"

class Box: public Object{

	private:

	Vector dimensions;			// box half sides
	Vector position;
	
	Matrix attitude;			// world to box transform

	public:

	Box(const Vector& dimensions_,
	    const Vector& position_,
	    const Matrix& attitude_);
	
	/* getters */

	inline const Vector& getDimensions(void)	const { return dimensions; }
	inline const Vector& getPosition(void)		const { return position; }
	inline const Matrix& getAttitude(void)		const { return attitude; }

	/* virtual copy */
	virtual Box* copy(void) const override;

	virtual float sdf(const Vector& x) const override;
};
