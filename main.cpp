#include <iostream>
#include "myConio.h"

int main(){
	char c;
	string input = "Input Pencarian : ";

	while(true){
		cout << input;
		c = getch();
		if (c == '\n')
			break;
		input += c;
		clrscr();
	}

	return 0;
}