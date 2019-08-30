#pragma once
#include "Board.h"

void solve(Board &b, int s, bool &solved) {
	if (s == 81) {
		solved = true;
	}
	else if (b.isZero(s)) {
		for (int i = 1; i < (rowSize + 1); i++) {
			if (b.isValidMove(s, i)) {
				b.setSquare(s, i);
				solve(b, s + 1, solved);
				if (!solved) {
					b.undoSquare(s);
				}
			}
		}
	}
	else {
		solve(b, s + 1, solved);
	}
}

