#include <iostream>
#include <string>
#include <fstream>

#include "functions.hpp"
#include "step.hpp"


void getSteps(Step *etapes, unsigned int nbEtapes)
{
    string nom, prerequ;
    unsigned int prerequis;
    for(unsigned int i = 0; i < nbEtapes; i++)
    {
        cout << endl << "Etape " << i+1 << " | nom : ";
        cin >> nom;
        etapes[i].setName(nom);

        cout << "Etape " << i+1 << " | nombre de prerequis : ";
        cin >> prerequis;
        etapes[i].setNbRequirements(prerequis);

        for(unsigned int j = 0; j < prerequis; j++)
        {
            cout << "Etape " << i+1 << " | prerequis " << j+1 << " : ";
            cin >> prerequ;
            etapes[i].addRequirement(prerequ);
        }
    }
}

void canBeUsed(Step *etapes, unsigned int nbEtapes, vector<string> route)
{
    ofstream fichier("route.txt");
    for(unsigned int i = 0; i < nbEtapes; i++)
    {
        cout << "canBeUsed for1" << endl;
        fichier << "canBeUsed for1" << endl;
        if(etapes[i].nbRequirements() == 0)
        {
        cout << "   canBeUsed if1" << endl;
        fichier << "   canBeUsed if1" << endl;
            etapes[i].setUsability(true);
        }

        for(unsigned int j = 0; j < etapes[i].nbRequirements(); j++)
        {
            cout << "   canBeUsed for2" << endl;
            fichier << "   canBeUsed for2" << endl;
            for(unsigned int k = 0; k < route.size(); k++)
            {
                cout << "       canBeUsed for3" << endl;
                fichier << "       canBeUsed for3" << endl;
                if(etapes[i].getRequirements(j) == route[k])
                {
                    cout << "           canBeUsed if2" << endl;
                    fichier << "           canBeUsed if2" << endl;
                    etapes[i].addCompletedRequirement(route[k]);
                }
                if(etapes[i].nbRequiCompleted() == etapes[i].nbRequirements())
                {
                    cout << "           canBeUsed if3" << endl;
                    fichier << "           canBeUsed if3" << endl;
                    etapes[i].setUsability(true);
                }
            }
        }
    }
}

void makeRoute(Step *etapes, unsigned int nbEtapes, vector<string>& route)
{
    ofstream fichier("route.txt");
    bool stepMissings = true;

    while(stepMissings)
    {
        cout << endl << "makeRoute while" << endl;
        fichier << endl << "makeRoute while" << endl;
        canBeUsed(etapes, nbEtapes, route);
        for(unsigned int i = 0; i < nbEtapes; i++)
        {
            cout << endl << "   makeRoute for" << endl;
            fichier << endl << "   makeRoute for" << endl;
            if(etapes[i].isUsable() && (etapes[i].isUsed() == false))
            {
                cout << endl << "       makeRoute if1" << endl;
                fichier << endl << "       makeRoute if1" << endl;
                route.push_back(etapes[i].getName());
                etapes[i].setUsedState(true);
            }
        }

        if(nbEtapes == route.size())
        {
            cout << endl << "   makeRoute if2" << endl;
            fichier << endl << "   makeRoute if2" << endl;
            stepMissings = false;
        }
    }
}

void printRoute(vector<string> route, string nomRoute)
{
    ofstream fichier("route.txt");
    cout << endl << nomRoute << " route :" << endl;
    for(unsigned int i = 0; i < route.size(); i++)
    {
        cout << route[i] << endl;
        fichier << route[i] << endl;
    }
}
