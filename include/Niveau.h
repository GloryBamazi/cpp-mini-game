#ifndef NIVEAU_H_INCLUDED
#define NIVEAU_H_INCLUDED
#include <vector>
#include "Objet.h"
#include "Image.h"
#include "Dictionnaire.h"
class Niveau{
private:
    vector <Objet> _vo;
    int _bonus;
public:
    Niveau(const Image &,const string &,const Dictionnaire& d);
    void dessiner() const;
    bool caseEstLibre(int x,int y)const;
    int getBonus() const;
    void testerBonusEtPrendre(int,int);
    int indiceObjet(int x,int y, const string &prop);
    bool gagne();
};

#endif // NIVEAU_H_INCLUDED
