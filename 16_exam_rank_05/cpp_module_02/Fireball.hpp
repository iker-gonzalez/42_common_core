#ifndef FIREBALL_HPP
# define FIREBALL_HPP

#include "ASpell.hpp"

class Fireball : public ASpell
{
	public:

		Fireball(void);
		~Fireball(void);

		virtual ASpell *clone(void) const;
};

#endif