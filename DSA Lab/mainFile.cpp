#include <iostream>
using namespace std;
#include "list.cpp"
int main() {
	// Test File
	list myLinkList;
	myLinkList.insert(10);
	myLinkList.insert(10);
	myLinkList.back();
	myLinkList.insert(60);
	myLinkList.insertAtBegin(20);
	myLinkList.insert(60);
	myLinkList.display();

	myLinkList.deleteByValue(60);

	myLinkList.display();
	system("pause");
}