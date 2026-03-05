#ifndef AVATAR_H_INCLUDED
#define AVATAR_H_INCLUDED
#include "Personnage.h"
#include "Ennemi.h"
#include "Image.h"
#include <string>


class Avatar{
private:
    Personnage _perso;

public:
    Avatar(const Image& img, int x, int y, int skin_x, int skin_y,Direction d);

    void dessiner() const;
    void allerDroite(const Niveau& niveau);
    void allerGauche(const Niveau& niveau);
    void allerHaut(const Niveau& niveau);
    void allerBas(const Niveau& niveau);
    int getX()const;
    int getY()const;
    bool touche(Ennemi e) const;
    void mettreAjourAnimation();
    Personnage getPerso() const;

};


#endif // AVATAR_H_INCLUDED
