#ifndef JOUEUR_H
#define JOUEUR_H

#include "Deck.h"
#include "Carte.h"
#include <vector>
#include "Deck.h"

class Joueur
{
    protected:
        int m_argent;
        std::vector<Carte> m_collection;
        std::vector<Deck> m_decks; //Tableau de tous les decks
        Deck *m_selection;


    private:

    public:
        Joueur();
        virtual ~Joueur();

        int Getargent() { return m_argent; }
        void Setargent(int val) { m_argent = val; }
        Deck *Getselection() { return m_selection; }
        void Setselection(Deck *val) { m_selection = val; }

        void ajouterArgent(int nouveau);
        void acheterCarte(Carte &nouvelle);
        void creerDeck(std::string nom);
        void selectionnerDeck(std::string nom);
        void gererJoueur();


        void ajouterCarte_Deck(Carte &nouvelle); /*Va appeler la m�thode Deck::ajouterCarte,
                                                 le deck modifi� est celui point� par m_selection*/

        void supprimerCarte_Deck(int n); //Va appeler la m�thode supprimer carte de deck




};

#endif // JOUEUR_H
