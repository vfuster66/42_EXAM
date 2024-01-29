// TargetGenerator.cpp

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{
}

TargetGenerator::~TargetGenerator()
{
	std::map<std::string, ATarget *>::iterator it_begin = this->array.begin();
	std::map<std::string, ATarget *>::iterator it_end = this->array.end();
	while (it_begin != it_end)
	{
		delete it_begin->second;
		++it_begin;
	}
	this->array.clear();
}

void TargetGenerator::learnTargetType(ATarget* target)
{
	if (target)
		array.insert(std::pair<std::string, ATarget *>(target->getType(), target->clone()));
}

void TargetGenerator::forgetTargetType(const std::string &name)
{
	std::map<std::string, ATarget *>::iterator it = array.find(name);
	if (it != array.end())
		delete it->second;
	array.erase(name);
}

ATarget* TargetGenerator::createTarget(const std::string &name)
{
	std::map<std::string, ATarget *>::iterator it = array.find(name);
	if (it != array.end())
		return array[name];
	return NULL;
}