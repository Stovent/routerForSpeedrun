#include <string>
#include <vector>
#include "step.hpp"

Step::Step()
{
    a_used = false;
    a_usable = false;
    vector<string> a_requirements(0);
    vector<int> nbRequiCompleted(0);
}

unsigned int Step::nbRequirements()
{
	return a_nbRequirements;
}

bool Step::isUsed()
{
	return a_used;
}

bool Step::isUsable()
{
	return a_usable;
}

string Step::getName()
{
	return a_name;
}

string Step::getRequirements(unsigned int i)
{
	return a_requirements[i];
}

unsigned int Step::nbRequiCompleted()
{
	return a_nbRequiCompleted.size();
}

// WRITE

void Step::setNbRequirements(unsigned int nbRequirements)
{
	a_nbRequirements = nbRequirements;
}

void Step::setUsedState(bool state)
{
	a_used = state;
}

void Step::setUsability(bool state)
{
	a_usable = state;
}

void Step::setName(string name)
{
	a_name = name;
}

void Step::addRequirement(string nom)
{
	a_requirements.push_back(nom);
}

void Step::addCompletedRequirement(string requi)
{
	a_nbRequiCompleted.push_back(requi);
}
