#pragma once
#include "shape.h"
#include<iostream>
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
	void print(); //affiche des infos basiques (fonction pour le débugage.)
	string getinfos(); //retourne un string avec des infos basiques
	float perimetre(); 
	float surface();
	void addcote(float cote); 
	virtual ~carre(); //destructeur
	void setcolor(string color); //ajoute la couleur de la forme.
	void addtext(string chaine); //ajoute le texte contenu dans la forme
	string gettext(); //retourne le texte contenu dans le fichier
private:
	string color; //...
	string text;
	float cote;
};

