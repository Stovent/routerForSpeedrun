#ifndef STEP_HPP
#define STEP_HPP

#include <vector>
#include <string>

class Step
{
private:
    std::vector<std::string> prerequisites;
    bool usable;

public:
    Step();
    
    bool IsUsable();
    void Usable(bool val);
    void AddPrerequisite(std::string name);
};

#endif // STEP_HPP
