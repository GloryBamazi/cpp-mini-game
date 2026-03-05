#include <fstream>
#include <iostream>
#include "Dictionnaire.h"
#include "Niveau.h"
using namespace std;


Niveau::Niveau(const Image & img,const string & nomFichier, const Dictionnaire& d)
{
    ifstream input;
    input.open(nomFichier);
    _bonus=0;
    if (!(input.is_open()))
        throw runtime_error("Impossible d'ouvrir le fichier");

    int nb;
    input >> nb;  // nombre de tuiles
    for (int i = 0; i < nb; i++)
    {
        string nom;
        int cx, cy;              // coordonnées en CASES dans le fichier
        input >> nom >> cx >> cy;

        int x = cx * TAILLE_CASE; // conversion en pixels
        int y = cy * TAILLE_CASE;

        _vo.push_back(Objet(img, nom, d, x, y));
        if(_vo[i].getTuile().getPropriete()=="bonus")
        {
            _bonus++;
        }
    }
}
void Niveau::dessiner() const
{
    for(int i=0; i<_vo.size(); i++)
    {
        if(_vo[i].getTuile().getPropriete()!="cache")
        {
            _vo[i].dessiner();
        }
    }
}

bool Niveau::caseEstLibre(int x,int y) const
{
    bool libre=true;
    int i=0;
    while(libre && i<_vo.size())
    {
        if(_vo[i].getTuile().getPropriete()=="solide")
        {
            if(_vo[i].getX()==x && _vo[i].getY()==y)
            {
                libre=false;
            }
        }
        i++;
    }
    return libre;
}
int Niveau::getBonus() const
{
    return _bonus;
}

void Niveau::testerBonusEtPrendre(int x,int y)
{
    int ind=indiceObjet(x,y,"bonus");
    if(ind!=-1)
    {
        _bonus--;
        _vo[ind].cacher();
    }
}

int Niveau::indiceObjet(int x,int y, const string &prop)
{
    int ind=-1;
    int i=0;
    while(ind==-1&&i<_vo.size())
    {
        if(_vo[i].getTuile().getPropriete()==prop)
        {
            if(_vo[i].getX()==x && _vo[i].getY()==y)
            {
                ind= i;
            }
            else
            {
                i++;
            }
        }
        else
        {
            i++;
        }
    }
    return ind;
}
bool Niveau::gagne()
{
    return _bonus==0;
}
