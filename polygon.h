#ifndef POLYGON_H_INCLUDED
#define POLYGON_H_INCLUDED
#include <stdlib.h>
#include <stdbool.h>

double minX;
double minY;

typedef struct
{
    double x;
    double y;
}POINT;


POINT** createPOINT(size_t n);
bool addPoint(POINT** points, size_t n, double x, double y);
bool destroyPoint(POINT *points[], size_t n);

void polygon(POINT *points[], size_t n);
int compareTangent(const void* point1, const void* point2);
void display(POINT** points, size_t n); //MODIFIER LA FONCTION
int minimumAxisY(POINT** points, size_t n);

#endif // POLYGON_H_INCLUDED
