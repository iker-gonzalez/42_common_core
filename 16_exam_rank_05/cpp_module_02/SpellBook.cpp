#include "SpellBook.hpp"

SpellBook::SpellBook(void) {}

SpellBook::~SpellBook(void)
{
	std::map<std::string, ASpell *>::iterator it_begin = spells.begin();
	std::map<std::string, ASpell *>::iterator it_end = spells.end();
	while (it_begin != it_end)
	{
		delete it_begin->second;
		it_begin++;
	}
	spells.clear();
}


void SpellBook::learnSpell(ASpell* new_spell)
{
	if (new_spell)
		spells.insert(std::pair<std::string, ASpell *>(new_spell->getName(), new_spell->clone()));
}

void SpellBook::forgetSpell(std::string const &spell_name)
{
	std::map<std::string, ASpell *>::iterator it = spells.find(spell_name);
	if (it != spells.end())
		delete it->second;
	spells.erase(spell_name);
}

ASpell* SpellBook::createSpell(std::string const &spell_name)
{
	std::map<std::string, ASpell *>::iterator it = spells.find(spell_name);
	if (it != spells.end())
		return spells[spell_name];
	return NULL;
}