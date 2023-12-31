#include "stdafx.h"
#include <iostream>

#define SIZE 8

using namespace std;

class Board {
private:
	char board[SIZE][SIZE];
public:
	Board() {
		for (int i = 0; i < SIZE; i++) {
			for (int y = 0; y < SIZE; y++) {
				board[i][y] = ' ';
			}
		}
	}
	int count(char color) {
		int numOfColor = 0;
		for (int i = 0; i < SIZE; i++) {
			for (int y = 0; y < SIZE; y++) {
				if (board[i][y] == color) {
					numOfColor++;
				}
			}
		}
		return numOfColor;
	}
	void set(int row, int col, char color) {
		board[row][col] = color;
	}

	int resultOfMove(int row, int col, char color) {
		if (board[row][col] == ' ') {
			int counter = 0;
			int numBlacks = 0;
			for (int i = col - 1; i >= 0; i--) { // left horizontal check
				if (board[row][i] == ' ') {
					break;
				}
				if (board[row][i] == 'b') {
					numBlacks++;
					continue;
				}
				if (board[row][i] == 'w') {
					counter += numBlacks;
					break;
				}
			}
			numBlacks = 0;
			for (int i = col + 1; i <= 7; i++) { // right horizontal check
				if (board[row][i] == ' ') {
					break;
				}
				if (board[row][i] == 'b') {
					numBlacks++;
					continue;
				}
				if (board[row][i] == 'w') {
					counter += numBlacks;
					break;
				}
			}
			numBlacks = 0;
			for (int i = row - 1; i >= 0; i--) { // upper vertical check
				if (board[i][col] == ' ') {
					break;
				}
				if (board[i][col] == 'b') {
					numBlacks++;
					continue;
				}
				if (board[i][col] == 'w') {
					counter += numBlacks;
					break;
				}
			}
			numBlacks = 0;
			for (int i = row + 1; i <= 7; i++) { // lower vertical check
				if (board[i][col] == ' ') {
					break;
				}
				if (board[i][col] == 'b') {
					numBlacks++;
					continue;
				}
				if (board[i][col] == 'w') {
					counter += numBlacks;
					break;
				}
			}

			int _row = row - 1;
			int _col = col + 1;
			numBlacks = 0;

			while (_col <= 7 && _row >= 0) { // upper-right diagonal check
				if (board[_row][_col] == ' ') {
					break;
				}
				if (board[_row][_col] == 'b') {
					numBlacks++;
					_col++;
					_row--;
					continue;
				}
				if (board[_row][_col] == 'w') {
					counter += numBlacks;
					break;
				}
			}

			_row = row + 1;
			_col = col - 1;
			numBlacks = 0;

			while (_row <= 7 && _col >= 0) { // lower-left diagonal check
				if (board[_row][_col] == ' ') {
					break;
				}
				if (board[_row][_col] == 'b') {
					numBlacks++;
					_col--;
					_row++;
					continue;
				}
				if (board[_row][_col] == 'w') {
					counter += numBlacks;
					break;
				}
			}

			_row = row + 1;
			_col = col + 1;
			numBlacks = 0;

			while (_col <= 7 && _row <= 7) { //lower-right diagonal check
				if (board[_row][_col] == ' ') {
					break;
				}
				if (board[_row][_col] == 'b') {
					numBlacks++;
					_row++;
					_col++;
					continue;
				}
				if (board[_row][_col] == 'w') {
					counter += numBlacks;
					break;
				}
			}

			_row = row - 1;
			_col = col - 1;
			numBlacks = 0;

			while (_col >= 0 && _row >= 0) { // upper-left diagonal check
				if (board[_row][_col] == ' ') {
					break;
				}
				if (board[_row][_col] == 'b') {
					numBlacks++;
					_row--;
					_col--;
					continue;
				}
				if (board[_row][_col] == 'w') {
					counter += numBlacks;
					break;
				}
			}
			return (count('w') + counter + 1) - (count('b') - counter);
		}
		return 0;
	}

	int bestMove(int& row, int& col, char color) {
		int max = -64; //initialized to minimum score
		for (int i = 0; i < SIZE; i++) {
			for (int y = 0; y < SIZE; y++) {
				if (board[i][y] == ' ') {
					int result = resultOfMove(i, y, 'w');
					if (result > max) {
						max = result;
						row = i;
						col = y;
					}
				}
			}
		}
		return max;
	}
};

int main() {
	Board reversi;
	int numWhites, numBlacks, row, col;
	cin >> numWhites >> numBlacks;
	for (int i = 0; i < numWhites; i++) {
		cin >> row >> col;
		reversi.set(row, col, 'w');
	}
	for (int i = 0; i < numBlacks; i++) {
		cin >> row >> col;
		reversi.set(row, col, 'b');
	}
	int maxRow = -1;
	int maxCol = -1;
	int score = reversi.bestMove(maxRow, maxCol, 'w');
	cout << maxRow << ' ' << maxCol << ' ' << score << endl;
	system("pause");
	return 0;
}