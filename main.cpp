#include <iostream>
#include <string.h>
#include "myConio.h"

int main(){

	int banyak = 6;
	string nama[banyak] = {"andi", "anang" ,"cibulangka", "bantama", "andika", "diki"};


	char c;
	int p_input;
	string key = "";
	string input = "Input Pencarian : ";
	string ambildata = "";
	bool muncul = true;
	bool ketemu = false;

	while(true){
		cout << input;
		if (key != "")
		{
			cout << "\n\n";
			ketemu = false;
			for (int i = 0; i < banyak; i++)
			{
				muncul = true;
				for (int j = 0; j < nama[i].length(); j++)
				{
					for (int k = 0; k < key.length(); k++)
						if (j + k < nama[i].length())
							ambildata += nama[i][j + k];

					if (strlow(ambildata) == strlow(key))
						if (muncul)
						{
							cout << "Nama  : " << nama[i] << endl;
							muncul = false;
							ketemu = true;
						}
					ambildata = "";
				}
			}
			if (!ketemu)
				cout << "Pencarian '" << key << "' Tidak Ditemukan !!! \n";
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