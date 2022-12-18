#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include "ASpell.hpp"
#include <map>

class SpellBook {

	private:

		std::map<std::string, ASpell *> spells;

		SpellBook(SpellBook const &other);
		SpellBook &operator=(SpellBook const &other);

	public:

		SpellBook(void);
		~SpellBook(void);

		void learnSpell(ASpell* spell);
		void forgetSpell(std::string const &spell_name);
		ASpell* createSpell(std::string const &spell_name);
};

#endif