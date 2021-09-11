#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP
# include <string.h>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		static const int _recipeMax = 4;
		AMateria* _mRecipe[_recipeMax];

	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & rhs);
		~MateriaSource(void);
		
		MateriaSource & operator=(MateriaSource const & rhs);
		
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif
