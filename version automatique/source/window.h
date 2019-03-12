#pragma once
#include<SDL.h>
#include<string>
#include <iostream>
#include<SDL_ttf.h>
class window
{
private://cette classe permet de g�rer tout les fonctions SDL 
	

	int width;
	int height;
	/*SDL*/
	SDL_Surface  *texte ;
	SDL_Surface * surface;
	SDL_Surface* sdlWindow;
	void detruire();
	void setPixel(int x, int y, Uint32 pixel); //fonction universelle pour changer l'etat d'un pixel

public:
	void pause(); //mettre en pause le programme (en attente d'une action de la part de l'utilisateur)
	
				  
				  //******************************  fonction importantes..
	void dessinerRectangle(int hauteur, int largeur,  SDL_Rect position, std::string couleur);
	void dessinerCarre(  int cote, SDL_Rect position, std::string couleur);
	void dessinerCercle( int radius, SDL_Rect position, std::string couleur);
	void dessinerLosange( int longeur1, SDL_Rect position, std::string couleur);
	void dessinerFleche(int longeur1, int type, SDL_Rect position, std::string couleur);
	//******************************
    void ajouterText(int taille,SDL_Rect position, std::string texte_a_afficher ); //ajoute du texte


	int getWidth();
	int getHeight();


	//******
	window(int width, int height);
	window();
	~window();
	//**********
};

