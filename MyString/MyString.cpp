#include <iostream>

using namespace std;

class MyString {
private:
	char* str;
	int length;
public:

	//Конструкторы и деструкторы
	MyString(){
		str = nullptr;
		length = 0;
	}


	MyString(const char* str){
		length = Lenght(str);

		this->str = new char[length+1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}
		this->str[length] = '\0';
	}
	
	MyString(const MyString& other) {
		length = other.length;

		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';
	}

	MyString(MyString&& other) {
		this->length = other.length;
		this->str = other.str;
		other.str = nullptr;
	}

	~MyString() {
		delete[] this->str;
	}

	//конструктор присваивания
	MyString operator=(const char* str){
		if (this->str != nullptr)
		{
			delete[] this->str;
			length = 0;
		}

		length = Lenght(str);

		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}
		this->str[length] = '\0';
		
		return this->str;
	}
	//конструктор копирования 
	MyString operator=(const MyString &other) {
		if (this->str != nullptr)
		{
			delete[] this->str;
			length = 0;
		}
		length = other.length;

		this->str = new char[length+1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';

		return this->str;

	}
	//конструктор конкатенации
	MyString operator+(const MyString &other)
	{
		MyString res;
		res.length = length + other.length;

		res.str = new char[res.length+1];

		int i = 0;
		for (; i < length; i++) {
			res.str[i] = this->str[i];
		}
		for (; i < res.length; i++) {
			res.str[i] = other.str[i-length];
		}
		res.str[res.length] = '\0';
		return res;
	}

	bool operator==(MyString &other) {
		if (length != other.length)
			return false;

		for (int i = 0; i < length; i++)
		{
			if (this->str[i] != other.str[i])
				return false;
		}
		return true;
	}

	bool operator != (MyString& other) {
		return !(this->operator==(other));
	}

	char& operator [](int i) {
		return this->str[i];
	}


	//Методы
	int i = 0;
	int Lenght(const char *str) {
		while(str[i] !='\0') {
			i++;
		}
		return i;
	}

	void Print() {
		cout << str;
	}
};

int main() {
	MyString str("Hello ");
	MyString str2 = "World";
	MyString conct;
	conct = str + str2;

	conct.Print();

	return 0;
}