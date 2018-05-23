#include "Step.hpp"

Step::Step()
{

}

void Step::AddPrerequisite(std::string name)
{
    prerequisites.push_back(name);
}

bool Step::IsUsable()
{
    return usable;
}

void Step::Usable(bool val)
{
    usable = val;
}
