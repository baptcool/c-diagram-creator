#pragma once
#include<string>
#include "shape.h"
#include<iostream>
using namespace std;
class rectangle :
	public shape
{
public:

	string getcolor();
	string getidentite();
	void print();
	void setcolor(string color) ;
	string getinfos();
	void addcote(float cote1, float cote2);
	float perimetre();
	float surface();
	rectangle();
	rectangle(const rectangle& orig);
	virtual ~rectangle();
	void addtext(string chaine);
	string gettext();
private:
	string color;
	string text;
	float cote1;
	float cote2;
};

