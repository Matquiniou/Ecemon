#ifndef PLAYER_H
#define PLAYER_H
#include <string>


class Player
{

public:
    Player(std::string nom1);
    virtual ~Player();

    void modifVie(int degat); // Modifie la vie du joueur
    bool verificationVie(bool valeur); // m�thode d�crite dans l�ACD



    bool SetTourperso(bool modif); // Dis si c�est au tour du joueur ou nom
    bool Setjouer(bool modif); // Pour emp�cher le joueur d�effectuer deux tirages cons�cutif
    bool Setfin(bool valeur); // on attribue � m_fin la valeur de verificationVie();
    std::string Setnom(std::string nom);

    int Getvie()
    {
        return m_vie;
    }
    bool Getjouer() // Pour savoir si le joueur a d�j� jouer une fois dans son tour (pour ne pas le r�p�ter)
    {
        return m_jouer;
    }
    bool Getfin()
    {
        return m_fin;
    }
    bool Getmort()
    {
        if (Getvie()>0)
            return false;
        else
            return true;
    }
    bool GettourPerso()
    {
        return m_tourPerso;
    }
    std::string Getnom()
    {
        return m_nom;
    }
private:
    int m_vie;
    bool m_jouer;
    bool m_fin;
    bool m_tourPerso;
    std::string m_nom;
};

#endif // PLAYER_H
