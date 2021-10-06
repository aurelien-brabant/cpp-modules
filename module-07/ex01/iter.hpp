template<typename T>
void iter(T * arrayLoc, size_t length, void (*fn)(const T&))
{
	for (size_t i = 0; i != length; ++i) {
			fn(arrayLoc[i]);
	}	
}

template<typename T>
void iter(T * arrayLoc, size_t length, void (*fn)(T&))
{
	for (size_t i = 0; i != length; ++i) {
			fn(arrayLoc[i]);
	}	
}
