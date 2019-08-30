#include "Board.h"
#include "SudokuSolver.h"
int main(){
	string s = "003020600900305001001806400008102900700000008006708200002609500800203009005010300";
	Board b(s);
	bool solved = false;
	solve(b, 0, solved);
	b.print();
	return 0;
}