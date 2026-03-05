#include "Tuile.h"
#include "Dictionnaire.h"
#include <fstream>
#include <iostream>
using namespace std;

Dictionnaire::Dictionnaire(const string& nomFichier)
{
    ifstream input;
    input.open(nomFichier);

    if (!(input.is_open()))
        throw runtime_error("Impossible d'ouvrir le fichier");

    int nb;
    input >> nb;  // nombre de tuiles

    for (int i = 0; i < nb; i++)
    {
        string nom, propriete;
        int x, y;

        input >> nom >> x >> y >> propriete;

        _v.push_back(Tuile(nom, x, y, propriete));
    }
}
void Dictionnaire::afficher() const
{
    for(int i=0; i<_v.size(); i++)
    {
        _v[i].afficher();
    }
}



bool Dictionnaire::recherche(const string & ch,Tuile &t) const
{
    int deb,fin,millieu,ind;
    bool trouve;
    deb=0;
    fin=_v.size()-1;
    ind=-1;
    trouve=false;
    while(!trouve && deb<=fin)
    {
        millieu=(deb+fin)/2;
        trouve=(_v[millieu].getName()==ch);
        if(trouve)
        {
            ind=millieu;
            t=_v[millieu];
        }
        else
        {
            if(_v[millieu].getName()>ch)
            {
                fin=millieu-1;
            }
            else
            {
                deb=millieu+1;
            }
        }
    }

    return (trouve);
}
