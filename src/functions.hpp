#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "step.hpp"

void getSteps(Step *steps, unsigned int nbEtapes);
void canBeUsed(Step *steps, unsigned int nbEtapes, vector<string> route);
void makeRoute(Step *steps, unsigned int nbEtapes, vector<string>& route);
void printRoute(vector<string> route, string nomRoute);

#endif //FUNCTIONS_H
