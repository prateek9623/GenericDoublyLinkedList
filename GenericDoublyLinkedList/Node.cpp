#include "Node.h"

template<typename T>
Node<T>::Node() :mData(nullptr), mPrev(nullptr), mNext(nullptr) {}

template<typename T>
Node<T>::Node(const T &data) : mData(data), mPrev(nullptr), mNext(nullptr) {}

template<typename T>
Node<T>::Node(const Node<T>* node) : mData(node->mData), mPrev(node->mPrev), mNext(node->mNext) {}

template<typename T>
Node<T> * Node<T>::getNext()
{
	return mNext;
}

template<typename T>
void Node<T>::setNext(Node *next)
{
	mNext = next;
}

template<typename T>
Node<T> * Node<T>::getPrev()
{
	return mPrev;
}

template<typename T>
void Node<T>::setPrev(Node *prev)
{
	mPrev = prev;
}

template<typename T>
void Node<T>::setData(Node * data)
{
	mData = data;
}

template<typename T>
T * Node<T>::getData()
{
	return mData;
}

template<typename T>
Node<T>::~Node()
{
	delete mData;
}
