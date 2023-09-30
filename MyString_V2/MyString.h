#ifndef MyString_h
#define MyString_h
class MyString {
private:
	char* str;
	int length;
public:
	//Конструкторы и деструкторы
	MyString();
	MyString(const char* str);
	MyString(const MyString& other);
	MyString(MyString&& other);

	~MyString();
	//
	//конструктор присваивания
	MyString operator=(const char* str);
	//конструктор копирования 
	MyString operator=(const MyString& other);
	//конструктор конкатенации
	MyString operator+(const MyString& other);
	//конструктор равенства
	bool operator==(MyString& other);
	//конструктор неравенства
	bool operator != (MyString& other);
	//конструктор индексации
	char& operator [](int i);
	//
	
	//Методы
	int Lenght(const char* str);

	void Print();
	//
};
#endif 

