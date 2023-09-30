#include <iostream>
#include "MyString.h"
using namespace std;

int main() {

	MyString str("Hello");
	MyString str2 = "World";
	MyString conct = str + str2;

	conct.Print();

	return 0;
}
