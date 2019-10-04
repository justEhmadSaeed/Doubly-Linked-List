class Node {
	int value;
	Node* next,*prev;
public:
	// To set the int value
	void setValue(int v) {
		value = v;
	}
	// To set the prev pointer
	void setPrev(Node* nn) {
		prev = nn;
	}
	// To set the next pointer
	void setNext(Node* nn) {
		next = nn;
	}
	// To get the int value
	int getValue() {
		return value;
	}
	// To get the prev pointer
	Node* getPrev() {
		return Prev;
	}
	// To get the next pointer
	Node* getNext() {
		return next;
	}
};