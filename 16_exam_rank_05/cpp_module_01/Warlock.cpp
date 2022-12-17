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
	if (new_spell)
		spells.insert(std::pair<std::string, ASpell *>(new_spell->getName(), new_spell->clone()));
}

void Warlock::forgetSpell(std::string spell_name)
{
	std::map<std::string, ASpell *>::iterator it = spells.find(spell_name);
	if (it != spells.end())
		delete it->second;
	spells.erase(spell_name);
}

void Warlock::launchSpell(std::string spell_name, ATarget const &target)
{
	ASpell *spell = spells[spell_name];
	if (spell)
		spell->launch(target);
}
