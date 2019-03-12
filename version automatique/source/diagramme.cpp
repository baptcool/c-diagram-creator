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
	trouvercouleur_formes(nouvellechaine, a);



	i = 0;
	n = nouvellechaine[i];

	while (n != ';') {
		n = nouvellechaine[i];
		i++;

	}

	longeur = nouvellechaine.size();
	nouvellechaine = nouvellechaine.substr(i, longeur - i);
	a->addtext(nouvellechaine);

}
int diagramme::getwidth()
{
	return width;
}
int diagramme::getheight()
{
	return height;
}
/*

*/



//fonction tr�s longue qui permet d'associer une place libre a un element a afficher.. idem pour les traies a afficher
void Disposition_element_losange(SDL_Rect* position,  int disposition_condition, int pasy, int pasx, window *gestionEcran, int height, int width, int& nombres_lignes, int& nombres_formes, int& etage_condition, int& etage_condition2, int& sauter_ligne) {
	
	if (disposition_condition == 0) {
		
		//*************** pour bien plac� les formes..
		if (nombres_lignes % 2 == 0) {

			if (position->x +  pasx+100 >= width) {
				nombres_lignes++;
				if (sauter_ligne > 0) {
					position->y += (sauter_ligne+1)*pasy;
				}
				else {
					position->y += pasy;
				}
				
				nombres_formes = 0;
				SDL_Rect position2;
				position2.x = position->x +50;
				position2.y = position->y -55;
				gestionEcran->dessinerRectangle(2, 30, position2, "noir");
				SDL_Rect positionT;
				positionT.x = position2.x;
				positionT.y = position2.y  + 25;
				gestionEcran->dessinerFleche(18, 2, positionT, "noir");
			}
			else {
				if (nombres_formes != 0) {
					SDL_Rect position2;
					position2.x = position->x + 105;
					position2.y = position->y + 25;
					gestionEcran->dessinerRectangle(40, 2, position2, "noir");

					SDL_Rect positionT;
					positionT.x = position2.x + 30;
					positionT.y = position2.y ;
					gestionEcran->dessinerFleche(18, 1, positionT, "noir");


					position->x += pasx;


				}
				
			}
		}
		else {

			if (position->x - pasx < 0) {
				nombres_lignes++;
				position->y += pasy;
				position->x = 50;
				nombres_formes = 0;
				SDL_Rect position2;
				position2.x = position->x + 50;
				position2.y = position->y - 55;
				gestionEcran->dessinerRectangle(2, 30, position2, "noir");

				SDL_Rect positionT;
				positionT.x = position2.x;
				positionT.y = position2.y + 25;
				gestionEcran->dessinerFleche(18, 2, positionT, "noir");



			}
			else {
				
				SDL_Rect position2;
				position2.x = position->x - 45;
				position2.y = position->y + 25;
				gestionEcran->dessinerRectangle(40, 2, position2, "noir");

				SDL_Rect positionT;
				positionT.x = position2.x -8;
				positionT.y = position2.y +27;
				gestionEcran->dessinerFleche(18, 3, positionT, "noir");




				position->x -= pasx;


			}

		}
		
		nombres_formes++;
	}

	if (disposition_condition == 1) { //si condition valide
		if (position->x - pasx > 0) {

			SDL_Rect position2;
			position2.x = position->x - 47;
			position2.y = position->y + 20;
			gestionEcran->dessinerRectangle(40, 2, position2, "noir");

			SDL_Rect positionT;
			positionT.x = position2.x -5;
			positionT.y = position2.y +27;
			gestionEcran->dessinerFleche(18, 3, positionT, "noir");


			position->x -= pasx;
		}
		else {
			if (position->y + pasy < height) {
				SDL_Rect position2;
				position2.x = position->x + 50;
				position2.y = position->y + 80;
				gestionEcran->dessinerRectangle(2, 20, position2, "noir");
				
				SDL_Rect positionT;
				positionT.x = position2.x ;
				positionT.y = position2.y+20 ;
				gestionEcran->dessinerFleche(18, 2, positionT, "noir");

				

				position->y += pasy;
				etage_condition++;
			}

		}
	}
	if (disposition_condition == 2) { //si condition non valide
		etage_condition2++;
		
		position->y += pasy;
		SDL_Rect position2;
		position2.x = position->x + 50;
		position2.y = position->y - 55;
		gestionEcran->dessinerRectangle(2, 30, position2, "noir");
		SDL_Rect positionT;
		positionT.x = position2.x;
		positionT.y = position2.y+27;
		gestionEcran->dessinerFleche(18, 2, positionT, "noir");
	}
	
}






void diagramme::recupere_shape()//fonction qui permet de lire le fichier et d'organiser la r�partition des elements 
{
	std::cout << "lecture fichier en cours.." << std::endl;
	ifstream fichier("list_of_shapes.txt");
	string contenu;
	int etage_condition = 0;
	int etage_condition2 = 0;
	int disposition_condition = 0;
	int positionAtLosange = 0;
	int nombres_lignes = 0;
	int nombres_formes= 0;
	int sauter_ligne = 0;
	SDL_Rect position;
	SDL_Rect position_temporaire;
	int pasx = 150;
	int pasy = 130;
	position.x = 50;
	position.y = 50;
	SDL_Rect previus_position = position;
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
				Disposition_element_losange(&position,disposition_condition,pasy,pasx, gestionEcran, height,width,nombres_lignes,nombres_formes, etage_condition, etage_condition2, sauter_ligne);
				carre *a = new carre();
				lire_text(contenu, a);
				dessiner_diagramme(position, a);
				break;
			}
			else {//cest un cercle
				Disposition_element_losange(&position, disposition_condition, pasy, pasx, gestionEcran, height, width, nombres_lignes, nombres_formes, etage_condition, etage_condition2, sauter_ligne);
				cercle *a = new cercle();
				lire_text(contenu, a);
				
				dessiner_diagramme(position, a);
				break;
			}
			break;
		case 'l': //l'element losange est particulier, il permet d'indiquer au programme qu'on S'appr�te a avoir une condition
		{
			Disposition_element_losange(&position, disposition_condition, pasy, pasx, gestionEcran, height, width, nombres_lignes, nombres_formes, etage_condition, etage_condition2, sauter_ligne);
			
			
			SDL_Rect position2;
			if (nombres_lignes % 2 == 0) {
				position2.x = position.x - 40;
				position2.y = position.y + 25;
				gestionEcran->dessinerRectangle(90, 2, position2, "noir");
				
			}
			else {
				position2.x = position.x + 50;
				position2.y = position.y + 25;
				gestionEcran->dessinerRectangle(90, 2, position2, "noir");
			}
			position2.x = position.x - 40;
			position2.x += 90 ;
			
			gestionEcran->dessinerRectangle(2, 70, position2, "noir");
			
			positionAtLosange = nombres_formes;
			losange *a = new losange();
			lire_text(contenu, a);
			position.y += pasy;
			dessiner_diagramme(position, a);
			disposition_condition = 5;
			previus_position = position;

			SDL_Rect positionT;
			positionT.x = position.x -35;
			positionT.y = position.y +25;
			gestionEcran->ajouterText(15, positionT, "oui");
			positionT.x = position.x + 60;
			positionT.y = position.y + 100;
			gestionEcran->ajouterText(15, positionT, "non");
		}
		break;
		case 'r':
		{
			Disposition_element_losange(&position, disposition_condition, pasy, pasx, gestionEcran, height, width, nombres_lignes, nombres_formes, etage_condition, etage_condition2, sauter_ligne);
			rectangle *a = new rectangle();
			lire_text(contenu, a);
			dessiner_diagramme(position, a);
			
			break;
		}
		break;
		case '|': // la condition commence
		{
			disposition_condition = 1;
			break;
		}
		break;
		case '&': // a la moiti� de la condition
		{
			position_temporaire = position;
			position = previus_position;
			
			disposition_condition = 2;
			break;
		}
		break;
		case '$': // fin de condition
		{
			if (etage_condition > etage_condition2) {
				
				SDL_Rect position2;
				position2.x = position.x +50 ;
				position2.y = position.y +80;
				gestionEcran->dessinerRectangle( 2 , 120*(etage_condition-etage_condition2) - 43 , position2, "noir");
				position2.y += 25 + 50 * (etage_condition - etage_condition2);
				position_temporaire.y += 25;
				position_temporaire.x += 100 + 50 ;
				gestionEcran->dessinerRectangle(  position.x  - position_temporaire.x + 50 , 2, position_temporaire, "noir");
				
				SDL_Rect positionT;
				positionT.x = position2.x - (position.x - position_temporaire.x)/2;
				positionT.y = position_temporaire.y;
				gestionEcran->dessinerFleche(18, 1, positionT, "noir");
				
				sauter_ligne = etage_condition - etage_condition2;
			}
			else if(etage_condition < etage_condition2){
				SDL_Rect position3 = position_temporaire;
				SDL_Rect position2;
				position2.x = position3.x + 50;
				position2.y = position3.y + 25 + pasy*(etage_condition2 - etage_condition);
				gestionEcran->dessinerRectangle(previus_position.x - position3.x - 100, 2, position2, "noir");
				
				SDL_Rect positionT;
				positionT.x = position2.x+ previus_position.x - position3.x - 100;
				positionT.y = position2.y ;
				gestionEcran->dessinerFleche(18, 1, positionT, "noir");
				
				position2.y += 25;
				position2.y -= 100 * (etage_condition2 - etage_condition);
				gestionEcran->dessinerRectangle(2, 100 * (etage_condition2 - etage_condition) -25, position2, "noir");
				
			}
			if (etage_condition == etage_condition2) {
				SDL_Rect position3 = position_temporaire;
				SDL_Rect position2;
				position2.x = position3.x + 120;
				position2.y = position3.y + 25;
				gestionEcran->dessinerRectangle((previus_position.x - position3.x - pasx), 2, position2, "noir");
				SDL_Rect positionT;
				positionT.x = position2.x+ (previus_position.x - position3.x - pasx);
				positionT.y = position2.y ;
				gestionEcran->dessinerFleche(18, 1, positionT, "noir");
			}
			

			
			nombres_lignes = 0;
			etage_condition = 0;
			etage_condition2 = 0;
			disposition_condition = 0;
			positionAtLosange = 0;
			disposition_condition = 0;
			break;
		}
		break;
		default:
			break;
		}





	
	
		
		

	}
	fichier.close();
                       
        gestionEcran->pause();
        return;
}
void diagramme::dessiner_diagramme(SDL_Rect position, shape * s) //fonction finale qui permet de d'appeler les contructeurs d'elements 
{
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
	gestionEcran = new window(1000,700);
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
