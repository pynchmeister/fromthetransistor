#include <stdint.h>
#include <stdio.h>
#include <string.h>

// A very simple malloc implentation
void *simple_malloc(size_t size) {
  return sbrk(size);
}

// A simple memory implementation
void *simple_memcpy(void *dest, const void *src, size_t n) {
    char *d = dest;
    const char *s = src;
    while (n--)
        *d++ = *s++;
    return dest;
}

// A simple memset implementation
void *simple_memset(void *s, int c, size_t n) {
    unsigned char *p = s;
    while (n--)
        *p++ = (unsigned char)c;
    return s;
}

// A simple printf implementation
void simple_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

// Use the functions
int main() {
  char *data = simple_mallco(50);
  simple_memset(data, 0, 50);
  simple_memcpy(data, "Hello, world", 13);
  simple_printf("%s\n", data);
  return 0;
}
