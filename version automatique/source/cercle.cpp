
#include "cercle.h"
#include "carre.h"
#include <iostream>
#include<string>
using namespace std;

float cercle::perimetre() {
	return 2 * 3.14159*radius;
}
float cercle::surface() {
	return 3.14159*(radius*radius);
}
void cercle::addcote(float rad)
{
	this->radius = rad;
}
string cercle::getidentite()
{
	return "cercle";
}
string cercle::getcolor()
{
	return color;
}
void cercle::print() {
	cout << endl << "je suis un fucking cercle" << endl;
}
string cercle::getinfos()
{
	string infos;
	infos = "cercle";
	infos += ";";
	infos += color;
	infos += ";";
	infos += text;
	return infos;
}
cercle::cercle() {
	color = "noir";
	radius = 1;
}

void cercle::setcolor(string color)
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

cercle::cercle(float radius, string color)
{
}

cercle::cercle(const cercle& orig) {
}

cercle::~cercle() {
}

void cercle::addtext(string chaine)
{
	text = chaine;
}

string cercle::gettext()
{
	return text;
}
