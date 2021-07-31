#include <iostream>
#include <string>
#include "Karen.hpp"

using std::string;
using std::cout; using std::endl;

Karen::Karen(void)
{
	complains[MODE_DEBUG] = &Karen::debug;
	complains[MODE_INFO] = &Karen::info;
	complains[MODE_WARNING] = &Karen::warning;
	complains[MODE_ERROR] = &Karen::error;
}

/* private */

void Karen::error(void) const
{
	cout << "This is unacceptable, I want to speak to the manager now." << endl;
}

void Karen::warning(void) const
{
	cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << endl;
}

void Karen::info(void) const
{
	cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << endl;
}

void Karen::debug(void) const
{
	cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << endl;
}

/* public */

void Karen::complain(string mode)
{
	intMode im = getIntMode(mode);
	
	if (im != MODE_MAX)
		(this->*complains[im])();
	else
		cout << "Karen could not complain, because an invalid mode has been specified!" << endl;
}

Karen::intMode	Karen::getIntMode(const std::string &mode)
{
	if (mode == "DEBUG")	return MODE_DEBUG;
	if (mode == "INFO")		return MODE_INFO;
	if (mode == "WARNING")	return MODE_WARNING;
	if (mode == "ERROR")	return MODE_ERROR;

	// if MODE_MAX is returned, mode is invalid
	return MODE_MAX;
}
