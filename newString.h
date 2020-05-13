#ifndef H_newString
#define H_newString

#include <iostream>

using namespace std;

class newString
{
	friend ostream& operator<<(ostream&, const newString&);
	friend istream& operator>>(istream&, newString&);

	char* strP;
	int strLength;

public:
	int length() const;
	const newString& operator=(const newString&);
	newString operator+(const newString&);
	newString operator+=(const newString&);
	void changeChar(int, int);
	newString(const char*);
	newString();
	newString(const newString&);
	~newString();
	char& operator[](int);
	const char& operator[](int) const;

	friend bool operator==(const newString&, const newString&);
	friend bool operator!=(const newString&, const newString&);
	friend bool operator<(const newString&, const newString&);
	friend bool operator<=(const newString&, const newString&);
	friend bool operator>(const newString&, const newString&);
	friend bool operator>=(const newString&, const newString&);
};

#endif