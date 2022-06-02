#ifndef BOARD_H
#define BOARD_H

#include<string>
using namespace std;

template <class T>
struct Card		//creating a card
{
	bool isOpen;
	T value;
	Card()
	{}
	Card(bool status = false):isOpen(status)
	{}
};

template <class T>
class Board		//creating a board
{
	private:
		int row, col;
		Card<T> ** mat;

	public:
		Board<T>(int r, int c);
		~Board<T>();
		void readBoardFromFile(ifstream &);
		void displayBoard();
		void closeCard(int r, int c);
		int getRow();
		int getColumn();
		Card<T> kokenCard(int r, int c);
		bool getIsKoken(int r, int c);
};

#endif