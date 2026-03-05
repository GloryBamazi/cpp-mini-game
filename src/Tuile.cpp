#include "Tuile.h"
#include <stdlib.h>
#include <iostream>
using namespace std;


Tuile::Tuile(const string& n, int skin_x, int skin_y, const string& p)
{
    _name=n;
    _skin_x=skin_x;
    _skin_y=skin_y;
    _property=p;
}

Tuile::Tuile()
{
    _name=" ";
    _skin_x=0;
    _skin_y=0;
    _property=" ";
}


void Tuile::afficher() const
{
    cout<<_name<<": "<<endl;
    cout<<"x= "<<_skin_x<<", ";
    cout<<"y= "<<_skin_y<<", ";
    cout<<_property<<". "<<endl;
}
string Tuile::getName()const
{
    return _name;
}


int Tuile::getX()const
{
    return _skin_x;
}
int Tuile::getY()const
{
    return _skin_y;
}
string Tuile::getPropriete() const
{
    return _property;
}

void Tuile::setPropriete(const string& p)
{
    _property=p;
}
