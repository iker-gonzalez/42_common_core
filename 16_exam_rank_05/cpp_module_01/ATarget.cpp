#include "ATarget.hpp"

ATarget::ATarget(void) {};

ATarget::ATarget(std::string const &type)
{
	this->type = type;
}

ATarget::ATarget(ATarget const &other)
{
	*this = other;
}

ATarget &ATarget::operator=(ATarget const &other)
{
	this->type = other.type;
	return *this;
}

ATarget::~ATarget(void) {};

std::string const &ATarget::getType(void) const
{
	return (this->type);
}

void ATarget::getHitBySpeell(ASpell const &spell) const
{
	std::cout << getType() << " has been " << spell.getEffects() << "!" << std::endl;
}
