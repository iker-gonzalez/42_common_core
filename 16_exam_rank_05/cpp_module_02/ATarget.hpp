#ifndef ATARGET_HPP
# define ATARGET_HPP

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget {

	private:

		std::string type;

	public:

		ATarget(void);
		ATarget(std::string const &type);
		ATarget(ATarget const &other);
		ATarget &operator=(ATarget const &other);
		virtual ~ATarget(void);

		std::string const &getType(void) const;

		virtual ATarget *clone(void) const = 0;

		void getHitBySpeell(ASpell const &spell) const;
};

#endif