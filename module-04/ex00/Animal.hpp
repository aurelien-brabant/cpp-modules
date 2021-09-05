#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>
# include <iostream>

class Animal
{
    std::string _type;

    public:
        Animal();
        Animal(Animal const &rhs);
        Animal& operator=(Animal const &rhs);
        ~Animal(void);

        virtual void makeSound(void) const;
        std::string getType(void) const;
};

std::ostream &operator<<(std::ostream &os, Animal const& a);

#endif