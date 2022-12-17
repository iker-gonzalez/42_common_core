#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell {

	private:

		std::string name;
		std::string effects;

	public:

	ASpell(void);
	ASpell (std::string const &name, std::string const &effects);
	ASpell (ASpell const &other);
	ASpell &operator=(ASpell const &other);
	virtual ~ASpell(void);

	std::string const &getName(void) const;
	std::string const &getEffects(void) const;

	virtual ASpell *clone(void) const = 0;

	void launch(ATarget const &target) const;

};

#endif