#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "Step.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        cout << "This program need 1 and only 1 file!" << std::endl;
        return 1;
    }
    
    
    std::vector<std::string> route; // final route
    std::map<string, Step> steps;
    
    std::ifstream input(argv[1]);
    std::string tmp, tmpName;
    int tmpArg = 0;
    
    
    // read input file and create steps
    while(input.good())
    {
        input >> tmpName;
        steps.insert(std::pair<std::string, Step>(tmpName, Step()));
        cin >> tmpArg;
        while(tmpArg)
        {
            cin >> tmp;
            steps[tmpName].AddPrerequisite(tmp);
            tmpArg--;
        }
    }
    
    
    // calculates the route
    while(route.size() < steps.size())
    {
        for(std::map<string, Step>::iterator it = steps.begin(); it != steps.end(); it++)
        {
            if(find(route.begin(), route.end(), it->first) == route.end()) // the step is not in the route so we add it
            {
                if(it->second.IsUsable())
                {
                    route.push_back(it->first);
                    it->second.Usable(false);
                }
            }
        }
    }
    
    return 0;
}
