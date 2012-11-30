#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#include "polygon.h"
#include <stdbool.h>

POINT** readFile(const char* path);
bool writeFile(POINT** points, size_t n, char* path);

#endif // FILE_H_INCLUDED
