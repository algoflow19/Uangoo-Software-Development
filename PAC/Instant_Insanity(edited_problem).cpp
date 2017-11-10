#include <iostream>
#include <string>
#include<iomanip>


using namespace std;

enum color { B, W, G, R };

class ColorChecker {
public:
	ColorChecker() {
		resetColor();
	}

	~ColorChecker() {}

	void resetColor() {
		black = white = green = red = false;
	}

	bool check(color thisColor) {
		switch (thisColor) {
		case B:
			if (black) return false;
			black = true;
			break;
		case W:
			if (white) return false;
			white = true;
			break;
		case G:
			if (green) return false;
			green = true;
			break;
		case R:
			if (red) return false;
			red = true;
			break;

		}
		return true;
	}

private:
	bool black, white, green, red;
};

class Cube {   // When you design a class, the frist thing you should do is clear the need!
public:

	Cube(int mode) {
		setMode(mode);
	}

	~Cube() {}

	void turnTopToFront() {
		color tmp;
		tmp = top;

		top = back;
		back = bottom;
		bottom = front;
		front = tmp;
	}


	void turnFrontToRight() {
		color tmp;
		tmp = right;

		right = front;
		front = left;
		left = back;
		back = tmp;
	}

	void setFront(color thisFace) {
		front = thisFace;
	}
	void setBack(color thisFace) {
		back = thisFace;
	}
	void setTop(color thisFace) {
		top = thisFace;
	}
	void setBottom(color thisFace) {
		bottom = thisFace;
	}
	void setLeft(color thisFace) {
		left = thisFace;
	}
	void setRight(color thisFace) {
		right = thisFace;
	}

	void setMode(int mode) {
		switch (mode) {
		case 0:
			isUsing = false;
		case 1:
			isUsing = true;
			top = B;
			front = G;
			right = R;
			back = G;
			left = B;
			bottom = W;
			break;
		case 2:
			isUsing = true;
			top = G;
			front = G;
			right = B;
			back = R;
			left = W;
			bottom = W;
			break;
		case 3:
			isUsing = true;
			top = W;
			front = G;
			right = B;
			back = W;
			left = R;
			bottom = R;
			break;
		case 4:
			isUsing = true;
			top = R;
			front = W;
			right = B;
			back = B;
			left = R;
			bottom = G;
			break;



		}
	}

private:

	bool isUsing;
	color front;
	color back;
	color top;
	color bottom;
	color left;
	color right;

	friend void printCubeTop(Cube * cubeList);
	friend bool isVaild(Cube * cubeList, int & count);

};

void printCubeTop(Cube * cubeList);
bool doneInstantInsanity(Cube * cubeList, int & count, bool & startFlag);
bool isVaild(Cube * cubeList, int & count);
bool spintAndCheck(Cube * cubeList, int & count, bool & startFlag);

int main() {

	Cube * cubeList;

	cubeList = (Cube*)malloc(sizeof(Cube) * 4);

	cubeList[0].setMode(1);
	cubeList[1].setMode(2);
	cubeList[2].setMode(3);
	cubeList[3].setMode(4);


	int count = 1;
	bool startFlag = false;

	if (doneInstantInsanity(cubeList, count, startFlag))
		printCubeTop(cubeList);

	free(cubeList);
	return 0;
}

void printCubeTop(Cube * cubeList) {

	for (int i = 0; i <= 3; i++) {
		switch (cubeList[i].top) {
		case 0:
			cout << "The top is Black" << endl;
			break;
		case 1:
			cout << "The top is Withe" << endl;
			break;
		case 2:
			cout << "The top is Green" << endl;
			break;
		case 3:
			cout << "The top is Red" << endl;
		}
	}

	for (int i = 0; i <= 3; i++) {
		switch (cubeList[i].bottom) {
		case 0:
			cout << "The bottom is Black" << endl;
			break;
		case 1:
			cout << "The bottom is Withe" << endl;
			break;
		case 2:
			cout << "The bottom is Green" << endl;
			break;
		case 3:
			cout << "The bottom is Red" << endl;
		}
	}
	for (int i = 0; i <= 3; i++) {
		switch (cubeList[i].front) {
		case 0:
			cout << "The front is Black" << endl;
			break;
		case 1:
			cout << "The front is Withe" << endl;
			break;
		case 2:
			cout << "The front is Green" << endl;
			break;
		case 3:
			cout << "The front is Red" << endl;
		}
	}
	for (int i = 0; i <= 3; i++) {
		switch (cubeList[i].back) {
		case 0:
			cout << "The back is Black" << endl;
			break;
		case 1:
			cout << "The back is Withe" << endl;
			break;
		case 2:
			cout << "The back is Green" << endl;
			break;
		case 3:
			cout << "The back is Red" << endl;
		}
	}
	for (int i = 0; i <= 3; i++) {
		switch (cubeList[i].right) {
		case 0:
			cout << "The right is Black" << endl;
			break;
		case 1:
			cout << "The right is Withe" << endl;
			break;
		case 2:
			cout << "The right is Green" << endl;
			break;
		case 3:
			cout << "The right is Red" << endl;
		}
	}
	for (int i = 0; i <= 3; i++) {
		switch (cubeList[i].left) {
		case 0:
			cout << "The left is Black" << endl;
			break;
		case 1:
			cout << "The left is Withe" << endl;
			break;
		case 2:
			cout << "The left is Green" << endl;
			break;
		case 3:
			cout << "The left is Red" << endl;
		}
	}

	return;
}

bool doneInstantInsanity(Cube * cubeList, int & count, bool & startFlag) {
	if (!isVaild(cubeList, count))
		return false;
	else if (count == 4)
		return true;

	if (startFlag)
		count++;
	else startFlag = true;

	if (spintAndCheck(cubeList, count, startFlag))
		return true;
	cubeList[count].turnTopToFront();

	if (spintAndCheck(cubeList, count, startFlag))
		return true;
	cubeList[count].turnTopToFront();

	if (spintAndCheck(cubeList, count, startFlag))
		return true;
	cubeList[count].turnTopToFront();

	if (spintAndCheck(cubeList, count, startFlag))
		return true;
	cubeList[count].turnTopToFront();

	cubeList[count].turnFrontToRight();
	cubeList[count].turnTopToFront();
	if (spintAndCheck(cubeList, count, startFlag))
		return true;
	cubeList[count].turnTopToFront();
	cubeList[count].turnTopToFront();
	if (spintAndCheck(cubeList, count, startFlag))
		return true;
	cubeList[count].turnTopToFront();
	cubeList[count].turnFrontToRight();
	cubeList[count].turnFrontToRight();
	cubeList[count].turnFrontToRight();
	count--;
	return false;

}

bool spintAndCheck(Cube * cubeList, int & count, bool & startFlag) {
	for (int i = 0; i <= 3; i++) {
		cubeList[count].turnFrontToRight();
		if (doneInstantInsanity(cubeList, count, startFlag))
			return true;
	}
	return false;
}

bool isVaild(Cube * cubeList, int & count) {
	if (count == 1) return true;
	ColorChecker topChecker, bottomChecker, frontChecker, backChecker, rightChecker, leftChecker;

	for (int i = 0; i <= count - 1; i++) {
		if (!topChecker.check(cubeList[i].top))
			return false;
		if (!bottomChecker.check(cubeList[i].bottom))
			return false;
		if (!frontChecker.check(cubeList[i].front))
			return false;
		if (!backChecker.check(cubeList[i].back))
			return false;
		if (!rightChecker.check(cubeList[i].right))
			return false;
		if (!leftChecker.check(cubeList[i].left))
			return false;
	}
	return true;
}
