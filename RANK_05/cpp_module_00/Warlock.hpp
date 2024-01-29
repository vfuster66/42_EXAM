#pragma once

#include <iostream>

class Warlock
{
private:
	std::string name;
	std::string title;

	Warlock();
	Warlock(const Warlock &other);
	Warlock &operator=(const Warlock &other);

public:
	Warlock(std::string const &name, std::string const &title);

	~Warlock();

	std::string const &getName()const;

	std::string const &getTitle()const;

	void setTitle(std::string const &title);

	void introduce() const;
};