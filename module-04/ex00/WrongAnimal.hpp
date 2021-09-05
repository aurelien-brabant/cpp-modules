#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP
# include <string>
# include <iostream>

class WrongAnimal 
{
    protected:
        std::string _type;

    public:
        WrongAnimal();
        WrongAnimal(WrongAnimal const &rhs);
        WrongAnimal& operator=(WrongAnimal const &rhs);
        virtual ~WrongAnimal(void);

        // makeSound is not marked as virtual, then dynamic binding
        // won't work as expected.
        void makeSound(void) const;
        std::string getType(void) const;
};

std::ostream &operator<<(std::ostream &os, WrongAnimal const& a);

#endif