#include <iostream>
using namespace std;
#include "rectangle.h"

string rectangle::getcolor()
{
	return color;
}

string rectangle::getidentite()
{
	return "rectangle";
}

void rectangle::print() {
	cout << endl << "je suis rectangle" << endl;
}
void rectangle::setcolor(string color)
{
	switch (color[0])
	{
	case 'n': //noir
		this->color = "noir";
		break;
	case 'r'://rouge
		this->color = "rouge";
		break;
	case 'b'://bleu
		this->color = "bleu";
		break;
	case 'v'://vert
		this->color = "vert";
		break;
	default:
		break;
	}
}
string rectangle::getinfos()
{
	string infos;
	infos = "rectangle";
	infos += ";";
	infos += color;
	infos += ";";
	infos += text;
	return infos;
}
void rectangle::addcote(float cote1, float cote2)
{
	this->cote1 = cote1;
	this->cote2 = cote2;
}
float rectangle::perimetre() {
	return cote2 * 2 + cote1 * 2;
}
float rectangle::surface() {
	return cote1*cote2;
}
rectangle::rectangle() {
	color = "noir";
	cote1 = 1;
	cote2 = 2;
}

rectangle::rectangle(const rectangle& orig) {
}

rectangle::~rectangle() {
}

void rectangle::addtext(string chaine)
{
	text = chaine;
}

string rectangle::gettext()
{
	return text;
}

