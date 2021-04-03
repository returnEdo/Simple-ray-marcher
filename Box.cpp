#include "Box.h"


#include <algorithm>



Box::Box(const Vector& dimensions_,
	 const Vector& position_,
    	 const Matrix& attitude_):
		dimensions(dimensions_),
		position(position_),
		attitude(attitude_)	{}

Box* Box::copy(void) const{

	return (new Box(dimensions, position, attitude));
}


float Box::sdf(const Vector& y) const{
	/* sdf @ x*/
	
	Vector x = attitude * (y - position);

	Vector diff = abs(x) - dimensions;
	
	Vector diff0(std::max(diff.x, .0f),
		     std::max(diff.y, .0f),	
		     std::max(diff.z, .0f));
	
	return (norm(diff0) + std::min(.0f, std::max(std::max(diff.x, diff.y), diff.z)));

}
