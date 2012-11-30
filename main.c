/**
 * @file main.c
 * @brief
 * @author Julien RAMAKERS
 * @date 1 october 2012
 *
 *
 * Ce programme permet de faire du traitement d'images monochromes.
 * Voici la liste des differents traitements qu'il peut effectuer :
 *  + copie de l'image dans un nouveau fichier.
 *  + augmenter la luminosité de l'image ou l'assombrir.
 *  + appliquer un filtre de diffusion sur l'image.
 *  + changer la dimension de l'image.
 * Format de fichier pris en charge :
 *  -> PGM (Portable Graymap File Format)
 */

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




