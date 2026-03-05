#include "Ennemi.h"
#include "Personnage.h"
#include "Moteur.h"

Ennemi::Ennemi(const Image& img, int x, int y, int skin_x, int skin_y,Direction d)
{
    _perso = Personnage(img, x, y, skin_x, skin_y, d);
}

void Ennemi::dessiner() const
{
    _perso.dessiner();
}


void Ennemi::avancer(const Niveau& niveau)
{
    Direction d=(Direction)(_perso.getDirection());
    d =(Direction)(rand() % 4);
    cout<<"direction d"<<d<<endl;
    while(!(_perso.peutBougerVers(d,niveau))){
        d =(Direction)(rand() % 4);
    }

    switch (d)
    {
    case (DROITE):
        _perso.regarderDroite();
        _perso.deplacer(TAILLE_CASE,0);
        break;
    case (GAUCHE):
        _perso.regarderGauche();
        _perso.deplacer(-TAILLE_CASE,0);
        break;
    case (BAS):
        _perso.regarderBas();
        _perso.deplacer(0,TAILLE_CASE);
        break;
    case (HAUT):
        _perso.regarderHaut();
        _perso.deplacer(0,-TAILLE_CASE);
        break;
    }


}

int Ennemi::getX() const
{
    int x= _perso.getX();
    return x;
}

int Ennemi::getY() const
{
    int y= _perso.getY();
    return y;
}

Personnage Ennemi::getPerso() const{
    return _perso;
}

void Ennemi::mettreAjourAnimation() {
    _perso.mettreAjourAnimation();
}
