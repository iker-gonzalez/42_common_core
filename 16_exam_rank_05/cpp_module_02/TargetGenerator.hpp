#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include "ATarget.hpp"
#include <map>

class TargetGenerator {

	private:

		std::map<std::string, ATarget *> targets;
		TargetGenerator(TargetGenerator const &other);
		TargetGenerator &operator=(TargetGenerator const &other);

	public:

		TargetGenerator(void);
		~TargetGenerator(void);

		void learnTargetType(ATarget* target);
		void forgetTargetType(std::string const &target);
		ATarget* createTarget(std::string const &target);
};

#endif