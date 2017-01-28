//klepple 250836229
#include"TopSpin.h"
using namespace std;

TopSpin::TopSpin(){
	size = 20;
	spinSize = 4;
	for (int i = 1; i <= size; i++) {//Populates the CDLL board with nodes in ascending order from 1 to size-1
		board.addTail(i);
	}
}

TopSpin::TopSpin(int size, int spinSize) {
	if (size < 1 || spinSize > size) {//If the sizes are invalid, replace them with the default of 20,4
		this->size = 20;
		this->spinSize = 4;
	}
	else {//Sets size & spinSize values
		this->size = size;
		this->spinSize = spinSize;
	}
	for (int i = 1; i <= this->size; i++) {//Populates the CDLL board with nodes in ascending order from 1 to size
		board.addTail(i);
	}
}

TopSpin::~TopSpin() {}

int TopSpin::getSize() const {
	return size;
}
int TopSpin::getSpinSize() const {
	return spinSize;
}
void TopSpin::shiftLeft() {
	board.sLeft();
}
void TopSpin::shiftRight() {
	board.sRight();
}

void TopSpin::spin(){
	CircularDoublyLinkedList<int>::Iterator x = board.begin(), y = board.begin();//Sets two new iterators, x and y to the head of board
	for (int k = 1; k < getSpinSize(); k++){//y goes all the way to the end of the spinSize
		++y;
	}
	for (int j = 1; j <= (getSpinSize() / 2); j++){//Starting from both ends, x and y swap values while incrementing towards the center point of spinSize
		board.swap(x, y);
		++x;
		--y;
	}
}
bool TopSpin::isSolved(){
	bool check(true);
	int index = 1;
	while (board.retrieveNode(index) != 1) {
		index++;
	}
	for (int i = 1; i < board.size(); i++) {
		if (index <= 20 && board.retrieveNode(index) != i) {
			check = 0;
		} 
		else if (index > 20 && board.retrieveNode(index - 20) != i) {
			check = 0;
		}
		index++;
	}
	return check;
}

std::ostream& operator << (std::ostream& os, const TopSpin& ts)
{
	CircularDoublyLinkedList<int>::Iterator iter = (ts.board).begin(); //Sets iter to the start of TopSpin object board
	cout << "--";
	for (int i = 0; i < ts.getSpinSize(); i++)
		cout << "--";
	cout << "-" << endl;

	for (int i = 0; i < ts.getSize(); i++, ++iter)
	{
		if (i == 0 || i == ts.getSpinSize())
			cout << "| ";
		os << iter.getValue() << " "; //Outputs the value stored in node
	}
	
	cout << endl;
	cout << "--";
	for (int i = 0; i < ts.getSpinSize(); i++)
		cout << "--";
	cout << "-" << endl;
	return os;
}