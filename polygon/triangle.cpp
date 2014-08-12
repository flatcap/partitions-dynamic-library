#include <cmath>

#include "polygon.h"

class Triangle : public Polygon
{
public:
	virtual double area (void) const
	{
		return side_length_ * side_length_ * sqrt(3) / 2;
	}
};


// the class factories

extern "C"
Polygon*
create (void)
{
	return new Triangle;
}

extern "C"
void
destroy (Polygon* p)
{
	delete p;
}

