#ifndef BRICKWALL_HPP
# define BRICKWALL_HPP

#include "ATarget.hpp"

class BrickWall: public ATarget {

	public:

		BrickWall(void);
		~BrickWall(void);

		virtual ATarget *clone(void) const;
};

#endif