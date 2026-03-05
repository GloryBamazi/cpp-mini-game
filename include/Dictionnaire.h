#ifndef DICTIONNAIRE_H_INCLUDED
#define DICTIONNAIRE_H_INCLUDED
#include "Tuile.h"
#include <vector>
#include <string>

class Dictionnaire{
private:
    vector<Tuile> _v;
public:
    Dictionnaire(const string& nomFichier);
    void afficher() const;
    bool recherche(const string &,Tuile &) const;
    /// Bianary search, on a utilise la recherche Dichomique
};

#endif // DICTIONNAIRE_H_INCLUDED
