#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class List {
private:
	class Node {
	public:
		Node* pNext;
		Node* pPrev;
		int data;

		Node(int data = 0, Node* pNext = nullptr, Node* pPrev = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
	};

	int size;
	Node* head;
	Node* teil;

public:
	List()
	{
		size = 0;
		head = nullptr;
		teil = nullptr;
	}

	//прототипы
	void print();
	void push_back(int data);
	void push_front(int data);
	void pop_back();
	void pop_front();
	void insert(int i, int data);
	void del(int i);
};
//реализация
void List::print(){
	Node* current = head;

	for (int i = 0; i < size; i++)
	{
		cout << current->data << " ";
		current = current->pNext;
	}
	cout << endl;
}

void List::push_back(int data){
	if (head == nullptr) {
		head = new Node(data);
	}
	else
	{
		Node* current = head;

		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node(data);
		current->pNext->pPrev = current;
		teil = current->pNext;

		
	}
	size++;
}

void List::push_front(int data) {
	if (head == nullptr) {
		head = new Node(data);
	}
	else
	{
		Node* current = new Node(data);
		current->pNext = head;
		head->pPrev = current;
		head = current;
	}
	size++;
}

void List::pop_back() {
	if (head != nullptr) {

		Node* current = head;

		while(current->pNext->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = nullptr;
		delete teil;
		teil = current;

		size--;
	}
}

void List::pop_front() {
	if (head != nullptr) {

		Node* current = head;

		current = current->pNext;
		
		current->pPrev = nullptr;
		delete head;
		head = current;

		size--;
	}
}

void List::insert(int i, int data) {
	if (head == nullptr) {
		head = new Node(data);
	}
	else {
		int count = 0;
		Node* temp = new Node(data);
		Node* current = head;

		while (count < i - 1) {
			current = current->pNext;
			count++;
		}
		temp->pPrev = current;
		if (current->pNext != nullptr) {
			temp->pNext = current->pNext;
			current->pNext->pPrev = temp;
		}

		current->pNext = temp;
	}
	size++;
}

void List::del(int i) {
	if (head != nullptr) {

		int count = 0;
		Node* current = head;
		Node* temp;

		while (count < i - 1) {
			current = current->pNext;
			count++;
		}

		temp = current->pNext;
		
		current->pNext->pPrev = current;
		current->pNext = current->pNext->pNext;

		delete temp;

		size--;
	}
}

int main() {
	List lst;

	for (int i = 0; i < 5; i++)
	{
		lst.insert(i,i+1);
	}

	lst.insert(2, 44);
	lst.insert(6, 333);

	lst.del(2);
	lst.del(5);

	lst.print();

	return 0;
}