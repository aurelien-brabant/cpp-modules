#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
    public:
        Brain *brain;
        Cat();
        Cat(Cat const& rhs);
        Cat& operator=(Cat const& rhs);
        ~Cat();

        void makeSound(void) const;
};

#endif
