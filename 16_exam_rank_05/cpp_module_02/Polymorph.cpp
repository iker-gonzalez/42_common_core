#include "Polymorph.hpp"

Polymorph::Polymorph(void) : ASpell("Polymorph", "turned into a critter") {};

Polymorph::~Polymorph(void) {};

ASpell *Polymorph::clone(void) const
{
	return(new Polymorph());
}