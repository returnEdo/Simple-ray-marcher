#pragma once

#include "Vector.h"

class Light{

	private:

	Vector position;
	Vector color;

	public:

	Light(const Vector& position_, const Vector& color_ = Constants::WHITE):
			position(position_),
			color(color_)	{}

	/* getters */
	inline const Vector& getPosition(void) 		const { return position; }
	inline const Vector& getColor(void)		const { return color; }

	/* setters */
	inline void setPosition(const Vector& position_)	{ position = position_; }
	inline void setColor(const Vector& color_)		{ color = color_; }
};
