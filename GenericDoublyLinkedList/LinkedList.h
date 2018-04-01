#include "Node.h"

template<typename T>
class LinkedList
{
	Node<T> *head;
	Node<T> *tail;
	size_t size;
public:
	LinkedList();
	LinkedList(const size_t s);
	LinkedList(const LinkedList& rhs);

	LinkedList<T>& operator=(const LinkedList& rhs);
	T& operator[](const size_t index);

	bool insert(const T& value);
	bool insert(const size_t position, const T& value);

	bool remove(const size_t position);

	size_t getSize();
	Node<T>* getHead();
	void deleteList();
	~LinkedList();
};

