#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

#include "functions.hpp"
#include "step.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    string nomRoute;
    unsigned int nbEtapes;

    cout << "Route Name : ";
    getline(cin, nomRoute);
    cout << endl << "Nombres d'etapes : ";
    cin >> nbEtapes;

    Step etapes[nbEtapes];
    vector<string> route(0);

    getSteps(etapes, nbEtapes);
    makeRoute(etapes, nbEtapes, route);
    printRoute(route, nomRoute);

    return EXIT_SUCCESS;
}
