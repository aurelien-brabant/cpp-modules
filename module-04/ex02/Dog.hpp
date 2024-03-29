#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
    public:
        Brain* brain;
        Dog(void);
        Dog(Dog const& rhs);
        Dog const &operator=(Dog const& rhs);
        ~Dog();

        void makeSound(void) const;
};

#endif