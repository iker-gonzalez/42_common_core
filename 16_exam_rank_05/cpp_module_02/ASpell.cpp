#include "ASpell.hpp"

ASpell::ASpell(void) {};

ASpell::ASpell(std::string const &name, std::string const &effects)
{
	this->name = name;
	this->effects = effects;
}

ASpell::ASpell(ASpell const &other)
{
	*this = other;
}

ASpell &ASpell::operator=(ASpell const &other)
{
	this->name = other.name;
	this->effects = other.effects;
	return *this;
}

ASpell::~ASpell(void) {};

std::string const &ASpell::getName(void) const
{
	return (this->name);
}

std::string const &ASpell::getEffects(void) const
{
	return (this->effects);
}

void ASpell::launch(ATarget const &target) const
{
	target.getHitBySpeell((*this));
}
