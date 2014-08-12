#include <iostream>

#include "foo2.h"

Foo::Foo (int f) :
	num(f)
{
	std::cout << "start" << std::endl;
}

Foo::~Foo()
{
	std::cout << "end" << std::endl;
}

void
Foo::do_something (void)
{
	std::cout << "SOMETHING" << std::endl;
}

