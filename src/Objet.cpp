#include "Objet.h"
#include "Dictionnaire.h"
#include "Moteur.h"
#include "Image.h"
#include <stdlib.h>

Objet::Objet(const Image& img, const string& n, const Dictionnaire& d, int x, int y)
{
    bool found;
    Tuile t;
    found = d.recherche(n,t);
    if (found)
    {
        _img=img;
        //_x=t.getX();
        _x=x;
        //_y=t.getY();
        _y=y;
        _t=t;
    }
    else
        throw invalid_argument("La nom de l'objet que vous cherchez n'existe pas");
}


void Objet::dessiner() const
{
    int sx=_t.getX()*TAILLE_CASE;
    int sy =_t.getY()*TAILLE_CASE;
    _img.dessiner(_x, _y, sx, sy, TAILLE_CASE, TAILLE_CASE);
}
int Objet::getX()const
{
    return _x;
}
int Objet::getY() const
{
    return _y;
}
const Tuile& Objet::getTuile() const
{
    return _t;
}

void Objet::cacher()
{
    _t.setPropriete("cache");
}
