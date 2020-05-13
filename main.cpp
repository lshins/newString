#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cassert>
#include "newString.h"

using namespace std;

int main()
{
	newString s1("This is a test!"), s2("Hope this works...");
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "Length for s1: " << s1.length() << endl;
	cout << "Length for s2: " << s2.length() << endl;
	cout << endl;
	cout << "s1 + s2" << s1 + " " + s2 << endl;
	s2 += "maybe...";
	cout << endl;
	cout << "s2: " << s2 << endl;
	cout << endl;
	cout << "s1 + s2" << s1 + " " + s2 << endl;
	cout << endl;
	s2.changeChar(0, s2.length() - 1);
	cout << "s2: " << endl;
	return 0;
}