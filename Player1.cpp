#include "Player1.h"
#include "Board1.h"
#include <iostream>
#include <string>
using namespace std;

template <class T>
Player<T>::Player(Board<T> &myboard):board(myboard)		//constructor
{  
	score = 0;
}

template <class T>
T Player<T>::openCard(int r, int c)		//opening card
{  
	return board.kokenCard(r,c).value;
}

template <class T>
bool Player<T>::validMove(int r, int c)		//restricting selections of players to pick valid cards 
{
	if ((r > board.getRow()) || (r < 0))
		return false;
	else if ((c > board.getColumn()) || (c < 0))
		return false;
	else if (board.getIsKoken(r,c))
		return false;
	else
		return true;
}

template <class T>
void Player<T>::increaseNumberOfSuccess()		//increment score
{
	score++;
}

template <class T>
int Player<T>::getNumberOfSuccess()		//returning score
{
	return score;
}





