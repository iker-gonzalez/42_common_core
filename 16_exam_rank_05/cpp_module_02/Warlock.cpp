#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title)
{
	this->name = name;
	this->title = title;
	std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(void)
{
	std::cout << this->name << ": My job here is done!" << std::endl;
}

std::string const &Warlock::getName(void) const
{
	return (this->name);
}

std::string const &Warlock::getTitle(void) const
{
	return (this->title);
}

void Warlock::setTitle(std::string const &title)
{
	this->title = title;
}

void Warlock::introduce(void) const
{
	std::cout << "I am " << this->name << ", " << this->title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *new_spell)
{
	book.learnSpell(new_spell);
}

void Warlock::forgetSpell(std::string spell_name)
{
	book.forgetSpell(spell_name);
}

void Warlock::launchSpell(std::string spell_name, ATarget const &target)
{
	ATarget const *test = 0;
	if (test == &target)
		return ;
	ASpell *spell = book.createSpell(spell_name);
	if (spell)
		spell->launch(target);
}
