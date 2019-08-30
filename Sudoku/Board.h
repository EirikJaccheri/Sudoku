#pragma once
#include "std_lib_facilities.h"

const int boardSize = 81;
const int rowSize = 9;

class Board{
	private:
		int board[boardSize];
		bool rowMoves[rowSize][rowSize];
		bool colMoves[rowSize][rowSize];
		bool squareMoves[rowSize][rowSize];
	public:
		Board(string boardString);
		bool isZero(int s);
		bool isValidMove(int s, int num);
		void setSquare(int s, int num);
		void undoSquare(int s);
		void print();
};