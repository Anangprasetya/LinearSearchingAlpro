#include <iostream>
#include "myConio.h"

int main(){

	int banyak = 5;
	string nama[banyak] = {"andi", "anang" ,"cibulangka", "bantama", "andika" };


	char c;
	int p_input;
	string key = "";
	string input = "Input Pencarian : ";

	while(true){
		cout << input;
		if (key != "")
		{
			cout << "Kunci : " << key << endl;
		}

		c = getch();
		if (c == '\n')
			break;
		else if ((int) c == 127){
			p_input = input.length() - 1;
			input.erase(p_input, 1);

			p_input = key.length() - 1;
			key.erase(p_input, 1);
		}
		else{
			input += c;
			key += c;
		}

		clrscr();
	}

	return 0;
}