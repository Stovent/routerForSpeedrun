#ifndef STEP_HPP
#define STEP_HPP

#include <vector>
#include <string>

class Step
{
private:
    std::vector<std::string> prerequisites;

public:
    Step();
    
    bool IsUsable();
    void AddPrerequisite(std::string name);
};

#endif // STEP_HPP
