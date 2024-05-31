
#ifndef GUARD_str_h
#define GUARD_str_h
Str(const Str& s) {
	length = s.length;
	value = new char[length];

	std::copy(s.value, s.value + s.length, new_value);
}

Str operator +=(const char c) {
	size_type new_length = length + 1;
	char* new_value = new char[new_length];
	std::copy(value, value + length, new_length);

	if (value != 0)
		delete[] value;
	//char 추가
	new_value[length] = c;
	value = new_value;
	length = new_length;
	return *this;
}
Str operator +=(const char *c) {
	size_type new_length = length + strlen(c);
	char* new_value = new char[new_length];
	std::copy(value, value + length, new_length);

	if (value != 0)
		delete[] value;
	//char 추가
	std::copy(c, c + strlen(c), new_value + length);
	value = new_value;
	length = new_length;
	return *this;
}

//Q11 (할당 연산자)
Str& operator =(const Str&, rhs) {
	if (&rhs != this) {
		if (value != 0) {
			delete[] value;
		}
		length = rhs.length;
		value = new char[length];
		std::copy(rhs.begin(), rhs.end(), value);
	}
	return *this;
}


//Q7
typedef char* iterator;
typedef const char* const_iterator;

std::ostream& operator <<(std::ostream&, const Str&);
std::istream& getline(std::istream_iterator&, const Str&);

Str operator +(const Str&, const Str&);
Str operator +(const Str&, const char *);
Str operator +(const char *, const Str&);



bool operator<(const Str&, const Str&);
bool operator>(const Str&, const Str&);
bool operator<=(const Str&, const Str&);
bool operator>=(const Str&, const Str&);
bool operator==(const Str&, const Str&);
bool operator!=(const Str&, const Str&);
#endif // DEBUG
