#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <math.h>


using namespace std;
int check_insturction(char x[][100], string& line, int& ct, int& r, int& length, int& i, int& pos, string& location, string& num, string& Hnum, int& hex_length, int& f, int& tmp_number, int& Dnum, int& counter);
int check_HEX(char x[][100], string& line, int& ct, int& r, int& length, int& i, int& pos, string& location, string& num, string& Hnum, int& hex_length, int& f, int& tmp_number, int& Dnum);
int check_DEC(char x[][100], string& line, int& ct, int& r, int& length, int& i, int& pos, string& location, string& num, string& Hnum, int& hex_length, int& f, int& tmp_number, int& Dnum);
int dec(string hex);
string hexa(int num);
int Assembler();




int main()
{
	Assembler();
}






int dec(string hex)
{
	unsigned long result = 0;
	for (int i = 0; i < hex.length(); i++) {
		if (hex[i] >= 48 && hex[i] <= 57)
		{
			result += (hex[i] - 48) * pow(16, hex.length() - i - 1);
		}
		else if (hex[i] >= 65 && hex[i] <= 70) {
			result += (hex[i] - 55) * pow(16, hex.length() - i - 1);
		}
		else if (hex[i] >= 97 && hex[i] <= 102) {
			result += (hex[i] - 87) * pow(16, hex.length() - i - 1);
		}
	}
	return result;
}
string hexa(int num)
{
	// map for decimal to hexa, 0-9 are
	// straightforward, alphabets a-f used
	// for 10 to 15.
	map<int, char> m;

	char digit = '0';
	char c = 'a';

	for (int i = 0; i <= 15; i++) {
		if (i < 10) {
			m[i] = digit++;
		}
		else {
			m[i] = c++;
		}
	}

	// string to be returned
	string res = "";

	// check if num is 0 and directly return "0"
	if (!num) {
		return "0";
	}
	// if num>0, use normal technique as
	// discussed in other post
	if (num > 0) {
		while (num) {
			res = m[num % 16] + res;
			num /= 16;
		}
	}
	// if num<0, we need to use the elaborated
	// trick above, lets see this
	else {
		// store num in a u_int, size of u_it is greater,
		// it will be positive since msb is 0
		unsigned int n = num;

		// use the same remainder technique.
		while (n) {
			res = m[n % 16] + res;
			n /= 16;
		}
	}

	return res;
}


int check_DEC(char x[][100], string& line, int& ct, int& r, int& length, int& i, int& pos, string& location, string& num, string& Hnum, int& hex_length, int& f, int& tmp_number, int& Dnum)
{
	if (x[r][pos] == 'D' && x[r][pos + 1] == 'E' && x[r][pos + 2] == 'C')
	{
		for (i = pos + 3; x[r][i] == ' '; i++)
		{

		}

		//check if there is a number or Error
		if (x[r][i] == '\0' || x[r][i] == '/')
		{
			cout << "Error" << endl;
			return 0;
		}
		// store the number
		for (; x[r][i] != '\0'; i++)
		{
			if (x[r][i] != ' ')
			{
				num += x[r][i];

				if (x[r][i + 1] == ' ')
				{
					break;
				}
			}
		}

		//convert the number to hexa
		Dnum = stoi(num);
		Hnum = hexa(Dnum);


		hex_length = Hnum.length();

		// check the size of the number
		if (hex_length < 4)
		{
			for (int n = 0; n < 4 - hex_length; n++)
			{
				cout << 0;
			}
			cout << Hnum << endl;
		}
		else if (hex_length > 4)
		{
			int n = hex_length - 4;


			while (n < hex_length)
			{
				cout << Hnum[n];
				n++;
			}

			cout << endl;
		}
		else
		{
			cout << Hnum << endl;
		}

		// to add 1 to the location


		num = ' ';

		return 1;
	}

	return 0;
}



int check_HEX(char x[][100], string& line, int& ct, int& r, int& length, int& i, int& pos, string& location, string& num, string& Hnum, int& hex_length, int& f, int& tmp_number, int& Dnum)
{
	if (x[r][pos] == 'H' && x[r][pos + 1] == 'E' && x[r][pos + 2] == 'X')
	{
		for (i = pos + 3; x[r][i] == ' '; i++)
		{

		}

		if (x[r][i] == '\0' || x[r][i] == '/')
		{
			cout << "Error" << endl;
			return 0;
		}

		string hex;
		for (; x[r][i] != '\0'; i++)
		{
			if (x[r][i] != ' ')
			{
				hex += x[r][i];

				if (x[r][i + 1] == ' ')
				{
					break;
				}
			}
		}


		hex_length = hex.length();


		if (hex_length < 4)
		{
			for (int n = 0; n < 4 - hex_length; n++)
			{
				cout << 0;
			}
			cout << hex << endl;
		}
		else if (hex_length > 4)
		{
			int n = hex_length - 4;


			while (n < hex_length)
			{
				cout << hex[n];
				n++;
			}

			cout << endl;
		}
		else
		{
			cout << hex << endl;
		}




		return 1;
	}

	return 0;
}


int check_insturction(char x[][100], string& line, int& ct, int& r, int& length, int& i, int& pos, string& location, string& num, string& Hnum, int& hex_length, int& f, int& tmp_number, int& Dnum, int& counter)
{
	//if it is one of the instructions 
	if (x[r][pos] == line[0] && x[r][pos + 1] == line[1] && x[r][pos + 2] == line[2])
	{

		//if it is memory reference
		if (line[4] == '0' || line[4] == '1' || line[4] == '2' || line[4] == '3' || line[4] == '4' || line[4] == '5' || line[4] == '6')
		{

			for (i = pos + 3; x[r][i] == ' '; i++)
			{

			}

			if (x[r][i] == '\0' || x[r][i] == '/')
			{
				cout << "Error" << endl;
				return 0;
			}


			string copy_location = location;

			tmp_number = dec(copy_location);
			tmp_number--;
			copy_location = hexa(tmp_number);

			for (int rr = 0; rr < ct; rr++)
			{
				if (x[rr][0] != ' ' && x[rr][0] != '\t')
				{
					f = 1;
					int k, y;

					for (k = 0, y = i; x[rr][k] != ',' && x[rr][k] != ' '; k++, y++)
					{
						if (x[rr][k] != x[r][y])
						{
							f = 0;
						}

						if (k == 3)
						{
							cout << "Error" << endl;
						}
					}

					if (f == 0 && rr == (ct - 2))
					{
						cout << "Error" << endl;
					}

					if (f == 1 && x[rr][k] != ',')
					{
						cout << "Error" << endl;
					}
					if (f == 1 && x[r][y] != ' ' && x[r][y] != '\0')
					{
						cout << "Error" << endl;
					}




					if (f == 1)
					{


						if (x[r][y + 1] == 'I' || x[r][y + 2] == 'I')
						{
							cout << line[9];

							hex_length = copy_location.length();



							if (hex_length < 3)
							{
								for (int n = 0; n < 3 - hex_length; n++)
								{
									cout << 0;
								}
								cout << copy_location << endl;
							}
							else if (hex_length > 3)
							{
								int n = hex_length - 4;


								while (n < hex_length)
								{
									cout << copy_location[n];
									n++;
								}

								cout << endl;
							}
							else
							{
								cout << copy_location << endl;
							}

						}
						else
						{
							cout << line[4];

							hex_length = copy_location.length();



							if (hex_length < 3)
							{
								for (int n = 0; n < 3 - hex_length; n++)
								{
									cout << 0;
								}
								cout << copy_location << endl;
							}
							else if (hex_length > 3)
							{
								int n = 0;
								for (; n < hex_length - 3; n++)
								{

								}

								while (n < hex_length)
								{
									cout << copy_location[n];
									n++;
								}

								cout << endl;
							}
							else
							{
								cout << copy_location << endl;
							}


						}



						break;
					}
				}
				tmp_number = dec(copy_location);
				tmp_number++;
				copy_location = hexa(tmp_number);
			}
			return 1;
		}
		else
		{
			// if it is non memory reference
			for (i = 4; line[i] != '\0'; i++)
			{
				cout << line[i];
			}
			cout << endl;




			return 1;
		}
	}   // if it is not in the instructoins
	else if (counter > 24)
	{
		cout << "Error" << endl;
		return 1;
	}

	return 0;
}


int Assembler()
{
	ifstream input, instructions;
	string line, location, num, Hnum;

	char x[100][100];
	int ct = 0, r = 0, length, i = 0, pos = 0, Dnum, hex_length, f = 0, tmp_number;





	input.open("x.txt");
	instructions.open("instructions.txt");

	// read from the file and put it in the array
	while (getline(input, line))
	{
		length = line.length();

		for (i = 0; i < length; i++)
		{
			x[r][i] = line[i];
		}

		x[r][i] = '\0';
		r++;

		ct++;
	}

	// to catch the first instruction
	for (i = 0; x[0][i] != '\0'; i++)
	{
		if (x[0][i] != ' ')
		{
			pos = i;
			break;
		}
	}
	// check if the first instruction ORG
	if (x[0][pos] != 'O' || x[0][pos + 1] != 'R' || x[0][pos + 2] != 'G')
	{
		cout << "Error" << endl;
		return 1;
	}
	else
	{   // store the number after the ORG
		for (i = pos + 3; x[0][i] != '\0'; i++)
		{
			if (x[0][i] != ' ')
			{
				num += x[0][i];

				if (x[0][i + 1] == ' ')
				{
					break;
				}
			}
		}

		// store the locations
		location = num;
		num = ' ';
	}



	for (r = 1; r < ct; r++)
	{
		instructions.close();
		instructions.open("instructions.txt");
		int counter = 0;

		if (x[r][pos] == 'E' && x[r][pos + 1] == 'N' && x[r][pos + 2] == 'D')
		{
			break;
		}




		//search around the instructions
		while (getline(instructions, line))
		{
			counter++;

			if (check_insturction(x, line, ct, r, length, i, pos, location, num, Hnum, hex_length, f, tmp_number, Dnum, counter))
			{
				break;
			}
			if (check_DEC(x, line, ct, r, length, i, pos, location, num, Hnum, hex_length, f, tmp_number, Dnum))
			{
				break;
			}
			if (check_HEX(x, line, ct, r, length, i, pos, location, num, Hnum, hex_length, f, tmp_number, Dnum))
			{
				break;
			}






		}
	}


	// check if the last line is END or not
	if (x[r][pos] != 'E' || x[r][pos + 1] != 'N' || x[r][pos + 2] != 'D')
	{
		cout << "Error" << endl;
	}




	//close the files

	input.close();
	instructions.close();
}

