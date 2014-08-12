#include <iostream>

#include <dlfcn.h>

#include "polygon.h"

int
main()
{
	// load the Triangle library
	void* lib_triangle = dlopen ("./triangle.so", RTLD_LAZY);
	if (!lib_triangle) {
		std::cerr << "Cannot load library: " << dlerror() << '\n';
		return 1;
	}

	// reset errors
	dlerror();

	// load the symbols
	create_t* create_triangle = (create_t*) dlsym (lib_triangle, "create");	// "_Z6createv"
	const char* dlsym_error = dlerror();
	if (dlsym_error) {
		std::cerr << "Cannot load symbol create: " << dlsym_error << '\n';
		return 1;
	}

	destroy_t* destroy_triangle = (destroy_t*) dlsym (lib_triangle, "destroy");	// "_Z7destroyP7Polygon"
	dlsym_error = dlerror();
	if (dlsym_error) {
		std::cerr << "Cannot load symbol destroy: " << dlsym_error << '\n';
		return 1;
	}

	// create an instance of the class
	Polygon* poly = create_triangle();

	// use the class
	poly->set_side_length (7);
	std::cout << "The area is: " << poly->area() << '\n';

	// destroy the class
	destroy_triangle (poly);

	// unload the triangle library
	dlclose (lib_triangle);
}

