#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

struct Base
{
	virtual ~Base(void);
};

struct A: public Base
{
};

struct B: public Base
{
};

struct C: public Base
{
};

Base * generate(void);
void identify(Base * p);
void identify(Base & p);

#endif
