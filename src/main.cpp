#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Step.hpp"

int main(int argc, char* argv[])
{
    if(argc < 2 || argc > 3)
    {
        std::cout << "This program needs one or two arguments." << std::endl;
        std::cout << "first argument is the input file containing the steps. Second argument (optional) is the name of the output file" << std::endl;
        exit(1);
    }


    std::vector<std::string> route; // final route
    std::vector<std::pair<std::string, Step>> steps;
    std::ifstream input(argv[1]);
    if(!input.good())
    {
        std::cout << "Couldn't open input file '" << argv[1] << "'! Stopping..." << std::endl;
        exit(1);
    }

    std::string argName, stepName;
    int argNbr = 0;
    std::string line;
    while(std::getline(input, line))// read input file and create steps
    {
        std::stringstream sline(line); // used to avoid duplication of the last step if input file finish by a new line
        sline >> stepName;
        steps.push_back(std::pair<std::string, Step>(stepName, Step()));
        stepName = "";
        sline >> argNbr;
        while(argNbr)
        {
            sline >> argName;
            auto it = steps.end() - 1;
            it->second.AddPrerequisite(argName);
            argNbr--;
        }
    }

    std::cout << "input : " << std::endl;
    // show input
    for(auto value : steps)
    {
        std::cout << value.first << std::endl;
        auto prereq = value.second.GetPrerequisites();
        for(auto val : prereq)
            std::cout << "  " << val << std::endl;
        std::cout << std::endl;
    }

    const unsigned int size = steps.size();
    // calculates the route
    while(route.size() < size) // while the route is not completed,
    {
        for(auto step = steps.begin(); step != steps.end(); step++) // for every step,
        {
            std::vector<std::string>& prerequisites = step->second.GetPrerequisites(); // I retrives its prerequisites,

            for(auto itPre = prerequisites.begin(); itPre != prerequisites.end(); itPre++) // and for each of them,
            {
                if(find(route.begin(), route.end(), *itPre) != route.end()) // if it is in the route
                {
                    prerequisites.erase(itPre); // then it is completed and so removed for the list.
                    itPre--;
                }
            }

            if(prerequisites.empty()) // if there is no more prerequisites,
                step->second.Usable(); // then the step can be used in the route.

            if(step->second.IsUsable() && !(step->second.IsUsed())) // if the step can be used and is not already used,
            {
                route.push_back(step->first); // we add it into the list,
                step->second.Used(); // we set it to Used so it won't be used twice,
            }

        }
    }

    std::cout << std::endl << "output : " << std::endl;
    std::ofstream output((argc == 3) ? argv[2] : "route.txt");
    //show route
    for(auto value : route)
    {
        std::cout << value << std::endl;
        output << value << std::endl;
    }

    return 0;
}
