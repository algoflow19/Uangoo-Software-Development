// PAC++.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include<iomanip>
using namespace std;

bool doneKingnightTour(int chessboard[][8],int & count,int & cols, int & rows);
bool warpper(int chessboard[][8], int & count,
	int & cols, int & rows,int & xMove,int & yMove);
bool isVaildPositon(int chessboard[][8], int & x, int & y);

int main() {

	int chessboard[8][8] = {};  // Use it to set the default value!
	int count = 1;
	int cols = 7;
	int rows = 0;
	doneKingnightTour(chessboard,  count, cols , rows );
	for (int col = 0; col <= 7; col++) {
		for (int rows = 0; rows <= 7; rows++)
			if (chessboard[col][rows] == 0)
				cout << "[  ]";
			else
				cout << "[" << setw(2) << chessboard[col][rows] << "]";

		cout << endl;
	}
	cout << endl;

	return 0;

}

bool isVaildPositon(int chessboard[][8], int & x, int & y) {
	if (x < 0 || x>7)
		return false;
	if (y < 0 || y>7)
		return false;
	if (chessboard[x][y] > 0)
		return false;
	return true;
}

bool warpper(int chessboard[][8], int & count,
	int & cols, int & rows, int & xMove, int & yMove){
	
	cols += xMove; rows += yMove;
	bool returnValue = doneKingnightTour(chessboard, count, cols, rows);
	cols -= xMove; rows -= yMove;
	return returnValue;
}

bool doneKingnightTour(int chessboard[][8], int & count,
	int & cols, int & rows) {

	if (!isVaildPositon(chessboard, cols, rows))
		return false;
	else if (count == 64) {
		chessboard[rows][cols] = 64;
		return true;
	}
	chessboard[cols][rows] = count;
	count++;
	for (int col = 0; col <= 7; col++) {
		for (int rows = 0; rows <= 7; rows++)
			if (chessboard[col][rows] == 0)
				cout << "[  ]";
			else
				cout << "[" << setw(2) << chessboard[col][rows] << "]";
		cout << endl;
	}
	cout << endl;
	count--;
	chessboard[cols][rows] = 0;

	return false;
	
}
