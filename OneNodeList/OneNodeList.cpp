#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using namespace std;

class List {
private:
	class Node {
	public:
		Node* pNext;
		int data;

		Node(int data = 0, Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int Size;
	Node* head;
public:
	List()
	{
		Size = 0;
		head = nullptr;
	}

	void push_front(int data) {
		Node* current = new Node(data);
		current->pNext = head;
		head = current;

		Size++;
	}

	void push(int i, int data) {
		if (Size >= i) {
			Node* temp = new Node(data);
			Node* current = head;
			int count = 0;

			while (count != i - 1) {
				current = current->pNext;
				count++;
			}
			temp->pNext = current->pNext;
			current->pNext = temp;

			Size++;
		}
	}

	void push_back(int data) {
		if (head == nullptr)
		{
			head = new Node(data);
		}
		else
		{
			Node* current = head;

			while (current->pNext != nullptr)
			{
				current = current->pNext;
			}
			current->pNext = new Node(data);
		}
		Size++;
	}

	void pop_back() {
		Node* current = head;

		while (current->pNext->pNext != nullptr)
		{
			current = current->pNext;
		}
		//delete current->pNext->pNext;
		current->pNext = nullptr;
		Size--;
	}

	void pop_front() {
		head = head->pNext;
		Size--;
	}

	void pop(int i) {
		if (Size > i) {

			int count = 0;
			Node* current = head;

			while (count < i - 1) {
				current = current->pNext;
				count++;
			}
			current->pNext = current->pNext->pNext;
			Size--;
		}
		else cout << "Error you enter number more then size" << endl;
	}

	int GetSize() { return Size; }

	int& operator[](int i)
	{
		int count = 0;
		Node* current = head;

		while (count != i) {
			current = current->pNext;
			count++;
		}
		return current->data;
	}

	int* InArr() {
		int* arr = new int[Size];
		Node* current = head;

		for (int i = 0; i < Size; i++) {
			arr[i] = current->data;
			current = current->pNext;
		}

		return arr;
	}

	void print() {
		if (head != nullptr) {
			Node* current = head;
			for (int i = 0; i < Size; i++) {
				cout << current->data << " ";
				current = current->pNext;
			}
			cout << endl;
		}
		else cout << "is empty" << endl;
	}
};

//print
void print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//buble sort
void BubleSort(int* arr, int size)
{
	int temp = 0;

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {
	srand(time(NULL));

	List lst;

	int data;
	int i;

	bool work = true;

	int choose;
	while (work == true) {

		system("cls");

		cout << "List: ";
		lst.print();

		cout << "Choose you wont function: push(1)\tpush_front(2)\tpush_back(3)\t" << endl;
		cout << "\t\t\tpop(4)\tpop_front(5)\tpop_back(6)\tExit(7)" << endl;

		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "Enter number: ";
			cin >> i;
			cout << "Enter data: ";
			cin >> data;
			lst.push(i, data);
			break;

		case 2:
			cout << "Enter data: ";
			cin >> data;
			lst.push_front(data);
			break;

		case 3:
			cout << "Enter data: ";
			cin >> data;
			lst.push_back(data);
			break;

		case 4:
			cout << "Enter number: ";
			cin >> i;
			lst.pop(i);
			break;

		case 5:
			lst.pop_front();
			break;

		case 6:
			lst.pop_back();
			break;

		case 7:
			work = false;
			break;
		}


		system("pause");
	}

	return 0;
}