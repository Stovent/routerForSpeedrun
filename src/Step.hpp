#ifndef STEP_HPP
#define STEP_HPP

#include <vector>
#include <string>

class Step
{
private:
    std::vector<std::string> prerequisites;
    bool usable;
    bool used;

public:
    Step();

    bool IsUsable();
    void Usable();

    bool IsUsed();
    void Used();

    void AddPrerequisite(std::string name);
    std::vector<std::string>& GetPrerequisites();
};

#endif // STEP_HPP
