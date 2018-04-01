template<typename T>
class Node
{
	Node<T> *mPrev;
	Node<T> *mNext;
	T *mData;
public:
	Node();
	Node(const T);
	Node(const Node<T>*);
	Node* getNext();
	void setNext(Node*);
	Node* getPrev();
	void setPrev(Node*);
	void setData(Node*);
	T* getData();
	~Node();
};
