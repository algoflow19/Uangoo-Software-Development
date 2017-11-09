// PAC++.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

bool doneEightQueen(bool chessboard[][8],int & cols, int & rows);
bool isVaildPositon(bool chessboard[][8], int x, int y);

int main() {

	bool cheseBoard[8][8] = {};  // Use it to set the default value!
	int x = -1;
	int y = 0;
	doneEightQueen(cheseBoard, x, y);
	for (int col = 0; col <= 7; col++) {
		for (int rows = 0; rows <= 7; rows++)
			if (cheseBoard[col][rows] == false)
				cout << "[ ]";
			else
				cout << "[X]";

		cout << endl;
	}
	return 0;

}

bool doneEightQueen(bool chessboard[][8], int & cols, int & rows) {

	if (!isVaildPositon(chessboard, cols, rows))
		return false;
	else if (cols == 7){
		chessboard[cols][rows] = 1;
		return true;
	}

	if(cols !=-1)
	chessboard[cols][rows] = 1;
	cols++;

	for (int y = 0; y <= 7; y++) {
		 {
			if (doneEightQueen(chessboard, cols, y))
				return true;
		}
	}
	cols--;
	chessboard[cols][rows] = false;

	return false;
}

bool isVaildPositon(bool chessboard[][8], int x, int y) {
	for (int i = 0; i <=x; i++)
		if (chessboard[i][y] == true)
			return false;
	if(x!=0)
		for (int i = 0; i <= x ; i++) {
			if (y + i <= 7)
				if (chessboard[x - i][y + i] == true)
					return false;
			if (y - i >= 0)
				if (chessboard[x - i][y - i] == true)
					return false;
		}
	return true;
}
