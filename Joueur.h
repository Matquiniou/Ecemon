#ifndef JOUEUR_H
#define JOUEUR_H

#include "Deck.h"
#include <vector>

class Joueur
{
    protected:
        int m_argent;
        vector<Carte> m_collection;
        vector<Decks> m_decks //Tableau de tous les decks
        Deck *m_selection;


    private:

    public:
        Joueur();
        virtual ~Joueur();

        int Getargent() { return m_argent; }
        void Setargent(int val) { m_argent = val; }
        Deck Get*m_selection() { return *m_selection; }
        void Set*m_selection(Deck val) { *m_selection = val; }

        void ajouterArgent(int nouveau);
        void acheterCarte(carte &nouvelle);
        void creerDeck(std::string nom);
        void selectionnerDeck(std::string nom);
        void gererJoueur();


        void ajouterCarte_Deck(carte &nouvelle); /*Va appeler la méthode Deck::ajouterCarte,
                                                 le deck modifié est celui pointé par m_selection*/

        void supprimerCarte_Deck(int n) //Va appeler la méthode supprimer carte de deck




};

#endif // JOUEUR_H
