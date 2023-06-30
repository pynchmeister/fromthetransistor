#include <stdio.h>
#include <dlfcn.h>

int main() {
    void *handle;
    void (*someFunction)();

    // Load a shared library 
    handle = dlopen("libSomeLibrary.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }

    // Clear any existing error
    dlerror();

    // Get the function from the library
    *(void **) (&someFunction) = dlsym(handle, "someFunction");

    // Check for any errors
    char *error = dlerror();
    if (error != NULL) {
        fprintf(stderr, "%s\n", error);
        return 1;
    }

    // Call the function
    (*someFunction)();

    // Close the library
    dlclose(handle);

    return 0;
}
