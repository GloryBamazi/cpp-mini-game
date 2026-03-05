#ifndef TUILE_H_INCLUDED
#define TUILE_H_INCLUDED
#include <string>
using namespace std;

class Tuile
{
private:
    string _name;
    int _skin_x,_skin_y;
    string _property;

public:
    Tuile();
    Tuile(const string& n, int skin_x, int skin_y, const string& p);
    string getName() const;
    void afficher() const;
    int getX() const;
    int getY() const;
    string getPropriete() const;
    void setPropriete();
    void setPropriete(const string& p);


};

#endif // TUILE_H_INCLUDED
