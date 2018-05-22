#include <iostream>
#include <string>
#include <fstream>

#include "step.hpp"
#include "functions.hpp"


void getSteps(Step *steps, unsigned int nbEtapes)
{
    string name, prerequ;
    unsigned int prerequis;
    for(unsigned int i = 0; i < nbEtapes; i++)
    {
        cout << endl << "Step " << i+1 << " | name : ";
        cin >> name;
        steps[i].setName(name);

        cout << "Step " << i+1 << " | number of requisites : ";
        cin >> prerequis;
        steps[i].setNbRequirements(prerequis);

        for(unsigned int j = 0; j < prerequis; j++)
        {
            cout << "Step " << i+1 << " | requisite " << j+1 << " : ";
            cin >> prerequ;
            steps[i].addRequirement(prerequ);
        }
    }
}

void canBeUsed(Step *steps, unsigned int nbEtapes, vector<string> route)
{
    ofstream fichier("route.txt");
    for(unsigned int i = 0; i < nbEtapes; i++)
    {
        /*cout << "canBeUsed for1" << endl;
        fichier << "canBeUsed for1" << endl;*/
        if(steps[i].nbRequirements() == 0)
        {
        /*cout << "   canBeUsed if1" << endl;
        fichier << "   canBeUsed if1" << endl;*/
            steps[i].setUsability(true);
        }

        for(unsigned int j = 0; j < steps[i].nbRequirements(); j++)
        {
            /*cout << "   canBeUsed for2" << endl;
            fichier << "   canBeUsed for2" << endl;*/
            for(unsigned int k = 0; k < route.size(); k++)
            {
                /*cout << "       canBeUsed for3" << endl;
                fichier << "       canBeUsed for3" << endl;*/
                if(steps[i].getRequirements(j) == route[k])
                {
                    /*cout << "           canBeUsed if2" << endl;
                    fichier << "           canBeUsed if2" << endl;*/
                    steps[i].addCompletedRequirement(route[k]);
                }
                if(steps[i].nbRequiCompleted() == steps[i].nbRequirements())
                {
                    /*cout << "           canBeUsed if3" << endl;
                    fichier << "           canBeUsed if3" << endl;*/
                    steps[i].setUsability(true);
                }
            }
        }
    }
}

void makeRoute(Step *steps, unsigned int nbEtapes, vector<string>& route)
{
    ofstream fichier("route.txt");
    bool stepMissings = true;

    while(stepMissings)
    {
        /*cout << endl << "makeRoute while" << endl;
        fichier << endl << "makeRoute while" << endl;*/
        canBeUsed(steps, nbEtapes, route);
        for(unsigned int i = 0; i < nbEtapes; i++)
        {
            /*cout << endl << "   makeRoute for" << endl;
            fichier << endl << "   makeRoute for" << endl;*/
            if(steps[i].isUsable() && (steps[i].isUsed() == false))
            {
                /*cout << endl << "       makeRoute if1" << endl;
                fichier << endl << "       makeRoute if1" << endl;*/
                route.push_back(steps[i].getName());
                steps[i].setUsedState(true);
            }
        }

        if(nbEtapes == route.size())
        {
            /*cout << endl << "   makeRoute if2" << endl;
            fichier << endl << "   makeRoute if2" << endl;*/
            stepMissings = false;
        }
    }
}

void printRoute(vector<string> route, string nomRoute)
{
    ofstream fichier("route.txt");
    cout << endl << nomRoute << " route:" << endl;
    fichier << endl << nomRoute << "route:" << endl;
    for(unsigned int i = 0; i < route.size(); i++)
    {
        cout << route[i] << endl;
        fichier << route[i] << endl;
    }
}
