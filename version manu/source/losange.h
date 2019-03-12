#pragma once
#include "shape.h"
#include<iostream>
#include<SDL.h>
class losange:
	public shape
{
public://les fonctions sont les memes que pour le carre..
	    // voir la classe carre pour plus d'infos.

	losange();
	virtual ~losange();
	losange(float cote, string color);
	losange(const losange& orig);


	string getidentite();
	string getcolor();
	void print();
	string getinfos();
	float perimetre();
	float surface();
	void addcote(float cote);

	void setcolor(string color);
	void addtext(string chaine);
	string gettext();
        SDL_Rect getposition();
        void setposition(SDL_Rect position);
private:
        SDL_Rect position;
	string color;
	string text;
	float cote;

};

