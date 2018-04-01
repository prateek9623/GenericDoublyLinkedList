#include "LinkedList.h"

template<typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

template<typename T>
LinkedList<T>::LinkedList(const size_t s) : head(nullptr), tail(nullptr), size(s)
{
	Node<T> newNode = new Node
		Node<T> *node = &newNode;
	for (size_t i = 0; i < size; i++) {
		node->setNext(new Node<T>);
		node = node->getNext();
	}
	this->head = newNode
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList & rhs)
{
	LinkedList::operator=(rhs);
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList & rhs)
{
	deleteList();
	size = rhs.getSize();
	Node<T> temp;
	for (Node<T>* nodePtr = rhs.getHead(), *newList = &temp; nodePtr; nodePtr = nodePtr->getNext()) {
		Node<T> newNode(nodePtr);
		newNode->setPrev(newList);
		newList->setNext(newNode);
		newList = newList->getNext();
	}
	this->head = temp.getNext();
	return *this;
}

template<typename T>
T & LinkedList<T>::operator[](const size_t index)
{
	Node<T>* nodePtr = head;
	if (index < 0 || index >= this->size) {
		std::cout << "ERROR: Subscript out of range.\n";
		exit(EXIT_FAILURE);
	}
	else {
		for (size_t i = 0; i < index; i++)
			nodePtr = nodePtr->getNext();
	}
	return nodePtr->getData();
}

template<typename T>
bool LinkedList<T>::insert(const T & value)
{
	Node<T>* newNode = new Node<T>(value);
	if (newNode == nullptr)
		return false;

	if (head == nullptr)
		head = newNode;
	else {
		Node<T>* nodePtr = head;
		while (nodePtr->getNext()!=nullptr) {
			nodePtr = nodePtr->getNext();
		}
		nodePtr->setNext(newNode);
		newNode->setPrev(nodePtr);
	}
	++size;
	return true;
}

template<typename T>
bool LinkedList<T>::insert(const size_t position, const T & value)
{
	if(position>size||position<0)
		return false;

	Node * newNode = new Node(value);
	if (newNode == nullptr) {
		return false;
	}
	if (position == 1) {
		if (head != NULL) {
			newNode->setNext(head);
			head->setPrev(newNode);
		}
		head = newNode;
		size++;
		return true;
	}

	Node * prev = head;
	for (int i = 1; i < position - 1; i++) {

		prev = prev->getNext();

		if (prev == NULL) {
			delete newNode;
			return false;
		}
	}

	newNode->setPrev(prev);
	if (prev->getNext()) {
		newNode->setNext(prev->getNext());
		prev->getNext()->setPrev(newNode);
	}
	prev->setNext(newNode);
	size++;
	return true;
}

template<typename T>
bool LinkedList<T>::remove(const size_t position)
{
	if (position <= 0 || head == NULL) {
		return false;
	}

	if (position == 1) {

		Node<T> * del = head;
		head = head->getNext();
		if (head != NULL) {
			head->setPrev(NULL);
		}
		delete del;
		--size;
		return true;
	}

	Node<T> * del = head;
	for (int i = 1; i < position; i++) {
		del = del->getNext();
		if (del == NULL) {
			return false;
		}
	}

	del->getPrev()->setNext(del->getNext());
	if (del->getNext()) {
		del->getNext()->setPrev(del->getPrev());
	}

	delete del;
	--size;
	return true;
}

template<typename T>
size_t LinkedList<T>::getSize()
{
	return size;
}

template<typename T>
Node<T>* LinkedList<T>::getHead()
{
	return head;
}

template<typename T>
void LinkedList<T>::deleteList()
{
	Node<T>* nodePtr = head;
	while (nodePtr != nullptr) {
		Node<T>* nextNode = nodePtr->getNext();
		delete nodePtr;
		nodePtr = nextNode;
	}
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	deleteList();
}
