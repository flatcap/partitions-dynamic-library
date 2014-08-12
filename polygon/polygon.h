#ifndef _POLYGON_H_
#define _POLYGON_H_

class Polygon
{
public:
	Polygon (void) {}
	virtual ~Polygon() {}

	void set_side_length (double side_length) {
		side_length_ = side_length;
	}

	virtual double area (void) const = 0;

protected:
	double side_length_ = 0;
};

// the types of the class factories
typedef Polygon* create_t (void);
typedef void destroy_t (Polygon*);

#endif // _POLYGON_H_

