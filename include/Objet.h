#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED
#include "Tuile.h"
#include "Dictionnaire.h"
#include "Image.h"

class Objet{

private:
    Image _img;
    int _x, _y;
    Tuile _t;

public:
    Objet(const Image& img, const string& n, const Dictionnaire& d, int x, int y);
    void dessiner() const;
    int getX() const;
    int getY() const;
    const Tuile& getTuile() const;
    void cacher();
};

#endif // OBJET_H_INCLUDED
