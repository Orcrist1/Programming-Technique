#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "polygon.h"


int main(int argc, char* argv[])
{
    POINT** points = NULL;

    if(argc > 1)
    {
        points = readFile(argv[1]);
        if(points != NULL)
        {
            display(points,12);
            polygon(points, 12);
            display(points, 12);

            writeFile(points, 13, argv[1]);
            destroyPoint(points, 13);
        }
    }

    return 0;
}




