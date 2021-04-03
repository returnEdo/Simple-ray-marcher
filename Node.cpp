#include "Node.h"

#include <cassert>
#include <algorithm>

void Node::setLeftChild(Node& leftChild_){

	leftChild = &leftChild_;
	
	leftChild -> setParent(*this);
}


void Node::setRightChild(Node& rightChild_){

	rightChild = &rightChild_;
	
	rightChild -> setParent(*this);
}


float distanceCSG(Node* node, const Vector& x){

	Node* left = node -> leftChild;
	Node* right = node -> rightChild;

	return distance(
		(left -> isLeaf()? left -> object -> sdf(x): distanceCSG(left, x)),
		(right -> isLeaf()? right -> object -> sdf(x): distanceCSG(right, x)), node -> operation);

}

float distance(float a, float b, const Operation& operation){

	assert(operation != Operation::NONE);

	switch(operation){

		case (Operation::UNION):

			return std::min(a, b);

		case (Operation::INTERSECTION):

			return std::max(a, b);

		case (Operation::DIFFERENCE):

			return std::max(a, -b);
	}

	return 1.0f;
}
