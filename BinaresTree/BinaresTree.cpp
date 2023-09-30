#include <iostream>
#include "Queue.h"
#include <windows.h>

using namespace std;
template<class T>
class Tree {
private:
	template<class T>
	class Node {
	public:
		T data;
		Node* Left, *Right;

		Node(T data = T(), Node* Left = nullptr, Node* Right = nullptr)
		{
			this->data = data;
			this->Left = Left;
			this->Right = Right;
		}
	};
	int Max_Deaph = 0;
	Node<T>* Root;
	//рекурсивные функции
	void addLeaf(T data, Node<T>* current);
	Node<T>* search(T data, Node<T>* current);
	void MaxDeaph(Node<T>* current, int count);
	void print(Node<T>* current);
	Tree<T>::Node<T>* Remove(Node<T>* current, T data);

public:
	Tree();
	//функции
	void addLeaf(T data);
	void printTree();
	void print();
	Tree<T>::Node<T>* search(T data);
	void Remove(T data);
	int MaxDeaph();
	int MinValue();
	int MaxValue();
	

};

template<class T>
Tree<T>::Tree()
{
	Root = nullptr;
}

template <typename T>
void Tree<T>::addLeaf(T data, Node<T>* current){
	if (current->data <= data) {
		if (current->Right == nullptr)current->Right = new Node<T>(data);
		else addLeaf(data, current->Right);
	}
	else
	{
		if (current->Left == nullptr)current->Left = new Node<T>(data);
		else addLeaf(data, current->Left);
	}
}

template <typename T>
void Tree<T>::addLeaf(T data) {
	if (Root == nullptr)Root = new Node<T>(data);

	else {
		addLeaf(data, Root);
	}
}

template <typename T>
Tree<T>::Node<T>* Tree<T>::search(T data) {
	return search(data, Root);
}

template <typename T>
Tree<T>::Node<T>* Tree<T>::search(T data, Node<T>*  current) {
	if (current->data > data && current->Left != nullptr) {
		current = current->Left;
		search(data, current);

	}
	else if (current->data < data && current->Right != nullptr) {
		current = current->Right;
		search(data, current);
	}
	else if (current->data == data)return current;
	else cout << endl << "Num is not search" << endl;
}

//print
template <typename T>
void Tree<T>::printTree() {
	int tabs;

	Queue<Tree<T>::Node<T>> qt;// создаём очередь с типом нашего дерева
	qt.push(Root);// добовляем в очередь первый элемент
	tabs = 1;
	for (int i = 0; i < MaxDeaph(); i++) {
		tabs *= 2;
	}
	int temp;// временая переменая
	Node<T>* current; //текущий элемент
	while (!qt.is_empty()) { // работает пока список не пустой
		temp = qt.getSize(); // temp сохраняет размер для правильного отображения
		for (int i = 0; i < temp; i++) { //for будет работать пока не отобразит все элементы текущего уровня

			if (qt.front() != nullptr) {
				current = qt.front();
				qt.pop();
				cout << current->data << "\t";


				qt.push(current->Left);
				qt.push(current->Right);
			}
			else {
				cout << "Null" << "\t";
				qt.pop();
			}
		}
		cout << endl;
	}
}

template <typename T>
void Tree<T>::print() {
	if (Root != nullptr)print(Root);
	else cout << "Tree is empty";
	cout << endl;
}

template <typename T>
void Tree<T>::print(Node<T>* current) {
	cout << current->data << " ";

	if (current->Left != nullptr)print(current->Left);
	if (current->Right != nullptr)print(current->Right);
}

template <typename T>
int Tree<T>::MaxDeaph() {
	if (Root == nullptr)return 0;

	int x = 0;
	MaxDeaph(Root, x);
	return Max_Deaph;

}

template <typename T>
void Tree<T>::MaxDeaph(Node<T>* current, int count) {
	if (current == nullptr)return;
	count++;

	if (current->Left != nullptr) {
		MaxDeaph(current->Left, count);
	}

	if (current->Right != nullptr) {
		MaxDeaph(current->Right, count);
	}
	if(current->Left == nullptr && current->Right == nullptr)
		if (count > Max_Deaph)Max_Deaph = count;
	}

template <typename T>
int Tree<T>::MinValue() {
	if (Root == nullptr)return 0;

	Node<T>* current = Root;

	while (current->Left != nullptr)current = current->Left;

	return current->data;
}

template <typename T>
int Tree<T>::MaxValue() {
	if (Root == nullptr)return 0;

	Node<T>* current = Root;

	while (current->Right != nullptr)current = current->Right;

	return current->data;
}

template <typename T>
void Tree<T>::Remove(T data){
	if (Root != nullptr) {
		if (Root->data == data) {
			Root = Remove(Root,data);
		}
		else {
			bool cheak = true;
			Node<T>* current = Root;

			while (cheak == true) {
				if (data >= current->data) {
					if (current->Right != nullptr) {
						if (current->Right->data != data){
							current = current->Right;
						}
						else cheak = false;
					}
					else cheak = false;
				}
				else {
					if (current->Left != nullptr){
						if (current->Left->data != data){
							current = current->Left;
						}
						else cheak = false;
					}
					else cheak = false;
				}
			}

			if (current->Left != nullptr) {
				if (current->Left->data == data){
					current->Left = Remove(current->Left, data);
				}
			}
			if (current->Right != nullptr) {
				if (current->Right->data == data) {
					current->Right = Remove(current->Right, data);
				}
			}

		}
	}
}

template <typename T>
Tree<T>::Node<T>* Tree<T>::Remove(Node<T>* current, T data) {
	if (current->data == data) {
		if (current->Left == nullptr && current->Right == nullptr) {
			delete current;
			current = nullptr;
			return current;
		}
		else if (current->Left != nullptr && current->Right == nullptr) {
			Node<T>* temp = current->Left;
			delete current;
			current = nullptr;
			return temp;
		}
		else {
			Node<T>* temp = current->Right;
			delete current;
			current = nullptr;
			return temp;
		}
	}

	return 0;
}

int main() {
	Tree<int> tr;

	tr.addLeaf(10);
	tr.addLeaf(5);
	tr.addLeaf(3);
	tr.addLeaf(3);
	tr.addLeaf(4);

	
	bool Work = true;
	int choose, num;

	while (Work == true) {
		system("cls");

		tr.print();
		cout << endl << "Plese enter num function\n(0)Exit\n(1)To add Element\n(2)To Remove Element" << endl;
		cin >> choose;
		switch (choose) {
		case 0:
			Work = false;
			break;
		case 1:
			do {
				system("cls");
				tr.print();

				cout << "Enter num what you wont to add Or enter 0 to exit"<<endl;
				cin >> num;
				if(num!=0)tr.addLeaf(num);
			} while (num != 0);
			break;
		case 2:
			do {
				system("cls");
				tr.print();

				cout << "Enter num what you wont to Remove Or enter 0 to exit" << endl;
				cin >> num;
				if (num != 0)tr.Remove(num);
			} while (num != 0);
			break;
		}

		system("pause");
	}
	
	return 0;
}
/*Список функций
	void addLeaf(T data); добавление обьектов
	void printTree();  вывод обьектов в виде дерева
	void print();  вывод обьектов
	Tree<T>::Node<T>* search(T data); Поиск обьекта
	void Remove(T data); удаление обьекта
	int MaxDeaph();  максимальная глубина ветки
	int MinValue(); максимальное число
	int MaxValue(); минимальное число
*/

