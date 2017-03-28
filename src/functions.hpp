#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "step.hpp"

void getSteps(Step *etapes, unsigned int nbEtapes);
void canBeUsed(Step *etapes, unsigned int nbEtapes, vector<string> route);
void makeRoute(Step *etapes, unsigned int nbEtapes, vector<string>& route);
void printRoute(vector<string> route, string nomRoute);

#endif //FUNCTIONS_H
