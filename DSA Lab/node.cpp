class Node {
	int value;
	Node* next, * prev;
public:
	// To set the int value
	void setValue(int v) {
		value = v;
	}
	// To set the next pointer
	void setNext(Node* nn) {
		next = nn;
	}
	// To set the previous pointer
	void setPrev(Node* nn) {
		prev = nn;
	}
	// To get the int value
	int getValue() {
		return value;
	}
	// To get the previous pointer
	Node* getPrev() {
		return prev;
	}
	// To get the next pointer
	Node* getNext() {
		return next;
	}
};