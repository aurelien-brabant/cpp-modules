#include <iostream>
#include <string>

const std::ostream &printDebug(std::string const &msg)
{
	(void)msg;

	#ifdef DEBUG
		std::cout << "[ \033[0;35mDEBUG\033[0m ] " << msg << std::endl;
	#endif

	return std::cout;
}
