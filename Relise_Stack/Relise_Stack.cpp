#include <iostream>
#include<Windows.h>

using namespace std;

template<class T>
class List {
private:
	template <class T>
	class Node {
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	Node<T>* head;
	int size;

public:
	List();
	void push_front(T data);
	void pop_front();
	void print();

	void getSize() { return size; }
};

template <class T>
List<T>::List() {
	head = nullptr;
	size = 0;
}

template <typename T>
void List<T>::push_front(T data) {
	if (head == nullptr) {
		head = new Node<T>(data);

		size++;
	}
	else {
		Node<T>* current = new Node<T>(data);

		current->pNext = head;
		head = current;

		size++;
	}
}

template <typename T>
void List<T>::pop_front() {
	if (head != nullptr) {
		Node<T>* current = head;

		head = head->pNext;
		teil = teil->pPrev;

		delete current;
		current = nullptr;

		size--;
	}
}

template <typename T>
void List<T>::print() {
	if (head != nullptr) {
		Node<T>* current = head;
		for (int i = 0; i < size; i++) {
			cout << current->data << " ";
			if (current->pNext != nullptr)current = current->pNext;
		}
	}
	else cout << "List is empty";
	cout << endl;
}

int main() {

	List <int> lst;

	int choose = 0;

	while (choose != 3)
	{
		system("cls");
		lst.print();
		cin >> choose;
		switch (choose)
		{
		case 1:
			int num;
			cin >> num;
			lst.push_front(num);
			break;

		case 2:
			lst.pop_front();
			break;
		}
	}
	
	
	return 0; 

}