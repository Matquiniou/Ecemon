#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(string nom1): m_vie(30), m_jouer(false), m_fin(false), m_tourPerso(true), m_nom(nom1)
{

}
void Player::modifVie(int degat)
{
    m_vie-=degat; // On enl�ve � la vie les pointts de d�g�ts
}
bool Player::verificationVie(bool valeur)
{
    if (valeur)
        return true;
    else
    {
        return Getmort();
    }
}

bool Player::SetTourperso(bool modif)
{
    m_tourPerso=modif;
}
bool Player::Setjouer(bool modif)
{
    m_jouer=modif;
}
bool Player::Setfin(bool valeur)
{
    m_fin=verificationVie(valeur);
}
string Player::Setnom(string nom)
    {
        m_nom=nom;
    }
Player::~Player()
{
    //dtor
}
