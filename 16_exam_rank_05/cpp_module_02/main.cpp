#include "Warlock.hpp"
#include "Fireball.hpp"
#include "ATarget.hpp"
#include "TargetGenerator.hpp"
#include "Polymorph.hpp"
#include "BrickWall.hpp"

int main()
{
  Warlock richard("Richard", "foo");
  richard.setTitle("Hello, I'm Richard the Warlock!");
  BrickWall model1;

  Polymorph* polymorph = new Polymorph();
  TargetGenerator tarGen;

  tarGen.learnTargetType(&model1);
  richard.learnSpell(polymorph);

  Fireball* fireball = new Fireball();

  richard.learnSpell(fireball);

  ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

  richard.introduce();
  richard.launchSpell("Polymorph", *wall);
  richard.launchSpell("Fireball", *wall);
}

/*
* Expected output:

	~$ ./a.out | cat -e
	Richard: This looks like another boring day.$
	Richard: I am Richard, Hello, I'm Richard the Warlock!!$
	Inconspicuous Red-brick Wall has been turned into a critter!$
	Inconspicuous Red-brick Wall has been burnt to a crisp!$
	Richard: My job here is done!$
~$
*/