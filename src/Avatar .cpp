#include "Personnage.h"
#include "Ennemi.h"
#include "Avatar.h"
#include "Moteur.h"
#include <stdlib.h>
using namespace std;

Avatar::Avatar(const Image& img, int x, int y, int skin_x, int skin_y,Direction d)
{
    _perso = Personnage(img, x, y, skin_x, skin_y, d);

}

void Avatar::dessiner() const
{
    _perso.dessiner();
}

void Avatar::allerDroite(const Niveau& niveau)
{
    _perso.regarderDroite();
    if (_perso.peutBougerVers(DROITE,niveau))
        _perso.deplacer(TAILLE_CASE,0);
}

void Avatar::allerGauche(const Niveau& niveau)
{
    _perso.regarderGauche();
    if (_perso.peutBougerVers(GAUCHE,niveau))
        _perso.deplacer(-TAILLE_CASE,0);
}
void Avatar::allerBas(const Niveau& niveau)
{
    _perso.regarderBas();
    if (_perso.peutBougerVers(BAS,niveau))
        _perso.deplacer(0,TAILLE_CASE);
}
void Avatar::allerHaut(const Niveau& niveau)
{
    _perso.regarderHaut();
    if (_perso.peutBougerVers(HAUT,niveau))
        _perso.deplacer(0,-TAILLE_CASE);
}


bool Avatar::touche(Ennemi e) const
{
    return (_perso.getX()==e.getX() && _perso.getY()== e.getY());
}

int Avatar::getX()const
{
    return _perso.getX();
}
int Avatar::getY()const
{
    return _perso.getY();
}

void Avatar::mettreAjourAnimation() {
    _perso.mettreAjourAnimation();
}

Personnage Avatar::getPerso() const{
    return _perso;
}
