#pragma once

#include "Object.h"
#include "Vector.h"

enum class Operation{

	UNION,
	INTERSECTION,
	DIFFERENCE,
	NONE
};


class Node{
	
	public:

	Node* parent		= nullptr;
	Node* leftChild		= nullptr;
	Node* rightChild	= nullptr;

	Object* object		= nullptr;

	Operation operation	= Operation::NONE;

	inline bool isRoot(void) 	const { return parent == nullptr; }
	inline bool isLeaf(void)	const { return ((leftChild == nullptr) and (rightChild == nullptr)); }

	/* setters */
	
	inline void setOperation(const Operation& operation_)	{ operation = operation_; }
	inline void setObject(Object& object_)			{ object = &object_; }

	inline void setParent(Node& parent_)			{ parent = &parent_; }

	void setLeftChild(Node& leftChild_);
	void setRightChild(Node& rightChild_);
};


float distanceCSG(Node* node, const Vector& x);
float distance(float a, float b, const Operation& operation);
