#include <stdio.h>
#include <dlfcn.h>

const int (*foo_pointer)(void);

int main (int argc, char *argv[])
{
	void *handle = NULL;
	char *error = NULL;

	if (argc != 2)
		return 1;

	handle = dlopen (argv[1], RTLD_NOW);
	if (!handle) {
		printf ("dlopen failed: %s\n", dlerror());
		return 1;
	}

	foo_pointer = dlsym (handle, "foo");
	error = dlerror();
	if (error) {
		printf ("dlsym failed: %s\n", error);
		dlclose (handle);
		return 1;
	}

	printf ("foo returns: %d\n", (*foo_pointer)());

	dlclose (handle);
	return 0;
}

