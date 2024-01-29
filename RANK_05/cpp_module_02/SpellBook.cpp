// SpellBook.cpp

#include "SpellBook.hpp"

SpellBook::SpellBook()
{
}

SpellBook::~SpellBook()
{
	std::map<std::string, ASpell *>::iterator it_begin = this->array.begin();
	std::map<std::string, ASpell *>::iterator it_end = this->array.end();
	while (it_begin != it_end)
	{
		delete it_begin->second;
		++it_begin;
	}
	this->array.clear();
}

void SpellBook::learnSpell(ASpell* spell)
{
	if (spell)
		array.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
}

void SpellBook::forgetSpell(std::string const &name)
{
	std::map<std::string, ASpell *>::iterator it = array.find(name);
	if (it != array.end())
		delete it->second;
	array.erase(name);
}

ASpell* SpellBook::createSpell(std::string const &name)
{
	std::map<std::string, ASpell *>::iterator it = array.find(name);
	if (it != array.end())
		return array[name];
	return NULL;
}