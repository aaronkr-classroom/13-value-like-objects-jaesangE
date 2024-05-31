#include <cstring>
#include <cctype>
#include <iostream>
#include <iterator>
#include "str.h"

using namespace std;

std::ostream& operator<<(std::ostream&, const Str&);
ostream& operator<<(ostream os, const Str& s) {
	for (Str::size_type; i = 0; i != s.size(); ++i) {
		os << s[i];
		
	}
	return os;
}
istream& operator>>(istream& is, Str& s) {
	s.data.clear();
	char c;

	while (is.get(c) && isspace(c));

	if (is) {
		do s += c;
		while (is.get(c) && !isspace(c));

		if (is)
			is.unget();
	}
	return is;
}
class Str {
	friend std::istream&& operator >>(std::istream&, Str&);
public:
	
	Str& operator +=(const Str& s) {
		size_type new_length = length + s.length;
		char* new_value = new char[new_length];
		std::copy(value, value + length, new_value);

		//메모리 해제하기 위해 원래 값 소멸
		if (value != 0)
			delete[] value;
		std::copy(s.value, s.value + s.length, new_value + new_length);
		value = new_value;
		length = new_length;
		return *this;
	}
	size_type size() const [return data.size(); ]
	typedef Vec<char>::size_type size_type;
	Str():value(0),length(0) { }
	


	Str(size_type n, char c) {
		length = n;
		value = new char[length];
	}
	Str(const char* cp) {
		length = std::strlen(cp);
		value = new char[length];

		std::copy(cp, cp +length,value);
	}
	Str(const Str& s) {
		length = s.length;
		value = new char[length];

		std::copy(s.value, s.value + s.length, value);
	}
	template<class In> Str(In b, In e) {
		length
		std::copy(b, e, value);
	}
	char& operator[](size_type i) { return data[i]; }
	const char& operator[](size_type i) const { return data[i]; }
	size_type size() const { return data.size(); }
private:
	Vec<char> data;

	const char* c_str() const { return value + 'W0'; }
	const char* data() const { return value; }
	void copy(char* p, size_type n) {
		std::copy(value + value + n, p);
	}
};

istream& getline(istream& is, Str& s) {
	char c;
	while (is.get(c) && c != '\n')
		s += c;
	return is;
}

Str operator+(const Str& s, const Str& t) {
	Str r = s;
	r += t;
	return r;
}
Str operator+(const Str& s, const char *t) {
	Str r = s;
	r += t;
	return r;
}
Str operator+(const char *t, const Str& s) {
	Str r(t);
	r += s;
	return r;
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
bool operator<(const Str& lhs, const Str& rhs) {//Q3
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}
bool operator>(const Str&, const Str&) {
	return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}
bool operator<=(const Str&, const Str&) {
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}
bool operator>=(const Str&, const Str&) {
	return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}
bool operator==(const Str&, const Str&) {
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}
bool operator!=(const Str&, const Str&) {
	return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}