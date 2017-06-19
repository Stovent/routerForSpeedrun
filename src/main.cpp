#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

#include "step.hpp"
#include "functions.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    string routeName;
    unsigned int nbEtapes;
    string s;
    s = "yolo";

    cout << "Route name: ";
    getline(cin, routeName);
    cout << endl << "Number of steps: ";
    cin >> nbEtapes;

    Step etapes[nbEtapes];
    vector<string> route(0);

    getSteps(etapes, nbEtapes);
    makeRoute(etapes, nbEtapes, route);
    printRoute(route, routeName);

    return EXIT_SUCCESS;
}
