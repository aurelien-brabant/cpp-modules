#include <string>
#include <cmath>

using std::string;

// My stod implementation, as C++11 conversion utilities are not allowed since
// we're restricted to C++98's features.

double stod(string const & s)
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
