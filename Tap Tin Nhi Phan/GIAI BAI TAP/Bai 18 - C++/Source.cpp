#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void DocFile(ifstream &FileIn, string &str)
{
	FileIn.open("INPUT.TXT", ios::in);

	if(!FileIn)
	{
		cout << "\nKhong tim thay tap tin INPUT.TXT";
		system("pause");
		exit(0);
	}

	getline(FileIn, str);

	FileIn.close();
}

int main()
{
	string str;
	ifstream FileIn;

	DocFile(FileIn, str);
	cout << "\nChuoi doc duoc la: " << str;

	system("pause");
	return 0;
}