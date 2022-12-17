#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>

class Warlock {

	private:
		
		std::string name;
		std::string title;

		Warlock(void);
		Warlock (Warlock const &other);
		Warlock &operator=(Warlock const &other);

	public:

		Warlock (std::string const &name, std::string const &title);
		~Warlock(void);

		std::string const &getName(void) const;
		std::string const &getTitle(void) const;

		void setTitle(std::string const &title);
		
		void introduce(void) const;
};

#endif