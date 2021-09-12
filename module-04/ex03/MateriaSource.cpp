#include <string>
#include "MateriaSource.hpp"

using std::string;

MateriaSource::MateriaSource(void): _mRecipe()
{
}

MateriaSource::MateriaSource(MateriaSource const &rhs): _mRecipe()
{
	*this = rhs;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i != _recipeMax; ++i) {
		delete _mRecipe[i];
	}
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs)
{
	if (this != &rhs) {
		for (int i = 0; i != _recipeMax; ++i) {
			delete _mRecipe[i];
			_mRecipe[i] = rhs._mRecipe[i] ? rhs._mRecipe[i]->clone() : 0;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i != _recipeMax; ++i) {
		if (_mRecipe[i] == m) {
			return ;
		}	
	}

	for (int i = 0; i != _recipeMax; ++i) {
		if (!_mRecipe[i]) {
			_mRecipe[i] = m;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(string const & type)
{
	for (int i = 0; i != _recipeMax; ++i) {
		if (_mRecipe[i] && _mRecipe[i]->getType() == type) {
			return _mRecipe[i]->clone();			
		}
	}
	return 0;
}
