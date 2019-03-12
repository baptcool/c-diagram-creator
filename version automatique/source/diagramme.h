#include <vector>
#include "shape.h"
#include "window.h"

class diagramme //classe principal
{
private :
	int width;
	int height;
	window * gestionEcran; // attribut window qui permet de gérer l'affichage
	void dessiner_diagramme(SDL_Rect position, shape * s); //comme son nom l'indique
public:
	
	int getwidth();
	int getheight();
	
	
	
	void recupere_shape(); //récupére les shapes contenues dans le fichier.

	diagramme();
	diagramme(int width, int height);
	~diagramme();
};

