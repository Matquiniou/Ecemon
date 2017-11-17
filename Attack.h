#ifndef ATTACK_H
#define ATTACK_H

#include <iostream>
class Attack
{
    public:
        Attack();
        virtual ~Attack();

        std::string Getname() { return m_name; }
        void Setname(std::string val) { m_name = val; }
        int GetHP() { return m_HP; }
        void SetHP(int val) { m_HP = val; }

    protected:

    private:
        std::string m_name;
        int m_HP;
};

#endif // ATTACK_H
