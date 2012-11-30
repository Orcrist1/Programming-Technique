#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "polygon.h"
#include "file.h"

POINT** readFile(const char* path)
{
   POINT** points = NULL;
   int size = 0;

   FILE* file = fopen(path, "r");
   if(file != NULL)
   {
      fscanf(file, "%d", &size);
      points = createPOINT(size);

      if(points != NULL)
      {
         for(int i = 0; i < size; i++)
           fscanf(file, "%lf %lf", &points[i]->x , &points[i]->y);
      }

      fclose(file);
   }
   return points;
}

bool writeFile(POINT** points, size_t n,  char* path) //change le nom parametre "path" partout !
{
    bool state = false;
    FILE* file = NULL;
    char *p = NULL;

    if(points != NULL)
    {
        char *filename = calloc(strlen(path) + 2, sizeof(char));
        if(filename != NULL)
        {
            memcpy(filename, path, sizeof(filename));
            if( (p = strstr(filename, ".in")) != NULL)
            {
                memmove(p, ".out", sizeof(".out"));
                file = fopen(filename, "w+");
                if(file != NULL)
                {
                    for(unsigned int i = 0; i < n; i++)
                    {
                        fprintf(file, "%f %f\n", points[i]->x, points[i]->y);
                    }
                    fclose(file);
                }
            }
            free(filename);
        }
    }

    return state;
}

