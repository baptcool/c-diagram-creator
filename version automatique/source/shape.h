#pragma once
#include<string>
#include<iostream>
using namespace std;
class shape
{
public: //la classe mere si dessous est une classe pure virtuel, c'est tres pratique! 
	shape();
	virtual void setcolor(string color) = 0;
	virtual string getidentite() = 0;
	virtual string getcolor() = 0;
	virtual void print() = 0;
	virtual string gettext() = 0;
	virtual float perimetre() = 0;
	virtual float surface() = 0;
	virtual string getinfos() = 0;
	shape(const shape& orig);
	virtual ~shape();

	virtual void addtext(string chaine) = 0;
};

