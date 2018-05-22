#ifndef STEP_HPP
#define STEP_HPP

#include <string>
#include <vector>

using namespace std;

class Step
{
    private:
    unsigned int a_nbRequirements;
    bool a_used;
    bool a_usable;

    string a_name;
    vector<string> a_requirements;
    vector<string> a_nbRequiCompleted;


    public:
    Step();

    // READ
    unsigned int nbRequirements();
    bool isUsed();
    bool isUsable();
    string getName();
    string getRequirements(unsigned int i);
    unsigned int nbRequiCompleted();

    // WRITE
    void setNbRequirements(unsigned int nbRequirements);
    void setUsedState(bool state);
    void setUsability(bool state);
    void setName(string name);
    void addRequirement(string nom);
    void addCompletedRequirement(string requi);

};

#endif //STEP_HPP
