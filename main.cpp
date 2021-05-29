#include <iostream>
#include "myConio.h"

int main(){
	char c;
	string input = "Input Pencarian : ";
	int p_input;

	while(true){
		cout << input;
		c = getch();
		if (c == '\n')
			break;
		else if ((int) c == 127){
			p_input = input.length() - 1;
			input.erase(p_input, 1);
		}
		else{
			input += c;
		}
		clrscr();
	}

	return 0;
}