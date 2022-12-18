#include "Fireball.hpp"

Fireball::Fireball(void) : ASpell("Fireball", "burnt to a crisp") {};

Fireball::~Fireball(void) {};

ASpell *Fireball::clone(void) const
{
	return(new Fireball());
}