#include"LinkedList.h"
#include<iostream>
#include"Integer.h"

using namespace std;

int main(int argc, char*argv[]) {

	cout << "Hello World";
	LinkedList<Integer> list;
	Integer newInteger(5);
	list.insert(newInteger);
	cout<<list[0].getData();

	_getwch();
}