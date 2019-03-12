#include <vector>
#include "shape.h"
#include "window.h"

class diagramme //classe principal
{
private :
	int width;
	int height;
        void dessinerTrais(string contenu);
        void dessinerfleche(string contenu);
        void dessiner_diagramme( shape * s); //comme son nom l'indique
        window * gestionEcran; // attribut window qui permet de g�rer l'affichage
		void dessinertexte(string contenu);
public:
	
	int getwidth();
	int getheight();
	void recupere_shape(); //r�cup�re les shapes contenues dans le fichier.
           
	diagramme();
	diagramme(int width, int height);
	~diagramme();
};

