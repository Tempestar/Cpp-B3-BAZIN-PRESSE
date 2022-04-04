#include <iostream>
#include "../Headers/constantes.h"

using namespace std;
/************************************************************************************************************************************************/


ChoixMenu demanderChoixMenu()
{
    char saisieChoix;
    cin >> saisieChoix;
    // on met a jour la condition demander choix menu
    if (saisieChoix == static_cast<char>(ChoixMenu::JOUER) || saisieChoix == static_cast<char>(ChoixMenu::JOUER_FACILE) || saisieChoix == static_cast<char>(ChoixMenu::JOUER_TROIS_PARTIES) || saisieChoix == static_cast<char>(ChoixMenu::QUITTER))
    {
        return static_cast<ChoixMenu>(saisieChoix);
    }
    else
    {
        return ChoixMenu::INCORRECT;
    }
}

void demanderProposition(int &proposition)
{
    cin >> proposition;
    // ici on passe la r�f�rence
}

void jouerPartie(int leJustePrix, int max)
// type pour le param�tre, pas auto, on remplace les occurrences de aDeviner par leJustePrix
{
    auto proposition{0};
    auto nombreTentatives{0};
    do
    {
        // comme dans tous les langages l'int�r�t des fonctions est de pouvoir r�utiliser le code
        cout << "Proposition? ";
        demanderProposition(proposition);

        cout << proposition;

        if (proposition >= BORNE_MIN && proposition < max)
        {
            nombreTentatives++;
            if (proposition == leJustePrix)
            {
                cout << "Bravo! " << endl;
            }
            else if (proposition > leJustePrix)
            {
                cout << "C'est moins ! " << endl;
            }
            else
            {
                cout << "C'est plus ! " << endl;
            }
        }
    } while (proposition != leJustePrix && proposition >= BORNE_MIN);

    if (proposition == leJustePrix)
    {
        cout << "partie termin�e! "
             << "en " << nombreTentatives << " tentatives" << endl;
    }
    else
    {
        cout << "partie abandonn�e ";
    }
}

// ici on ne souhaite pas retourner de valeur on utilise void
void jouerTroisParties()
{
    cout << "C'est parti ! " << endl;
    for (auto aDeviner : {208, 42, 1984})
    {
        // on veut la param�trer avec le nombre a deviner
        jouerPartie(aDeviner, BORNE_MAX);
    }
}

void afficherMenu()
{
    cout << static_cast<char>(ChoixMenu::JOUER) << ": jouer" << endl;
    // on ajoute les choix possible � l'affichage
    cout << static_cast<char>(ChoixMenu::JOUER_FACILE) << ": jouer" << endl;
    cout << static_cast<char>(ChoixMenu::JOUER_TROIS_PARTIES) << ": jouer" << endl;
    cout << static_cast<char>(ChoixMenu::QUITTER) << ": quitter" << endl;
}



/******/

// cr�er un fichier constantes.h et cocher debug et release
// et enregistrer le projet !!! tr�s important pour la compilation
// cr�ation de trois lignes par d�faut directives pr�processeur, ici on �vite de d�clare plusieurs fois le contenu de notre fichier

// � cet endroit le nom de la constante que nous allons utiliser doit �tre unique dans l'ensemble de tout notre programme

// #pragma once on verra plus tard

// on passe au dossier !!!
