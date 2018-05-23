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



    for(auto value : steps)
    {
        std::cout << value.first << std::endl;
        auto typ = value.second.GetPrerequisites();
        for(auto val : typ)
            std::cout << "  " << val << std::endl;
    }


    return 0;
}
