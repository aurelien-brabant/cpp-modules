#ifndef COMMANDINFO_H
# define COMMANDINFO_H
# include <string>
# include "PhoneBook.h"

void	commandAdd(PhoneBook &pb);
void	commandHelp(PhoneBook &pb);
void	commandRemove(PhoneBook &pb);
void	commandSearch(PhoneBook &pb);
void	commandSave(PhoneBook &pb);
void	commandLoad(PhoneBook &pb);
void	commandExit(PhoneBook &pb);
void	commandClear(PhoneBook &pb);

struct CommandInfo
{
	std::string label;
	std::string usage;
	void (*handler)(PhoneBook &pb);
};

#endif
