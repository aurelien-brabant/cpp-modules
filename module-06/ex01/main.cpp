#include <iostream>
#include "serialization.hpp"

using std::cout;

int main(void)
{
	Data *book = new Data("Vingt-mille lieux sous les mers", 234);

	cout << "not serialized book: \n" << *book << "\n";

	uintptr_t serializedBook = serialize(book);

	cout << "serialized book: \n" << serializedBook << "\n";

	Data *deserializedBook = deserialize(serializedBook);

	cout << "deserialized book: \n" << *deserializedBook << "\n";

	if (deserializedBook == book) {
		cout << "Pointers are equal\n";
	}

	delete book; 
	
	return 0;
}
