#include"LinkedList.h"
#include<iostream>
#include"Integer.h"

using namespace std;

int main(int argc, char*argv[]) {

	cout << "Hello World";
	LinkedList<Integer> list;
	Integer value(5);
	list.insert(value);
	Integer value2(6);
	list.insert(value2);
	cout << endl << list[0].getData();
	cout << endl << list[1].getData();
	LinkedList<Integer> list2(list);
	LinkedList<Integer> list3;
	list3 = list;
	list3.insert(100);
	list2[0] = list[0].getData()+list2[1].getData();
	cout << endl << list2[0].getData();
	cout << endl << list2[1].getData();
	cout << endl << list3[0].getData();
	cout << endl << list3[1].getData();
	cout << endl << list3[2].getData();
	_getwch();
}