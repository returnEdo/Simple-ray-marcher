#pragma once

#include "Object.h"
#include "Node.h"


class CSG: public Object{

	private:

	Node* root;

	public:

	CSG(Node& root_);
	CSG(Node* root_);

	inline virtual CSG* copy(void)	const override { return (new CSG(root)); }

	virtual float sdf(const Vector& x) const override;
};
