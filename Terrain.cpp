#include "Terrain.h"
#include <iostream>

using namespace std;

Terrain::Terrain():m_joueur(NULL), m_musicienActif(NULL) // Il n'y a pas de musicien posé initialement
{
    string nom1;
    nom1="Mozart";
    m_joueur= new Player(nom1);
    //ctor
}
Terrain::~Terrain()
{
    delete m_joueur;
    //dtor
}
void Terrain::remplirPioche(Carte* unecarte) /// Méthode pour tester mon code, du bullllshit !
{
    m_pioche.push_back(unecarte);
}
void Terrain::DisplayTerrain()const
{
    /// Ca va planter car m_musicienActif est NULL
    /// Ce qui n'arrivera pas puisque si il n'y a plus de carte musiciens, le jeu s'arrête.

    cout << "Nom du joueur: " << m_joueur->Getnom() << endl;
    cout << "Vie du joueur: " << m_joueur->Getvie() << endl;
    cout << "Nom de la carte active: " << m_musicienActif->Getname() << endl;
    cout << "Vie de la carte active: " << m_musicienActif->GetLP() << endl;
}
Carte* Terrain::PiocherCarte(int faconDePiocher)
{
    bool resteCarteDeck(false); // Pour savoir si il reste des cartes dans le deck
    bool resteCreatureDeck(false);// Pour savoir si il reste des cartes créature dans le deck
    bool carteCreatureSurTerrain(false); // Pour savoir si il y a une créature sur le terrain

    carteCreatureSurTerrain=GetpresenceMusicien(); // On regarde si il y a une créature

    for (int i=0; i< m_pioche.size(); i++)
    {
        if(m_pioche[i]->GetType()==1||m_pioche[i]->GetType()==2||m_pioche[i]->GetType()==3) // Si il reste une carte dans le deck
        {
            resteCarteDeck=true; // Si il y a une carte, on met à true resteCarteDeck
        }
        if(m_pioche[i]->GetType()==1)
        {
            resteCreatureDeck=true; // Même chose mais pour savoir si il ya des créatures
        }
    }

    if(resteCarteDeck)
    {
        if(resteCreatureDeck&&carteCreatureSurTerrain)
        {
            ///On pioche normalement
        }
        else if(!resteCreatureDeck)
        {
            ///On ne pioche pas car plus de créatures, du coût il a perdu.
            m_joueur->Setfin(true); // permet de déterminer qui a perdu en premier
        }
        else if(resteCreatureDeck&&!carteCreatureSurTerrain)
        {
            /// Déroule et pioche jusqu'à tomber sur une créature
            /// On devrait utiliser une file, bcp plus simple
        }
    }
}
void Terrain::effetCarteSpecial()
{
    /// La carte spéciale agit, à compléter rapidement.
    /// Fonctionne avec l'attribut m_specialePersistante.
}
void Terrain::deroulementJeu()
{
    SetCondition();
    if(Getcondition()==1) /// On joue normalement
    {
        effetCarteSpecial(); // La carte spécial agît si il y en a une
        PiocherCarte(); // Pioche une carte, agît en fonction

    }
    if(Getcondition()==2)
    {

    }
    if(Getcondition()==3)
    {

    }
    if(Getcondition()==4)
    {

    }
    if(Getcondition()==5)
    {

    }
    if(Getcondition()==6)
    {

    }
}
int Terrain::verificationJeu() /// Du coup il marche du feu de DIEUUUUUU
{
    int validation(0);
    bool resteCarteDeck(false); // Pour savoir si il reste des cartes dans le deck
    bool resteCreatureDeck(false);// Pour savoir si il reste des cartes créature dans le deck
    bool carteCreatureSurTerrain(false); // Pour savoir si il y a une créature sur le terrain

    for (int i=0; i< m_pioche.size(); i++)
    {
        if(m_pioche[i]->GetType()==1||m_pioche[i]->GetType()==2||m_pioche[i]->GetType()==3)
        {
            resteCarteDeck=true; // Si il y a une carte, on met à true carte
        }
        if(m_pioche[i]->GetType()==1)
        {
            resteCreatureDeck=true; // Même chose mais pour savoir si il ya des créatures
        }
    }
    carteCreatureSurTerrain=GetpresenceMusicien(); // On regarde si il y a une créature

    if (resteCarteDeck) /// Si il lui reste des cartes
    {
        if(carteCreatureSurTerrain)
        {
            cout << m_joueur->Getnom() << " joue, tout va bien" << endl;
            /// Pioche normalement
            return 1; // Il joue
        }
        if(!carteCreatureSurTerrain)
        {
            if(resteCreatureDeck)
            {
                return 2;
                ///Pioche jusqu'à avoir une créature
            }
            if(!resteCreatureDeck)
            {
                cout <<m_joueur->Getnom() <<" a des cartes dans son deck mais plus de creatures nulle part.";
                cout << "Il a donc perdu." << endl;
                return 3;
                /// Il a perdu.
            }
        }
    }
    else if(!resteCarteDeck)
    {
        if(carteCreatureSurTerrain)
        {
            if(musicienCapaciteAttaquer()==1||musicienCapaciteAttaquer()==2||musicienCapaciteAttaquer()==3)
            {
                cout << m_joueur->Getnom() << " attaque." << endl;
                ///MusicienAttaque(leterrainàattaquer);
                return 4; // Il continue car il lui reste une carte créture sur le terrain
            }
            if(!(musicienCapaciteAttaquer()==1&&musicienCapaciteAttaquer()==2&&musicienCapaciteAttaquer()==3))
            {
                cout << m_joueur->Getnom() <<" n'a plus de deck, et sa carte active de ne peux plus attaquer, il a perdu  " << endl;
                return 5;
            }
        }
        if(!carteCreatureSurTerrain)
        {
            cout << m_joueur->Getnom() <<" n'a plus aucune carte, il a perdu" << endl;
            return 6; // Il a perdu car il n'a plus de cartes dans le deck et sur le terrain
        }
    }
    else
        return 0;
}
void Terrain::MusicienAttaque(Terrain* cible, int numAttaque)
{
    if(cible->GetpresenceMusicien())// Si il y a un musicien adverse, on l'attaque
    {
        if (numAttaque==1)
            cible->Setlife(3/* là dedans on met le get approprié pour retourner la bonne valeur d'attaque*/);
        if (numAttaque==1)
            cible->Setlife(4/* là dedans on met le get approprié pour retourner la bonne valeur d'attaque*/);
        if (numAttaque==1)
            cible->Setlife(5/* là dedans on met le get approprié pour retourner la bonne valeur d'attaque*/);
    }

}
void Terrain::Setlife(int hitpoints) /// On enlève de la vie au musicien
{
    int excesDegat(0);

    if(m_musicienActif->GetLP()>=hitpoints) // Si sa vie est supérieur aux HP
    {
        m_musicienActif->modifvie(hitpoints);
    }
    if(m_musicienActif->GetLP()<hitpoints) // Sinon...
    {
        excesDegat=hitpoints-m_musicienActif->GetLP();

        m_musicienActif->modifvie(m_musicienActif->GetLP()); // On met sa vie à zéro
        SetlifePlayer(excesDegat); // L'excès de dégât est infligé au player
    }
}
void Terrain::SetlifePlayer(int hitpoints) /// On modifie la vie du joueur, seulement si il y a un excès de dégât
{
    m_joueur->modifVie(hitpoints);
}
bool Terrain::GetpresenceMusicien() const
{
    if(m_musicienActif!=NULL)
    {
        return true; // Si il y a un musicien sur le plateau de jeu, alors on renvoie true
    }
    else
    {
        return false;
    }
}
int Terrain::musicienCapaciteAttaquer()
{
    /// A compléter, renvoie un int en fonction de l'attaque qu'il peut faire
}
