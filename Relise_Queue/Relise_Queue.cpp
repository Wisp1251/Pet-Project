#include <iostream>
#include <windows.h>

using namespace std;

template <class T>
class List {
private:
	template <class T>
	class Node {
	public:

		Node* pNext;
		Node* pPrev;
		T data;

		Node(T data = T(), Node* pNext = nullptr, Node* pPrev = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
	};
	Node<T>* head;
	Node<T>* teil;
	int size;

public:
	List();
	void print();
	void push_back(T data);
	void pop_front();
};

template <class T>
List<T>::List() {
	head = nullptr;
	teil = nullptr;
	size = 0;
}

template <typename T>
void List<T>::print() {
	if (head != nullptr) {
		Node<T>* current = head;
		for (int i = 0; i < size; i++) {
			cout << current->data<<" ";
			if (current->pNext != nullptr)current = current->pNext;
		}
	}
	else cout << "List is empty";
	cout << endl;
}

/*template <typename T>
void List<T>::push_back(T data) {
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* current = head;

		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
		current->pNext->pPrev = current;
		teil = current->pNext;
	}
	size++;
}*/

template <typename T>
void List<T>::push_back(T data) {
	if (teil == nullptr) {
		teil = new Node<T>(data);
		head = teil;
	}
	else {
		Node<T>* current = new Node<T>(data);
		current->pPrev = teil;
		teil->pNext = current;
		teil = current;
	}
	size++;
}

template <typename T>
void List<T>::pop_front() {
	if (head != nullptr) {
		Node<T>* current = head;
		head = head->pNext;
		current->pPrev = nullptr;
		
		if (teil->pPrev == nullptr)teil = nullptr;

		delete current;
		current = nullptr;

		size--;
	}
}

int main() {
	List <int> lst;

	int choose = 0;

	while (choose != 3)
	{
		system("cls");
		lst.print();
		cout << "Enter 1 to add ellement" << endl << "Enter 2 to delete element" << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
			int num;
			cout << "Enter num to add ellement" << endl;
			cin >> num;
			lst.push_back(num);
			break;

		case 2:
			lst.pop_front();
			break;
		}
	}
	return 0;
}