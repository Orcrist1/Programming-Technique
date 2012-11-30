#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "polygon.h"

int compareTangent(const void* point1, const void* point2)
{
    int returnValue;
    POINT const **pPoint1 = point1;
    POINT const **pPoint2 = point2;
    double diff =   (minX - (*pPoint2)->x) / (minY - (*pPoint2)->y) -
                    (minX - (*pPoint1)->x) / (minY - (*pPoint1)->y);


   if (diff > 0) returnValue = 1;
   else if (diff < 0) returnValue = -1;
   else returnValue = 0;

   return returnValue;
}

POINT** createPOINT(size_t n)
{
    POINT** points = malloc(sizeof(POINT*) * n);
    if(points != NULL)
    {
        for(unsigned int i = 0; i < n; i++)
        {
            points[i]  = malloc(sizeof(POINT));
        }
    }

    return points;
}


bool addPoint(POINT** points, size_t n, double x, double y)
{
   bool state = false;
   POINT** tempory = realloc(points, (n + 1) *  sizeof(POINT*));

   if(tempory != NULL)
   {
      points = tempory;
      points[n] = malloc(sizeof(POINT));
      if(points[n] != NULL)
      {
        points[n]->x = x;
        points[n]->y = y;
        state = true;
      }
   }

   return state;
}

bool destroyPoint(POINT *points[], size_t n)
{
    bool state = false;

    if(points != NULL)
    {
         for(unsigned int i = 0; i < n; i++)
         {
           free(points[i]);
           points[i] = NULL;
         }

         free(points);
         points = NULL;
         state = true;
    }

    return state;
}

void polygon(POINT *points[], size_t n)
{
    int index = 0;

    if(points != NULL)
    {
        index = minimumAxisY(points, n);
        minX = points[index]->x;
        minY = points[index]->y;

        qsort(points, n, sizeof(points[0]), compareTangent);
        addPoint(points, n, points[0]->x, points[0]->y);
    }
}

void display(POINT** points, size_t n)
{
    for(unsigned int i = 0; i < n; i++)
        printf("%05d | %lf  %lf\n", i, points[i]->x, points[i]->y);
}

int minimumAxisY(POINT** points, size_t n) /* modifier par qsort */
{
    int indexPoint = 0;
    double minimumValue = points[0]->y;

    for(unsigned int i = 1; i < n; i++)
    {
        if(minimumValue > points[i]->y)
        {
            minimumValue = points[i]->y;
            indexPoint = i;
        }
    }

    return indexPoint;
}





