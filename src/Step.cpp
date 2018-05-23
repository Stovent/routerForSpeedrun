#include "Step.hpp"

Step::Step()
{
    used = false;
    usable = false;
}

void Step::AddPrerequisite(std::string name)
{
    prerequisites.push_back(name);
}

std::vector<std::string>& Step::GetPrerequisites()
{
    return prerequisites;
}

bool Step::IsUsable()
{
    return usable;
}

void Step::Usable()
{
    usable = true;
}

bool Step::IsUsed()
{
    return used;
}

void Step::Used()
{
    used = true;
}
