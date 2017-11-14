#ifndef DECK_H
#define DECK_H


class Deck
{
    public:
        Deck();
        virtual ~Deck();

        std::string Getnom() { return m_nom; }
        void Setnom(std::string val) { m_nom = val; }
        bool Getjouable() { return m_jouable; }
        void Setjouable(bool val) { m_jouable = val; }

    protected:

    private:
        std::string m_nom;
        bool m_jouable;
};

#endif // DECK_H
