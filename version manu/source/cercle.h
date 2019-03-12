#pragma once
#include "shape.h"
#include<iostream>
#include<SDL.h>
using namespace std;
class cercle :
	public shape
{
public: //les fonctions sont les memes que pour le carre..
	    // voir la classe carre pour plus d'infos.
	string getidentite(); 
	string getcolor();
	void print();
	string getinfos();
	float perimetre();
	float surface();
	void addcote(float cote);
	cercle();
	void setcolor(string color) ;
	cercle(float radius, string color);
	cercle(const cercle& orig);
	virtual ~cercle();
	void addtext(string chaine);
	string gettext();
        SDL_Rect getposition();
        void setposition(SDL_Rect position);
private:
        SDL_Rect position;
	string color;
	string text;
	float radius;
};

