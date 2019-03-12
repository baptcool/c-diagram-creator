#pragma once
#include<SDL.h>
#include"window.h"
#include"diagramme.h"
#include <SDL_ttf.h>



int main(int argc, char * argv[])
{
	diagramme dia;
	dia.recupere_shape(); //c'est tr�s basique mais il sufit d'appeler cette fonction.

    return EXIT_SUCCESS;
}
