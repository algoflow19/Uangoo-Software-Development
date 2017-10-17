#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include"fun_include.h"


// 支票打印程序 
// 10=千 11=百 12=十  15=亿 14=万

void written_amount(unsigned long int amount, char *buffer1) {

	char *buffer = buffer1;

	if (amount >= 100'000'000)
	{
		buffer=four_p(amount / 100'000'000, buffer);
		num0_9(15, buffer);
		buffer += 2;
	}

	if (amount >= 10'000) {

		buffer = four_p((amount - (amount / 100'000'000)*100'000'000) / 10'000, buffer);

		num0_9(14, buffer);
		buffer += 2;
	}

	buffer = four_p(amount - (amount / 10'000)* 10'000, buffer);

	*buffer = '\0';

}




int main() {

	unsigned long amount = 40'9000'9789;
	
	char chars[1000];

	written_amount(amount, chars);

	printf("The word is %s \n", chars);
	

	return 0;

}