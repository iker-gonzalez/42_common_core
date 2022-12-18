#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock {

	private:
		
		SpellBook book;
		std::string name;
		std::string title;
		std::map<std::string, ASpell *> spells;

		Warlock(void);
		Warlock(Warlock const &other);
		Warlock &operator=(Warlock const &other);

	public:

		Warlock(std::string const &name, std::string const &title);
		~Warlock(void);

		std::string const &getName(void) const;
		std::string const &getTitle(void) const;

		void setTitle(std::string const &title);
		
		void introduce(void) const;

		void learnSpell(ASpell *new_spell);
		void forgetSpell(std::string spell_name);
		void launchSpell(std::string spell_name, ATarget const &target);
};

#endif