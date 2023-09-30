#ifndef MyString_h
#define MyString_h
class MyString {
private:
	char* str;
	int length;
public:
	//������������ � �����������
	MyString();
	MyString(const char* str);
	MyString(const MyString& other);
	MyString(MyString&& other);

	~MyString();
	//
	//����������� ������������
	MyString operator=(const char* str);
	//����������� ����������� 
	MyString operator=(const MyString& other);
	//����������� ������������
	MyString operator+(const MyString& other);
	//����������� ���������
	bool operator==(MyString& other);
	//����������� �����������
	bool operator != (MyString& other);
	//����������� ����������
	char& operator [](int i);
	//
	
	//������
	int Lenght(const char* str);

	void Print();
	//
};
#endif 

