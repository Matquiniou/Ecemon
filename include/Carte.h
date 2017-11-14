#ifndef CARTE_H
#define CARTE_H

#include <iostream>


class Carte
{
    public:
        Carte();
        virtual ~Carte();

        std::string Getname() { return m_name; }
        void Setname(std::string val) { m_name = val; }
        std::string Getdescription() { return m_description; }
        void Setdescription(std::string val) { m_description = val; }

    protected:

    private:
        std::string m_name;
        std::string m_description;
};

#endif // CARTE_H
