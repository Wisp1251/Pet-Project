#ifndef Queue_H
#define Queue_H
template<class T>
class Queue
{
private:
	class Node {
	public:
		T *data;
		Node *pNext;
		Node *pPrev;

		Node(T* data = nullptr, Node* pNext = nullptr, Node* pPrev = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
	};
	Node *head;
	Node *teil;
	int size;

public:
	Queue();
	void push(T* data);//add ellement in back
	void pop();// remove ellement in front
	T* front();// give ellement in front
	bool is_empty();// check empty is queue
	int getSize();
};

template<typename T>
Queue<T>::Queue() {
	head = nullptr;
	teil = nullptr;
	size = 0;
}

template<typename T>
void Queue<T>::push(T* data) {
	if (teil == nullptr) {
		teil = new Node(data);
		head = teil;
	}
	else {
		Node* current = teil;
		teil = new Node(data);
		teil->pPrev = current;
		current->pNext = teil;

		current = nullptr;
	}
	size++;
}
template<class T>
T* Queue<T>::front() {
	if (!is_empty()) {
		return head->data;
	}
	else return 0;
}
template<class T>
void Queue<T>::pop() {
	if (!is_empty()) {
		Node* current = head;
		head = head->pNext;
		if (head != nullptr)head->pPrev = nullptr;
		else  teil = nullptr;

		delete current;
		current = nullptr;

		size--;
	}
}

template<class T>
bool Queue<T>::is_empty() {
	if (head == nullptr)return true;
	else return false;
}

template<class T>
int Queue<T>::getSize() {
	return size;
}

#endif