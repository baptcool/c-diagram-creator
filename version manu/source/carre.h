#pragma once
#include "shape.h"
#include<iostream>
#include <SDL.h>
using namespace std;
class carre :
	public shape
{
public:

	carre();
	carre(float cote, string color); //construteur.. 
	carre(const carre& orig);


	string getidentite(); //permets de savoir de quelle typpe de shape il s'agit
	string getcolor(); //retourne la couleur
	void print(); //affiche des infos basiques (fonction pour le d�bugage.)
	string getinfos(); //retourne un string avec des infos basiques
	float perimetre(); 
	float surface();
	void addcote(float cote); 
	virtual ~carre(); //destructeur
	void setcolor(string color); //ajoute la couleur de la forme.
	void addtext(string chaine); //ajoute le texte contenu dans la forme
	string gettext(); //retourne le texte contenu dans le fichier
        SDL_Rect getposition();
        void setposition(SDL_Rect position);
private:
        SDL_Rect position;
	string color; //...
	string text;
	float cote;
};

