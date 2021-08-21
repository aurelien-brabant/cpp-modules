# This file contains all the Makefile variables and rules that will never change
# across modules and exercises. It is to be included at the top of every C++
# exercise own's Makefile.
#
# This template assumes that some variables are already defined before inclusion:
# - TARGET, which must hold the name of the executable.
# - SRCS, which must hold the list of .cpp files that are needed to compile the program. 
# - HEADERS, which must hold the list of .{h, hpp} files the program depends on.

CC			:= clang++
CPP_FLAGS	= -Wall -Wextra -Werror -std=c++98
LD			:= $(CC)

OBJS		:= $(SRCS:%.cpp=%.o)

RM			:= rm -rf

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(OBJS) -o $(TARGET)

ifdef DEBUG
%.o: %.cpp $(HEADERS)
	$(CC) -c $(CPP_FLAGS) -D DEBUG $< -o $@
endif

ifndef DEBUG
%.o: %.cpp $(HEADERS)
	$(CC) -c $(CPP_FLAGS) $< -o $@
endif

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

.PHONY: all clean fclean re
