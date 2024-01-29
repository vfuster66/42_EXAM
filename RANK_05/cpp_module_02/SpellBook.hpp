// SpellBook.hpp

#pragma once

#include "ASpell.hpp"
#include <map>

class SpellBook
{
private:
	std::map<std::string, ASpell *> array;

	SpellBook(SpellBook const &other);
	SpellBook &operator=(SpellBook const &other);

public:
	SpellBook();
	~SpellBook();

	void learnSpell(ASpell *spell);
	void forgetSpell(std::string const &name);
	ASpell* createSpell(std::string const &name);

};