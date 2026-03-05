#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED
#include "Image.h"
#include "Niveau.h"
#include <string>
using namespace std;
const int fondX=160;
const int fondY=128;

enum Direction { GAUCHE, DROITE, HAUT, BAS};
class Personnage{
    Image _img;
    int _y, _x;
    string _nom;
    int _x_selection;
    int _y_selection;
    int _skin_x;
    int _skin_y;
    Direction _direction;
    int _etapeAnimation; // 0, 1, 2 ou 3

public:
    Personnage();
    Personnage(const Image& img, int x, int y, int skinx, int skiny,Direction d);
    void dessiner()const;
    void regarderDroite();
    void regarderGauche();
    void regarderHaut();
    void regarderBas();
    void mettreAjourAnimation();

    void deplacer(int dx, int dy);

    bool peutBougerVers(Direction d,const Niveau& niveau) const;
    Direction getDirection() const;
    int getX() const;
    int getY() const;

    void inverserDirection();
};

#endif // PERSONNAGE_H_INCLUDED
