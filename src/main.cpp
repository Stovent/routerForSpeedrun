#include <iostream>
#include <map>
#include <string>

#include "Step.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        cout << "This program need 1 and only 1 file!" << std::endl;
        return 1;
    }
    
    map<string, Step> steps;
    
    return 0;
}
