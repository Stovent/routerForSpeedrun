#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "Step.hpp"

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        std::cout << "This program need 1 and only 1 file!" << std::endl;
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


    // calculates the route
    while(route.size() < steps.size())
        for(auto step : steps)
        {
            std::vector<std::string>& prereqs = step.second.GetPrerequisites();
            
            for(auto itPrereq = prereqs.begin(); itPrereq != prereqs.end(); itPrereq++)
            {
                for(auto itRoute = route.begin(); itRoute != route.end(); itRoute++)
                {
                    if(*itPrereq == *itRoute) // if prerequisite is in the route
                        prereqs.erase(itPrereq); // then we remove it from the list
                    
                    if(prereqs.empty()) // if the prerequisite is empty
                        step.second.Usable(); // this mean there is no prerequsites mising so we can use it in the route
                    
                    if(step.second.IsUsable() && !(step.second.IsUsed())) // if the step is usable and not already used (in the route)
                    {
                        route.push_back(step.first); // we add it to the route
                        step.second.Used(); // it become unusable
                    }
                }
            }
        }


    // show input
    for(auto value : steps)
    {
        std::cout << value.first << std::endl;
        auto typ = value.second.GetPrerequisites();
        for(auto val : typ)
            std::cout << "  " << val << std::endl;
    }

    //show route
    for(auto value : route)
        std::cout << value << std::endl;


    return 0;
}
