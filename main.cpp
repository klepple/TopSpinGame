//klepple 250836229
#include<iostream>
#include"TopSpin.h"
#include<ctime>
using namespace std;

int main() {
	cout << "Welcome to the TopSpin Game!!" << endl;
	//CREATE
	TopSpin board(20, 4);
	cout << "First we populate the board. Here it is!:" << endl;
	cout << board << endl;
	//SHUFFLE
	int randMoves;//User chosen int
	cout << "Please enter a number of random moves to shuffle the puzzle: " << endl;
	cin >> randMoves;
	for (int i = 1; i < randMoves; i++) {
		srand(unsigned int(time(NULL)));
		for (int j = (rand() % (board.getSize() - 1)); j > 0; j--) {
			board.shiftLeft();
		}
		board.spin();
	}
	//START GAME!
	cout << "Here is your shuffled board!:" << endl;
	cout << board << endl;
	cout << "Ready to play! Good Luck!" << endl;
	//MENU
	int choice;//User choice
	do{//while(choice != 3)
		cout << "Please choose from the following options: " << endl
			<< "1. Shift\t" << "2. Spin\t\t" << "3. Quit" << endl;
		cin >> choice;//take in user's choice
		switch (choice) {
		case 1://Shift
			int shiftNum;
			int shiftDir;
			cout << "How many times would you like to shift?:" << endl;
			cin >> shiftNum;//How many times the shift occurs
			cout << "Left or Right?(Enter 1 for Left or 2 for Right):" << endl;
			cin >> shiftDir;//Direction of shift
			switch (shiftDir) {
			case 1://Left
				for (int i = 0; i < shiftNum; i++) {
					board.shiftLeft();
				}
				cout << board << endl;
				if (board.isSolved()) {
					cout << "Congratulations! You solved the TopSpin Game!!" << endl;
					choice = 3;
				}
				break;
			case 2://Right
				for (int i = 0; i < shiftNum; i++) {
					board.shiftRight();
				}
				cout << board << endl;
				if (board.isSolved()) {
					cout << "Congratulations! You solved the TopSpin Game!!" << endl;
					choice = 3;
				}
				break;
			}
			break;
		case 2://Spin
			board.spin();
			cout << board << endl;
			if (board.isSolved()) {
				cout << "Congratulations! You solved the TopSpin Game!!" << endl;
				choice = 3;
			}
			break;
		case 3://Quit
			cout << "Better luck next time!" << endl;
			break;
		}
	} while (choice != 3);
	cout << "~~~THANK YOU FOR PLAYING!~~~" << endl;
	return 0;
}