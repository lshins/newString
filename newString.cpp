#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cassert>
#include "newString.h"

using namespace std;

int newString::length() const
{
	return (strLength);
}

newString::newString(const char* str)
{
	strLength = strlen(str);
	delete[] strP; //check
	strP = new char[strLength + 1];
	strcpy(strP, str);
}

newString::newString()
{
	strLength = 0;
	delete[] strP; //check
	strP = new char[1];
	strcpy(strP, "");
}

newString::newString(const newString& rightStr)
{
	strLength = rightStr.strLength;
	delete[] strP; //check
	strP = new char[strLength + 1];
	strcpy(strP, rightStr.strP);
}

newString::~newString()
{
	delete[] strP;
}

const newString& newString::operator=(const newString& rightStr)
{
	if (this != &rightStr)
	{
		delete[] strP;
		strLength = rightStr.strLength;
		strP = new char[strLength + 1];
		strcpy(strP, rightStr.strP);
	}
	return *this;
}

newString newString::operator+(const newString& rightStr)
{
	newString temp;
	temp.strLength = strLength + rightStr.strLength;
	delete[] temp.strP;
	temp.strP = new char[temp.strLength + 1];
	for (int i = 0; i <= strLength; i++)
		temp.strP[i] = strP[i];
	for (int j = strLength + 1; j <= temp.strLength; j++)
		temp.strP[j] = rightStr.strP[j];
	return temp;
}

newString newString::operator+=(const newString& rightStr)
{
	int prevLength = strLength;
	strLength += rightStr.strLength;
	delete[] strP;
	strP = new char[strLength + 1];
	for (int j = prevLength + 1; j <= strLength; j++)
		strP[j] = rightStr.strP[j];
	return *this; //check
}

void newString::changeChar(int n, int m)
{
	char c;
	cout << "Input the desired character which should replace the indexed character." << endl << endl;
	cin >> c;
	cout << endl;
	if (0 <= n && m < strLength)
		strP[n + m] = c;
	else
	{
		while (0 > n || m >= strLength)
		{
			cout << "Invalid parameters. Please reinput valid values of n (starting index) and m (number of indices after n)." << endl;
			cout << "Value of n (should be at least 0 and less than " << strLength << "." << endl << endl;
			cin >> n;
			cout << endl;
			cout << "Value of m (should be at least 0 and less than " << strLength - n << "." << endl << endl;
			cin >> m;
			cout << endl;
		}
		strP[n + m] = c;
	}
}

char& newString::operator[](int index)
{
	assert(0 <= index && index < strLength);
	return strP[index];
}

const char& newString::operator[](int index) const
{
	assert(0 <= index && index < strLength);
	return strP[index];
}

bool operator==(const newString& leftStr, const newString& rightStr)
{
	return (strcmp(leftStr.strP, rightStr.strP) == 0);
}

bool operator!=(const newString& leftStr, const newString& rightStr)
{
	return (strcmp(leftStr.strP, rightStr.strP) != 0);
}

bool operator<(const newString& leftStr, const newString& rightStr)
{
	return (strcmp(leftStr.strP, rightStr.strP) < 0);
}

bool operator<=(const newString& leftStr, const newString& rightStr)
{
	return (strcmp(leftStr.strP, rightStr.strP) <= 0);
}

bool operator>(const newString& leftStr, const newString& rightStr)
{
	return (strcmp(leftStr.strP, rightStr.strP) > 0);
}

bool operator>=(const newString& leftStr, const newString& rightStr)
{
	return (strcmp(leftStr.strP, rightStr.strP) >= 0);
}

ostream& operator<<(ostream& cout, const newString& str)
{
	cout << str.strP;
	return cout;
}

istream& operator>>(istream& cin, newString& str)
{
	char temp[81];
	cin >> setw(81) >> temp;
	str = temp;
	return cin;
}