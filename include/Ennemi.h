#ifndef ENNEMI_H_INCLUDED
#define ENNEMI_H_INCLUDED
#include "Personnage.h"
#include "Image.h"
#include <string>

class Ennemi{
private:
    Personnage _perso;

public:
    Ennemi(const Image& img, int x, int y, int skin_x, int skin_y,Direction d);

    void dessiner() const;
    void avancer(const Niveau& niveau   );
    int getX()const;
    int getY()const;
    Personnage getPerso() const;
    void mettreAjourAnimation();
};

#endif // ENNEMI_H_INCLUDED
