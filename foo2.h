#ifndef _FOO2_H_
#define _FOO2_H_

class Foo
{
public:
	Foo (int f);
	virtual ~Foo();

	void do_something (void);

protected:
	int num = 0;
};

#endif // _FOO2_H_

