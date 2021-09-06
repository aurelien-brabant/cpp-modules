#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
    Brain *brain;

    public:
        Cat();
        Cat(Cat const& rhs);
        Cat& operator=(Cat const& rhs);
        ~Cat();

        void makeSound(void) const;

        // Cat specific. Allow the given cat to empty its mind, i.e to set all its ideas
        // to the empty string.
        // A const cat has a fixed mind, and can't meditate :(
        void meditate(void);
};

#endif