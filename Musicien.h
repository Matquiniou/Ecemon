#ifndef MUSICIEN_H
#define MUSICIEN_H

#include "Carte.h"
#include "Attack.h"
#include <vector>
#include <iostream>

class Musicien : public Carte
{
    public:
        Musicien(std::string name, std::string description);
        virtual ~Musicien();

        virtual int GetType(){return 1;}
        int GetLP() { return m_LP; }
        int GetHP(); // On retournera la valeur approprié
        void SetLP(int val) { m_LP = val; }
        void modifvie(int val){m_LP-=val;} // On enlève de la vie au musicien


    protected:

    private:
        int m_LP;
        std::vector<Attack> m_attacks;
};

#endif // MUSICIEN_H
