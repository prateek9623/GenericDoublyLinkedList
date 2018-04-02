#include"LinkedList.h"
#include<iostream>
#include"Integer.h"

using namespace std;

int main(int argc, char*argv[]) {

	cout << "Hello World";
	LinkedList<Integer> list;
	Integer *value = new Integer(5);
	list.insert(value);
	value = new Integer(7);
	list.insert(value);
	cout << endl << list[0]->getData();
	cout << endl << list[1]->getData();

	_getwch();
}