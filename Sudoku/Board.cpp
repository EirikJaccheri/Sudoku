#include "Board.h"

Board::Board(string boardString){
	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < rowSize; j++) {
			rowMoves[i][j] = true;
			colMoves[i][j] = true;
			squareMoves[i][j] = true;
		}
	}	

	for (int i = 0; i < boardSize; i++) {
		int n = static_cast<int>(boardString[i]) - 48;
		if (n == 0) {
			board[i] = 0;
		}
		else {
			setSquare(i, n);
		}
	}
}

bool Board::isZero(int s) {
	if (board[s] == 0) {
		return true;
	}
	else {
		return false;
	}
}

int row(int num) {
	return num / rowSize;
}

int col(int num) {
	return num % rowSize;
}

int square(int num) {
	int r = row(num);
	int c = col(num);
	for (int i = 1; i < 4; i++) {
		if (c < i * 3) {
			for (int j = 1; j < 4; j++) {
				if (r < j * 3) {
					return i + (j - 1) * 3  -1;
				}
			}

		}
	}
}

bool Board::isValidMove(int s, int num) {
	return (rowMoves[row(s)][num - 1] and colMoves[col(s)][num - 1] and squareMoves[square(s)][num - 1]);
}


void Board::setSquare(int s, int num) {
	board[s] = num;
	rowMoves[row(s)][num - 1] = false;
	colMoves[col(s)][num - 1] = false;
	squareMoves[square(s)][num - 1] = false;
}

void Board::undoSquare(int s) {
	int num = board[s];
	board[s] = 0;
	rowMoves[row(s)][num - 1] = true;
	colMoves[col(s)][num - 1] = true;
	squareMoves[square(s)][num - 1] = true;
}

void Board::print() {
	for (int i = 0; i < boardSize; i++) {
		cout << board[i];
		if (((i+1) % rowSize == 0) and (i != 0)) {
			cout << '\n';
		}
	}
}