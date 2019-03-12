#include "window.h"
#include<iostream>

using namespace std;

// j'ai tenu a refaire l'essemble des fonctions d'affichage.

window::window( int width, int height)
{
	std::cout << "Constructor MyWindow" << std::endl;
	this->width = width;
	this->height = height;
	/*On initialise la SDL.*/
	SDL_Init(SDL_INIT_VIDEO);
	SDL_WM_SetCaption("baptiste millot diagramme", NULL);
	surface = SDL_CreateRGBSurface(SDL_HWSURFACE, width, height, 32, 0, 0, 0, 0);
	sdlWindow = SDL_SetVideoMode(width, height, 32, SDL_ANYFORMAT | SDL_HWSURFACE);

	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 160, 168, 169));
	SDL_FillRect(sdlWindow, NULL, SDL_MapRGB(sdlWindow->format, 0, 0, 0));
	SDL_Rect pos;
	pos.x = 0;
	pos.y = 0;
	SDL_BlitSurface(surface, NULL, sdlWindow, &pos);
	SDL_WM_SetIcon(SDL_LoadBMP("TETE_DE_MORT.bmp"), NULL);
}

window::window()
{





	std::cout << "Constructor MyWindow" << std::endl;
	this->width = 1000;
	this->height = 700;
	/*On initialise la SDL.*/
	SDL_Init(SDL_INIT_VIDEO);
	SDL_WM_SetCaption("baptiste millot diagramme", NULL);
	surface = SDL_CreateRGBSurface(SDL_HWSURFACE, this->width, this->height, 32, 0, 0, 0, 0);
	sdlWindow = SDL_SetVideoMode(this->width, this->height, 32, SDL_ANYFORMAT | SDL_HWSURFACE);

	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 160, 168, 169));
	SDL_FillRect(sdlWindow, NULL, SDL_MapRGB(sdlWindow->format, 0, 0, 0));
	SDL_Rect pos;
	pos.x = 0;
	pos.y = 0;
	SDL_BlitSurface(surface, NULL, sdlWindow, &pos);


	SDL_WM_SetIcon(SDL_LoadBMP("TETE_DE_MORT.bmp"), NULL);
}

window::~window()
{
	SDL_FreeSurface(surface); // Lib�ration de la surface
	SDL_Quit();
}

void window::dessinerRectangle(int hauteur, int largeur, SDL_Rect position, std::string couleur)
{
	Uint32 pixel = SDL_MapRGB(surface->format, 0, 0, 0);

	switch (couleur[0])
	{
	case 'n': //noir
		pixel = SDL_MapRGB(surface->format, 50, 50, 50);
		break;
	case 'r'://rouge
		pixel = SDL_MapRGB(surface->format, 250, 30, 24);
		break;
	case 'b'://bleu
		pixel = SDL_MapRGB(surface->format, 31, 33, 250);
		break;
	case 'v'://vert
		pixel = SDL_MapRGB(surface->format, 0, 210, 10);
		break;
	default:
		pixel = SDL_MapRGB(surface->format, 0, 0, 0);
		break;
	}
	int i, j;
	std::cout << "dessin en cours rectangle" << std::endl;
	position.y += 25;
	for (i = 0; i < hauteur; i++) {
		for (j = 0; j < largeur; j++) {
			if (position.x + i < 0 || position.y + j < 0 || position.x + i > width || position.y + j > height) {
				std::cout << "erreur dans trac� rectangle" << std::endl;
				return;
			}
			setPixel(position.x + i, position.y + j, pixel);
		}
	}



	SDL_Rect pos;
	pos.x = 0;
	pos.y = 0;
	SDL_BlitSurface(surface, NULL, sdlWindow, &pos);//surperposition
	SDL_Flip(sdlWindow); //refresh
}


void window::dessinerCarre( int cote, SDL_Rect position, std::string couleur)
{

	Uint32 pixel = SDL_MapRGB(surface->format, 0, 0, 0);
	switch (couleur[0])
	{
	case 'n': //noir
		pixel = SDL_MapRGB(surface->format, 50, 50, 50);
		break;
	case 'r'://rouge
		pixel = SDL_MapRGB(surface->format, 250, 30, 24);
		break;
	case 'b'://bleu
		pixel = SDL_MapRGB(surface->format, 31, 33, 250);
		break;
	case 'v'://vert
		pixel = SDL_MapRGB(surface->format, 0, 210, 10);
		break;
	default:
		pixel = SDL_MapRGB(surface->format, 0, 0, 0);
		break;
	}

	int i, j;
	std::cout << "dessin en cours carre" << std::endl;
	for (i = 0; i < cote; i++){
		for (j = 0; j < cote; j++){
			if (position.x + i < 0 || position.y + j < 0 || position.x + i > width || position.y + j > height) {
				std::cout << "erreur dans trac� carre" << std::endl;
				return;
			}
			setPixel(position.x + i, position.y + j, pixel);
		}
	}

	SDL_Rect pos;
	pos.x = 0;
	pos.y = 0;
	SDL_BlitSurface(surface, NULL, sdlWindow, &pos);
	SDL_Flip(sdlWindow);
}



void window::dessinerCercle( int radius, SDL_Rect position, std::string couleur)
{

	Uint32 pixel = SDL_MapRGB(surface->format, 0, 0, 0);
	switch (couleur[0])
	{
	case 'n': //noir
		pixel = SDL_MapRGB(surface->format, 50, 50, 50);
		break;
	case 'r'://rouge
		pixel = SDL_MapRGB(surface->format, 250, 30, 24);
		break;
	case 'b'://bleu
		pixel = SDL_MapRGB(surface->format, 31, 33, 250);
		break;
	case 'v'://vert
		pixel = SDL_MapRGB(surface->format, 0, 210, 10);
		break;
	default:
		pixel = SDL_MapRGB(surface->format, 0, 0, 0);
		break;
	}
	position.y += 50;
	position.x += 50;
	std::cout << "dessin en cours cercle"<<std::endl;
	for (int i = -radius; i <= radius; i++) {
		for (int j = -radius; j <= radius; j++) {
			if ((i * i + j * j) <= (radius * radius)) {
				if (position.x + i < 0 || position.y + j < 0 || position.x + i > width || position.y + j > height) {
					std::cout << "erreur dans trace cercle" << std::endl;
					return;
				}
				//cout << "(" << i << ";" << j << ")" << endl;
				setPixel(position.x + i, position.y + j, pixel);
			}
		}
	}

	SDL_Rect pos;
	pos.x = 0;
	pos.y = 0;
	SDL_BlitSurface(surface, NULL, sdlWindow, &pos);
	SDL_Flip(sdlWindow);

}

void window::dessinerLosange( int longeur1, SDL_Rect position, std::string couleur)
{
	Uint32 pixel = SDL_MapRGB(surface->format, 0, 0, 0);
	switch (couleur[0])
	{
	case 'n': //noir
		pixel = SDL_MapRGB(surface->format, 50, 50, 50);
		break;
	case 'r'://rouge
		pixel = SDL_MapRGB(surface->format, 250, 30, 24);
		break;
	case 'b'://bleu
		pixel = SDL_MapRGB(surface->format, 31, 33, 250);
		break;
	case 'v'://vert
		pixel = SDL_MapRGB(surface->format, 0, 210, 10);
		break;
	default:
		pixel = SDL_MapRGB(surface->format, 0, 0, 0);
		break;
	}
	std::cout << "dessin en cours losange" << std::endl;
	int pas = 1;
	int millieu = longeur1 / 2;
	int tolerance = -1;
	for (int i = 0; i <= longeur1; i++) {
		for (int j = 0; j <= longeur1; j++) {
			if (j <= millieu) {
				if ( millieu - tolerance <= j ){
					setPixel(position.x + i, position.y + j, pixel);
					}
			}else {
				if (j <= millieu + tolerance) {
					setPixel(position.x + i, position.y + j, pixel);
				}
			}

		}
		tolerance += pas;
		if (i == millieu) {
			pas = -1;
		}
	}


	SDL_Rect pos;
	pos.x = 0;
	pos.y = 0;
	SDL_BlitSurface(surface, NULL, sdlWindow, &pos);
	SDL_Flip(sdlWindow);
}
void window::dessinerFleche(int longeur1, int type, SDL_Rect position, std::string couleur)
{
	Uint32 pixel = SDL_MapRGB(surface->format, 0, 0, 0);
	switch (couleur[0])
	{
	case 'n': //noir
		pixel = SDL_MapRGB(surface->format, 50, 50, 50);
		break;
	case 'r'://rouge
		pixel = SDL_MapRGB(surface->format, 250, 30, 24);
		break;
	case 'b'://bleu
		pixel = SDL_MapRGB(surface->format, 31, 33, 250);
		break;
	case 'v'://vert
		pixel = SDL_MapRGB(surface->format, 0, 210, 10);
		break;
	default:
		pixel = SDL_MapRGB(surface->format, 0, 0, 0);
		break;
	}
	std::cout << "dessin en cours losange" << std::endl;

	switch (type) {
	case 1:
	{
		position.y += 17;
		position.x += 0;
		int pas = 1;
		int millieu = (longeur1 - 1) / 2;
		int tolerance = 1;
		for (int j = 0; j <= longeur1; j++) {
			for (int i = 0; i <= longeur1; i++) {
				if (i <= tolerance) {
					setPixel(position.x + i, position.y + j, pixel);
				}

			}
			tolerance += pas;
			if (j == millieu) {
				pas = -1;
			}
		}
	}
	break;
	case 2:
	{
		position.y += 20;
		position.x -= 9;
		int pas = 1;
		int millieu = (longeur1 - 1) / 2;
		int tolerance = 1;
		for (int i = 0; i <= longeur1; i++) {
			for (int j = 0; j <= longeur1; j++) {

				if (j <= tolerance) {
					setPixel(position.x + i, position.y + j, pixel);
				}

			}
			tolerance += pas;
			if (i == millieu) {
				pas = -1;
			}
		}
		break;
	}

	case 3:
	{
		position.x -= 5;
		position.y -= 10;
		int pas = 1;
		int millieu = longeur1 / 2;
		int tolerance = longeur1;
		for (int j = 0; j <= longeur1; j++) {
			for (int i = 0; i <= longeur1; i++) {
				if (i >= tolerance) {
					setPixel(position.x + i, position.y + j, pixel);
				}

			}

			if (j < millieu) {
				tolerance -= 1;
			}
			else {
				tolerance += 1;
			}
		}
		break; }

	}
	SDL_Rect pos;
	pos.x = 0;
	pos.y = 0;
	SDL_BlitSurface(surface, NULL, sdlWindow, &pos);
	SDL_Flip(sdlWindow);
}

void window::setPixel( int x, int y, Uint32 pixel)
{
	if (y > getHeight()  || x > getWidth()) {
		cout << getHeight() << getWidth() << endl;
		cout << "erreur, une des formes ou trais depasse la fenetre   --> position x : "<<x<<" y : "<<y<<endl;
		pause();
		detruire();
		return;
	}
	//Convert the pixels to 32 bit
	Uint32 *pixels = (Uint32 *)surface->pixels;

	//Set the pixel
	pixels[(y * surface->w) + x] = pixel;
}

void window::detruire()
{
	SDL_FreeSurface(surface); // Lib�ration de la surface
	SDL_Quit();
}



int window::getWidth()
{

	return width;
}

int window::getHeight()
{
	return height;
}

void window::pause()
{
	std::cout<<"programme en pause";
	SDL_Event evt;
	char done = 0;
        

	while (!done)
	{
		SDL_WaitEvent(&evt);
		if (evt.type == SDL_QUIT || evt.type == SDL_KEYDOWN)
			done = 1;
	}
	detruire();
}


void window::ajouterText(int taille, SDL_Rect position, std::string texte_a_afficher){
	std::cout << "ajout texte en cours.."<<std::endl;
    if(texte_a_afficher.size()>11 ){ //pour permettre un retour a la ligne si la phrase a afficher est trop longue
            int i=1;
            while (texte_a_afficher[i] != ' ' ){
                i++;
				
            }
            int longeur = texte_a_afficher.size();
            string nouvellechaine = texte_a_afficher.substr(i+1, longeur - i);
            texte_a_afficher = texte_a_afficher.substr(0, i);
            const char * c2 = nouvellechaine.c_str();
            const char * c = texte_a_afficher.c_str();
            SDL_Surface  *texte = NULL;
            TTF_Font *police = NULL;
            SDL_Color couleurNoire = {210, 210, 210};
            TTF_Init();
            police = TTF_OpenFont("Ubuntu-B.ttf", taille);
            texte = TTF_RenderText_Blended(police, c, couleurNoire);
            SDL_BlitSurface(texte, NULL, surface, &position); /* Blit du texte */

            texte = TTF_RenderText_Blended(police, c2, couleurNoire);
            position.y += 15;
            
            SDL_BlitSurface(texte, NULL, surface, &position); /* Blit du texte */
			SDL_Rect pos;
			pos.x = 0;
			pos.y = 0;
			SDL_BlitSurface(surface, NULL, sdlWindow, &pos);
			SDL_Flip(sdlWindow);
    }else{

        const char * c = texte_a_afficher.c_str();
        SDL_Surface  *texte = NULL;
        TTF_Font *police = NULL;
         SDL_Color couleurNoire = {210, 210, 210};
        TTF_Init();
        police = TTF_OpenFont("Ubuntu-B.ttf", taille);
        texte = TTF_RenderText_Blended(police, c, couleurNoire);
        
		SDL_BlitSurface(texte, NULL, surface, &position); /* Blit du texte */
		SDL_Rect pos;
		pos.x = 0;
		pos.y = 0;
		SDL_BlitSurface(surface, NULL, sdlWindow, &pos);
        SDL_Flip(sdlWindow);
		
    }


}
