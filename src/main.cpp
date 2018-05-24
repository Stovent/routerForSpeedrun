#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Step.hpp"

int main(int argc, char* argv[])
{
    if(argc < 2 || argc > 3)
    {
        std::cout << "This program needs one or two arguments." << std::endl;
        std::cout << "first argument is the input file containing the steps. Second argument (optional) is the name of the output file" << std::endl;
        return 1;
    }


    std::vector<std::string> route; // final route
    std::vector<std::pair<std::string, Step>> steps;

    std::ifstream input(argv[1]);
    std::string tmp, tmpName;
    int tmpArg = 0;


    // read input file and create steps
    while(!input.eof())
    {
        input >> tmpName;
        steps.push_back(std::pair<std::string, Step>(tmpName, Step()));
        input >> tmpArg;
        while(tmpArg)
        {
            input >> tmp;
            auto it = steps.end() - 1;
            it->second.AddPrerequisite(tmp);
            tmpArg--;
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

    // calculates the route
    while(route.size() < steps.size())
    {
        for(auto step = steps.begin(); step != steps.end(); step++)
        {
            std::vector<std::string>& prerequisites = step->second.GetPrerequisites();

            for(auto itPre = prerequisites.begin(); itPre != prerequisites.end(); itPre++)
            {
                if(find(route.begin(), route.end(), *itPre) != route.end())
                {
                    prerequisites.erase(itPre);
                    itPre--;
                }
            }

            if(prerequisites.empty())
            {
                step->second.Usable();
            }

            if(step->second.IsUsable() && !(step->second.IsUsed()))
            {
                route.push_back(step->first);
                step->second.Used();
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
