#include "diagramme.h"
#include "carre.h"
#include "rectangle.h"
#include "losange.h"
#include "cercle.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

//ses fonctions sont assez complexes et ont prises 2 semaines pour etre develloper


using namespace std;

int trouvercouleur_formes(string a, shape* s) { //trouve la couleur du shape dans le fichier

	switch (a[0])
	{
	case 'n': //noir
		s->setcolor("noir");
		break;
	case 'r'://rouge
		s->setcolor("rouge");
		break;
	case 'b'://bleu
		s->setcolor("bleu");
		break;
	case 'v'://vert
		s->setcolor("vert");
		break;
	default:
		break;
	}

	return 0;
}
void lire_text(string contenu, shape* a) { //cr�� un shape pour lui associ� toutes les sp�cificit� contenues dans le fichier 
        using namespace std;
        char n = 'a';//****
	int i = 2;
	while (n != ';') {
		n = contenu[i];
		i++;
		if (i > 30) {
			cout << "erreur lecture";
		}
	}
	int longeur = contenu.size();
	string nouvellechaine = contenu.substr(i, longeur - i);
	trouvercouleur_formes(nouvellechaine, a); //trouver la couleur de la forme
        


	i = 0;
	n = nouvellechaine[i];

	while (n != ';') {
		n = nouvellechaine[i];
		i++;

	}

	longeur = nouvellechaine.size();
	nouvellechaine = nouvellechaine.substr(i, longeur- i); //100;100;text
        
        i = 0;
	n = nouvellechaine[i];

	while (n != ';') {
		n = nouvellechaine[i];
		i++;

	}
        
        
        longeur = nouvellechaine.size();
        string temporaire = nouvellechaine.substr(0,  i-1);
       
        
        int position1 ;
        stringstream convert(temporaire);
        convert >> position1;
	nouvellechaine = nouvellechaine.substr(i, longeur- i);
        
        i = 0;
	n = nouvellechaine[i];

	while (n != ';') {
		n = nouvellechaine[i];
		i++;

	}
        
        longeur = nouvellechaine.size();
        temporaire = nouvellechaine.substr(0,  i-1);
        int position2 ;
        stringstream convert1(temporaire);
        convert1 >> position2;
	nouvellechaine = nouvellechaine.substr(i, longeur- i);
        a->addtext(nouvellechaine);
        
        
        SDL_Rect pos;
        pos.x = position1;
        pos.y = position2;
        a->setposition(pos);     

}
int diagramme::getwidth()
{
	return width;
}
int diagramme::getheight()
{
	return height;
}

void diagramme::dessinerTrais(string contenu){
    using namespace std;
        char n = 'a';//****
	int i = 2;
	while (n != ';') {
		n = contenu[i];
		i++;
		if (i > 30) {
			cout << "erreur lecture";
		}
	}
	int longeur = contenu.size();
	string nouvellechaine = contenu.substr(i, longeur - i);
	
	i = 0;
	n = nouvellechaine[i];

	while (n != ';') {
		n = nouvellechaine[i];
		i++;

	}
        
        
	longeur = nouvellechaine.size();
	string temporaire = nouvellechaine.substr(0, i); 
        int position1 ;
        stringstream convert(temporaire);
        convert >> position1;
        
        longeur = contenu.size();
	nouvellechaine = nouvellechaine.substr(i, longeur - i);
        int position2 ;
        stringstream convert1(nouvellechaine);
        convert1 >> position2;
        
        SDL_Rect pos;
        pos.x = position1;
        pos.y = position2;
       //********************************************************
        
        i = 0;
	n = nouvellechaine[i];

	while (n != ';') {
		n = nouvellechaine[i];
		i++;

	}
        longeur = contenu.size();
	nouvellechaine = nouvellechaine.substr(i, longeur - i);
        int position3;
        int position4;
         i = 0;
	n = nouvellechaine[i];

	while (n != ';') {
		n = nouvellechaine[i];
		i++;

	}
        
        temporaire = nouvellechaine.substr(0, i-1); 
        stringstream convert3(temporaire);
        convert3 >> position3;        
        nouvellechaine = nouvellechaine.substr(i, longeur - i);
        stringstream convert4(nouvellechaine);
        convert4 >> position4;
        
        
        
        
        SDL_Rect position;
        position.x = position1;
        position.y = position2;
        
        gestionEcran->dessinerRectangle(position3, position4, position, "noir");
        
}
void diagramme::dessinerfleche(string contenu){
    using namespace std;
        char n = 'a';//****
	int i = 2;
	while (n != ';') {
		n = contenu[i];
		i++;
		if (i > 30) {
			cout << "erreur lecture";
		}
	}
	int longeur = contenu.size();
	string nouvellechaine = contenu.substr(i, longeur - i);
	
	i = 0;
	n = nouvellechaine[i];

	while (n != ';') {
		n = nouvellechaine[i];
		i++;

	}
        
        
	longeur = nouvellechaine.size();
	string temporaire = nouvellechaine.substr(0, i); 
        int position1 ;
        stringstream convert(temporaire);
        convert >> position1;
        
        longeur = contenu.size();
	nouvellechaine = nouvellechaine.substr(i, longeur - i);
        int position2 ;
        stringstream convert1(nouvellechaine);
        convert1 >> position2;
        
        SDL_Rect pos;
        pos.x = position1;
        pos.y = position2;
       //********************************************************
        
        i = 0;
	n = nouvellechaine[i];

	while (n != ';') {
		n = nouvellechaine[i];
		i++;

	}
        longeur = contenu.size();
		int position3;
		temporaire = nouvellechaine.substr(i, longeur - i);
		stringstream convert3(temporaire);
		convert3 >> position3;
        SDL_Rect position;
        position.x = position1;
        position.y = position2;
        
        gestionEcran->dessinerFleche(18, position3,position, "noir");
        
}
void diagramme::dessinertexte(string contenu) {
	using namespace std;
	char n = 'a';//****
	int i = 2;
	
	int longeur = contenu.size();
	string nouvellechaine = contenu.substr(i, longeur - i);

	i = 0;
	n = nouvellechaine[i];

	while (n != ';') {
		n = nouvellechaine[i];
		i++;

	}


	longeur = nouvellechaine.size();
	string temporaire = nouvellechaine.substr(0, i);
	int position1;
	stringstream convert(temporaire);
	convert >> position1;

	longeur = contenu.size();
	nouvellechaine = nouvellechaine.substr(i, longeur - i);
	int position2;
	stringstream convert1(nouvellechaine);
	convert1 >> position2;

	SDL_Rect pos;
	pos.x = position1;
	pos.y = position2;
	//********************************************************

	i = 0;
	n = nouvellechaine[i];

	while (n != ';') {
		n = nouvellechaine[i];
		i++;

	}
	
	longeur = contenu.size();
	string position3;
	temporaire = nouvellechaine.substr(i, longeur - i);
	stringstream convert3(temporaire);
	convert3 >> position3;
	SDL_Rect position;
	position.x = position1;
	position.y = position2;
	gestionEcran->ajouterText(15, position, position3);

}

void diagramme::recupere_shape()//fonction qui permet de lire le fichier et d'organiser la r�partition des elements 
{
     
	std::cout << "lecture fichier en cours.." << std::endl;
	ifstream fichier("list_of_shapes.txt");
	string contenu;
       
	while (!fichier.eof())
	{
           
		getline(fichier, contenu);
		if (contenu == "stop") { //aucunes autres m�thodes ne permets de s'arreter a fin du fichier sans faire d'erreurs...
			fichier.close();
                       
			gestionEcran->pause();
			return;
		}

		char test = contenu[0];
		switch (test)
		{
		case 'c':
			if (contenu[1] == 'a') { // cest un carre 
				
				carre *a = new carre();
				lire_text(contenu, a);
				dessiner_diagramme( a);
				break;
			}
			else {//cest un cercle
				cercle *a = new cercle();
				lire_text(contenu, a);
				
				dessiner_diagramme( a);
				break;
			}
			break;
		case 'l': //l'element losange est particulier, il permet d'indiquer au programme qu'on S'appr�te a avoir une condition
		{			
			
			losange *a = new losange();
			lire_text(contenu, a);
			dessiner_diagramme( a);
			

		}
		break;
		case 'r':
		{
			rectangle *a = new rectangle();
			lire_text(contenu, a);
			dessiner_diagramme(a);
			
			break;
		}
		case 'K':
		{
			dessinertexte(contenu);

			break;
		}
		break;
        case 't':
                   
            dessinerTrais(contenu);
            //gestionEcran->dessinerRectangle(5, 30, position2, "noir");
        break;
        case 'f':
                   
            dessinerfleche(contenu);
            //gestionEcran->dessinerRectangle(5, 30, position2, "noir");
        break;

		default:
			break;
		}


	}
	fichier.close();
                       
        gestionEcran->pause();
        return;
}
void diagramme::dessiner_diagramme( shape * s) //fonction finale qui permet de d'appeler les contructeurs d'elements 
{       
        SDL_Rect position =s->getposition();
        
	string type = s->getidentite();

	if (position.y + 115 > height) {
		gestionEcran->pause();
		return;
	}
	if (type == "carre") {

		gestionEcran->dessinerCarre(100, position, s->getcolor());
		SDL_Rect positionText;
		positionText.x = position.x + 10;
		positionText.y = position.y + 35;
		gestionEcran->ajouterText(15, positionText, s->gettext());
	}
	if (type == "rectangle") {
		gestionEcran->dessinerRectangle(100, 50, position, s->getcolor());
		SDL_Rect positionText;
		positionText.x = position.x + 8;
		positionText.y = position.y + 35;
		gestionEcran->ajouterText(15, positionText, s->gettext());
	}
	if (type == "cercle") {
		
		gestionEcran->dessinerCercle(50, position, s->getcolor());
		SDL_Rect positionText;
		positionText.x = position.x + 10;
		positionText.y = position.y + 35;
		gestionEcran->ajouterText(15, positionText, s->gettext());
	}
	if (type == "losange") { 

		gestionEcran->dessinerLosange(100, position, s->getcolor());
		SDL_Rect positionText;
		positionText.x = position.x + 19;
		positionText.y = position.y + 35;
		gestionEcran->ajouterText(15, positionText, s->gettext());
	}	
}

diagramme::diagramme()
{
	gestionEcran = new window();
	this->width = 1000;
	this->height = 700;
        
}

diagramme::diagramme(int width, int height)
{
	gestionEcran = new window(width, height);
	this->width = width;
	this->height = height;
              
}

diagramme::~diagramme()
{
	delete gestionEcran;
}
