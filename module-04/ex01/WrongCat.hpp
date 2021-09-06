#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(WrongCat const& rhs);
        WrongCat& operator=(WrongCat const& rhs);
        ~WrongCat();

        void makeSound(void) const;
};

#endif