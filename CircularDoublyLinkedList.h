//klepple 250836229
#pragma once
#include <assert.h>
#include<ctime>

template <class T>
class CircularDoublyLinkedList {
private:
	class Node {//Nodes for CDLL
	public:
		Node(T val, Node * nx = nullptr, Node * pv = nullptr) : value(val), next(nx), prev(pv) { }
		T value;//Value in node
		Node * prev;//Points to previous node
		Node * next;//Points to next node
	};
public:
	class Iterator {
	private: Node* m_ptr; //Iterator hides the pointer to a node
	public: Iterator(Node* ptr) { m_ptr = ptr; }
			void operator ++ () { m_ptr = m_ptr->next; }//Overload ++ to move to next node
			void operator --() { m_ptr = m_ptr->prev; }//Overload -- to move to previous node
			bool operator != (const Iterator& b) { return m_ptr != b.m_ptr; }//Overload != to check if nodes are not equal
			T getValue() { return m_ptr->value; }//Returns the value of the node
			void setValue(T val) { m_ptr->value = val; }//Sets the value of a node
	};

private:
	Node * m_head;
	Node * m_tail;
	unsigned int m_size;
public:
	Iterator begin() const{ return Iterator(m_head); }//Returns the first iterator of the CDLL
	Iterator end() { return Iterator(NULL); }

	CircularDoublyLinkedList();//Default Constructor
	~CircularDoublyLinkedList();//Destructor
	
	unsigned int size();//Returns size of CDLL
	void addHead(T item);//Add item to front
	void addTail(T item); //Add item to back
	void addNode(unsigned int n, T item);//Add item
	T retrieveHead();//Returns value in front
	T retrieveTail();//Returns value in back
	T retrieveNode(int index);//Returns item
	T removeHead();//Removes head node and returns its value
	T removeTail();//Removes tail node and returns its value
	T removeNode();//Removes node and returns its value
	T replace(unsigned int n, T item);//Replaces the value in a node and returns the replaced value
	void sLeft();//Shifts the head and tail nodes left by one
	void sRight();//Shifts the head and tail nodes right by one
	bool isEmpty();//Checks if the CDLL is empty and returns true if it is
	void CircularDoublyLinkedList<T>::swap(Iterator a, Iterator b);//Swaps the values of two nodes using iterators
};

template<class T>
CircularDoublyLinkedList<T>::CircularDoublyLinkedList() :m_head(nullptr), m_tail(nullptr), m_size(0) {}

template <class T>
CircularDoublyLinkedList<T>::~CircularDoublyLinkedList() {
	Node * here = m_head, * nextNode;
	for (int i = 0; i < m_size; i++) {
		nextNode = here->next;
		delete here;
		here = nextNode;
	}
}

template <class T>
unsigned int CircularDoublyLinkedList<T>::size(){
	return m_size;
}

template <class T>
void CircularDoublyLinkedList<T> ::addHead(T item){
	m_head = new Node(item, m_head, nullptr);
	if (m_tail == nullptr) {
		m_tail = m_head;
	}
	m_size++;
}

template <class T>
void CircularDoublyLinkedList<T>::addTail(T item) {
	if (m_size == 0){
		addHead(item);
	}
	else{
		Node *temp = new Node(item, m_head, m_tail);
		m_tail->next = temp;
		m_head->prev = temp;
		m_tail = temp;
		m_size++;
	}
}
template <class T>
void CircularDoublyLinkedList<T>::addNode(unsigned int n, T item) {
	if (n < 1 || n > (size() + 1)) {
		cout << "Out of bounds!" << endl;
	}
	if (n == 1) {
		addHead(item);
	}
	else if (n == (size() + 1)) {
		addTail(item);
	}
	else
	{
		Node * here = m_head;
		for (unsigned int k = 1; k < n - 1; k++) {
			here = here->next;
		}
		Node * temp = new Node(item, here->next, here);
		here->next = temp;
		here = temp;
		m_size++;
	}
}

template <class T>
bool CircularDoublyLinkedList<T>::isEmpty(){
	return (m_size == 0);
}

template<class T>
T CircularDoublyLinkedList<T>::retrieveHead(){
	if (isEmpty()) {
		cout << "Empty!!(retrieve head)" << endl;
	}
	return m_head->value;
}

template<class T>
T CircularDoublyLinkedList<T>::retrieveTail(){
	if (isEmpty()) {
		cout << "Empty!!(retrieve tail)" << endl;
	}
	return m_tail->value;
}

template <class T>
T CircularDoublyLinkedList<T>::retrieveNode(int index) {
	if (index < 1 || index >(size() + 1)) {
		cout << "Out of bounds!" << endl;
	}
	else {
		if (index == 1) return retrieveHead();
		if (index == size()) return retrieveTail();
		Node * here = m_head;
		for (unsigned int k = 1; k < index; k++) {
			here = here->next;
		}
		return here->value;
	}

}

template<class T>
T CircularDoublyLinkedList<T>::removeHead(){
	if (isEmpty())
	{
		cout << "Empty!!(remove head)" << endl;
	}
	Node * oldNode = m_head;
	T returnVal = m_head->value;
	m_head = m_head->next;
	if (m_head == nullptr) {
		m_tail = nullptr;
	}
	m_head->prev = m_tail;
	m_tail->next = m_head;
	m_size--;
	delete oldNode;
	return returnVal;
}

template<class T>
T CircularDoublyLinkedList<T>::removeTail(){
	if (isEmpty())
	{
		cout << "Empty!!(remove head)" << endl;
	}
	if (m_head == m_tail) {
		return removeHead();
	}
	else {
		T returnVal = m_tail->value;
		Node * preTail = m_head;
		while (preTail->next != m_tail) {
			preTail = preTail->next;
		}
		preTail->next = nullptr;
		delete m_tail;
		m_tail = preTail;
		m_tail->next = m_head;
		m_head->prev = m_tail;
		m_size--;
		return returnVal;
	}
}

template<class T>
T CircularDoublyLinkedList<T>::removeNode(){
	if (n == 1) {
		return removeHead();
	}
	if (n == size()) {
		return removeTail();
	}
	Node * here = m_head;
	for (unsigned int k = 1; k < n - 1; k++) {
		here = here->next;
	}
	Node * kill = here->next;
	T returnVal = kill->value;
	here->next = kill->next;
	delete kill;
	m_size--;
	return returnVal;
}

template<class T>
T CircularDoublyLinkedList<T>::replace(unsigned int n, T item) {
	if (n < 1 || n >(size() + 1)) {
		cout << "Out of bounds!" << endl;
	}
	T returnValue;
	Node * here = m_head;
	for (unsigned int k = 1; k < n; k++) {
		here = here->next;
	}
	returnValue = here->value;
	here->value = item;
	return returnValue;
}

template<class T>
void CircularDoublyLinkedList<T>::sLeft() {
	m_head = m_head->next;
	m_tail = m_tail->next;
}

template<class T>
void CircularDoublyLinkedList<T>::sRight() {
	m_head = m_head->prev;
	m_tail = m_tail->prev;
}

template<class T>
void CircularDoublyLinkedList<T>::swap(Iterator a, Iterator b) {
	T temp = a.getValue();
	a.setValue(b.getValue());
	b.setValue(temp);
}