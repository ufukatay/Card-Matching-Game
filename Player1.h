#ifndef PLAYER_H
#define PLAYER_H
#include "Board1.h"
#include <string>
#include <iostream>
using namespace std;

template <class T>
class Player		//creating a player
{
	public:
		Player(Board<T>&);
		bool validMove(int r, int c);
		T openCard(int r, int c);
		void increaseNumberOfSuccess();
		int getNumberOfSuccess();

	private:
		Board<T>& board;
		int score;
};

#endif
