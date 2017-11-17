#include "Carte.h"
#include <iostream>

using namespace std;

Carte::Carte(string name, string description): m_name(name), m_description(description)
{
    //ctor
}
void Carte::display()
{
    cout << "Nom de la carte: " << Carte::Getname()<< endl
    <<"Type de la carte: " << Carte::Getdescription() << endl;
}
Carte::~Carte()
{
    //dtor
}
