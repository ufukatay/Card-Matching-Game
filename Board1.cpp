#include "Board1.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

template <class T>
Board<T>::Board(int r, int c)		//constructor
{
	row = r;
	col = c;
	mat = new Card<T>* [row]; 

	for (int i = 0; i<row; i++)
		mat[i] = new Card<T>[col];

}

template <class T>
Board<T>::~Board()		//destructor
{
	for(int i = 0; i < row; i++){
		delete[] mat[i];
	}
	delete[] mat;
}

template <class T>
void Board<T>::readBoardFromFile(ifstream & fin)		//assigned values to cards from file
{
	for(int i =0; i < row; i++){
		for(int j = 0; j < col; j++){
			fin >> mat[i][j].value;
			mat[i][j].isOpen = false;
		}
	}
}

template <class T>
void Board<T>::displayBoard()		// printing the created matrix
{
	for (int j=0; j < row; j++){
		for (int k=0; k < col; k++){
			if(mat[j][k].isOpen == true)
				cout << mat[j][k].value << "  ";
			else
				cout << "X  ";
		}
		cout << endl;
    }
}

template <class T>
void Board<T>::closeCard(int r, int c)		//closing card
{
	mat[r][c].isOpen = false;
}

template <class T>
int Board<T>::getRow()		//getting row
{
	return row;
}

template <class T>
int Board<T>::getColumn()		//getting column
{
	return col;
}

template <class T>
Card<T> Board<T>::kokenCard(int r, int c)		//to use in player class, opening card
{
	mat[r][c].isOpen = true;
	return mat[r][c];
}

template <class T>
bool Board<T>::getIsKoken(int r, int c)		//to use in player class, getting value which is card statue  
{
	return mat[r][c].isOpen;
}