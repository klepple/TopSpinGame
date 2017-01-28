//klepple 250836229
#pragma once
#include<iostream>
#include "CircularDoublyLinkedList.h"
class TopSpinADT {//Given in assignment 2 file
public:
	// shifts the pieces 1 to the left
	virtual void shiftLeft() = 0;
	//shifts the pieces 1 to the right
	virtual void shiftRight() = 0;
	//reverses the pieces in the spin mechanism, IE if the 4 in the mechanism are
	// 1,4,3,6 we will have 6,3,4,1
	virtual void spin() = 0;
	//checks to see if the puzzle is solved that is to say the pieces are in numerical order 1 - 20
	virtual bool isSolved() = 0;
};

class TopSpin :public TopSpinADT {
private:
	int size;
	int spinSize;
	CircularDoublyLinkedList<int> board;
public:
	TopSpin(); //Default Constructor
	TopSpin(int size, int spinSize);//Constructor
	~TopSpin();//Destructor
	int getSize() const;//Returns the size of board
	int getSpinSize() const;//Returns the spinSize of board
	void shiftLeft();//Shifts the CDLL board once to the left
	void shiftRight();//Shifts the CDLL board once to the right
	void spin();//Spins spinner of size spinSize once
	bool isSolved();//Checks if the board is solved and returns true if it is
	friend std::ostream& operator<< (std::ostream& os, const TopSpin& s);//Overloads the << operator to print out the board
};