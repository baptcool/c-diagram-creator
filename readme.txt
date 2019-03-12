Rapport de projet SDL diagramme. Baptiste millot, cir 2.
Ce document contient des explications et des notes du projet SDL.
La version utilis�e de SDL est 1.2 .
Je vous invite � regarder les � screen-shots � dans la � rubrique exemples et tests � de ce dossier.

La classe principale est Diagramme, elle permet de g�rer des fonctions essentielles a la r�alisation d�un diagramme. Elle contient plusieurs attributs et m�thodes utiles comme recupere_shape() qui est la seule fonction appel�e dans le main.h. j�ai mis des commentaires si vous voulez jeter un coup d��il au programme. J�ai essay� d�optimiser mes fonctions sans pour autant les �loigner.
Il existe deux versions de mon projet, une version manuelle ou l�on indique dans un fichier la couleur, la position, le texte des formes dans un fichier.
La seconde version est automatique, c�est-�-dire que l�on n�a pas besoin de mettre la position des formes, la gestion de la position des formes, des traies et des fl�ches est prise en charge.
 
Voici une liste de fonctionnalit�s contenu pour les deux versions:
-lecture d�un fichier texte.
-gestion de 4 couleurs : noir, rouge, vert, bleu
-gestion de fl�ches (traies) entre les elements.
-gestion d�une ou plusieurs conditions. Mais pas deux conditions imbriqu�es pour la version automatique.
-gestion de plusieurs formes : carre, rectangle, cercle, losange(symbolise la condition pour la version automatique) .

Voici quelques indications pour la syntaxes de la version automatique du fichier ListOfShapes.txt :
//*******************
carre;rouge;phase voulu
losange;noir;condition ou autre phrase //le losange indique qu'il sagit d'une condition..
|                                      //ce symbole indique qu'on entre dans la condition
rectangle;rouge;blablabla              //ici, on indique la liste des formes quon veut dans la premiere branche
&                                      //indique qu'on mets la liste des formes dans la seconde branche
rectangle;vert;autre                   //liste formes secondes branches
rectangle;vert;reprise                 //fin de la condition, reprise 
$                                       //fin condition
cercle;noir;fin de l'histoire     //ainsi, on peut r�p�ter plusieurs fois ce sch�ma pour faire plusieurs stop                                  //obligatoire, cela permets d'arreter la lecture sans bugs
//*********************
Pour la version manuelle, voici la synthase :

carre;rouge;50;50;start everything
fleche;190;74;1 // on a le choix entre 3 fl�ches, 1, 2 ,3 selon le sens voulu
trais;150;74;40;2 // pour tracer des trais
// position.x ;position.y ;hauteur, largeur

K;467;210;oui
//affiche du texte a une position voulue

Merci.
