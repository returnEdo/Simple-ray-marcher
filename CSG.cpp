#include "CSG.h"

CSG::CSG(Node& root_):	root(&root_)	{}
CSG::CSG(Node* root_):	root(root_)	{}

float CSG::sdf(const Vector& x)	const{

	return distanceCSG(root, x);
}
