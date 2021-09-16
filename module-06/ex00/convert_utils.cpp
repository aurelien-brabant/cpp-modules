#include <string>
#include <cmath>
#include <iostream>

using std::string;

// My stod implementation, as C++11 conversion utilities are not allowed since
// we're restricted to C++98's features.

double ft_stod(string const & s)
{
	double d = 0.0;
	int sign = 1;
	size_t i = 0;

	if (s.size() != 0 && (s[i] == '+' || s[i] == '-')) {
		if (s[i++] == '-') {
			sign = -1;
		}
	}

	for (; i != s.size(); ++i) {
		if (s[i] != '.') {
			d = d * 10 + s[i] - 48;
		}
	}

	size_t floatingPointIndex = s.find('.');

	if (floatingPointIndex != string::npos) {
		d /= pow(10, s.size() - 1 - floatingPointIndex);
	}

	return d * sign;
}

float ft_stof(string const & s)
{
	string trimmed(s);
	size_t i = string::npos;

	if ((i = s.find('f')) != string::npos) {
		if (i != s.size() - 1) {
			return 0.0f;
		}
		trimmed.erase(i, 1);
	}

	return ft_stod(trimmed);
}
