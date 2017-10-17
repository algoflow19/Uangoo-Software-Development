#pragma once
int num0_9(int num, char * T) {

	static char *tmp = "一二三四五六七八九千百十零万亿";

	switch (num) {
	case 1:
		*T = tmp[0];
		T[1] = tmp[1];
		break;

	case 2:

		*T = tmp[2];
		T[1] = tmp[3];
		break;

	case 3:

		*T = tmp[4];
		T[1] = tmp[5];

		break;
	case 4:

		*T = tmp[6];
		T[1] = tmp[7];
		break;
	case 5:

		*T = tmp[8];
		T[1] = tmp[9];
		break;
	case 6:

		*T = tmp[10];
		T[1] = tmp[11];
		break;
	case 7:

		*T = tmp[12];
		T[1] = tmp[13];
		break;
	case 8:

		*T = tmp[14];
		T[1] = tmp[15];
		break;
	case 9:

		*T = tmp[16];
		T[1] = tmp[17];
		break;
	case 10:

		*T = tmp[18];
		T[1] = tmp[19];
		break;
	case 11:

		*T = tmp[20];
		T[1] = tmp[21];
		break;
	case 12:

		*T = tmp[22];
		T[1] = tmp[23];
		break;
	case 13:

		*T = tmp[24];
		T[1] = tmp[25];
		break;
	case 14:  //万

		*T = tmp[26];
		T[1] = tmp[27];
		break;

	case 15: //亿
		*T = tmp[28];
		T[1] = tmp[29];
		break;
	default:
		printf("Given a illegal argument!");
		return -1;
		break;

	}
	return 0;
}

char * four_p(unsigned int number, char *buffer) {
	int a1 = number % 10;
	int a2 = (number / 10) % 10;
	int a3 = (number / 100) % 10;
	int a4 = number / 1000;

	if (a4 != 0) {
		num0_9(a4, buffer);
		buffer += 2;
		num0_9(10, buffer);
		buffer += 2;

		if (a3 == 0 && a2 + a1 != 0)
		{
			num0_9(13, buffer);
			buffer += 2;
		}

	}
	if (a3 != 0) {
		num0_9(a3, buffer);
		buffer += 2;
		num0_9(11, buffer);
		buffer += 2;

		if (a2 == 0 && a1 != 0)
		{
			num0_9(13, buffer);
			buffer++;
		}

	}

	if (a2 != 0) {
		if (a2 != 1)
		{
			num0_9(a2, buffer);
			buffer += 2;
		}
		num0_9(12, buffer);
		buffer += 2;
	}
	if (a1 != 0) {
		num0_9(a1, buffer);
		buffer += 2;
	}
	return buffer;

}
