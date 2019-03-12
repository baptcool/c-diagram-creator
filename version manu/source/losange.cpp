#include <iostream>
using namespace std;
#include "losange.h"
#include<string>

string losange::getidentite()
{
	return "losange";
}

string losange::getcolor()
{
	return color;
}

void losange::print() {
	cout << endl << "je suis losange" << endl;
}

string losange::getinfos()
{
	string infos;
	infos = "losange";
	infos += ";";
	infos += color;
	infos += ";";
	infos += text;
	return infos;
}

float losange::surface() {
	return cote*cote;
}
void losange::addcote(float cote)
{
	this->cote = cote;

}
float losange::perimetre() {
	return 4 * cote;
}
losange::losange() {
	cote = 1;
	color = "noir";
}

losange::losange(float cote, string color)
{
	this->cote = cote;
	this->color = color;
}

losange::losange(const losange& orig) {


}

losange::~losange() {
}

void losange::setcolor(string colorchoisit)
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

void losange::addtext(string chaine)
{
	text = chaine;
}

string losange::gettext()
{
	return text;
}

 SDL_Rect losange::getposition(){
     return position;
 
 }
void losange::setposition(SDL_Rect position){
    this->position.x = position.x;
    this->position.y = position.y;
}