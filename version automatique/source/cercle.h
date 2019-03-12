#pragma once
#include "shape.h"
#include<iostream>
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
private:
	string color;
	string text;
	float radius;
};

