#include <iostream>
using namespace std;
#include "carre.h"
#include<string>

string carre::getidentite()
{
	return "carre";
}

string carre::getcolor()
{
	return color;
}

void carre::print() {
	cout << endl << "je suis carre" << endl;
}

string carre::getinfos()
{
	string infos;
	infos = "carre";
	infos += ";";
	infos += color;
	infos += ";";
	infos += text;
	return infos;
}

float carre::surface() {
	return cote*cote;
}
void carre::addcote(float cote)
{
	this->cote = cote;

}
float carre::perimetre() {
	return 4 * cote;
}
carre::carre() {
	cote = 1;
	color = "noir";
}

carre::carre(float cote, string color)
{
	this->cote = cote;
	this->color = color;
}

carre::carre(const carre& orig) {


}

carre::~carre() {
}

void carre::setcolor(string colorchoisit)
{

	switch (colorchoisit[0])
	{
	case 'n': //noir
		color = "noir";
		break;
	case 'r'://rouge
		color = "rouge";
		break;
	case 'b'://bleu
		color = "bleu";
		break;
	case 'v'://vert
		color = "vert";
		break;
	default:
		break;
	}

}

void carre::addtext(string chaine)
{
	text = chaine;
}

string carre::gettext()
{
	return text;
}

 SDL_Rect carre::getposition(){
     return position;
 
 }
void carre::setposition(SDL_Rect position){
    this->position.x = position.x;
    this->position.y = position.y;
}
