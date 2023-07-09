#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void GhiFile(ofstream &FileOut, string str)
{
	FileOut.open("OUTPUT.TXT", ios::out);

	if(FileOut != NULL)
	{
		FileOut << "Chuoi ban nhap vao la: " << str;
	}

	FileOut.close();
}

int main()
{
	string str;
	cout << "\nMoi ban nhap vao chuoi: ";
	getline(cin, str);

	ofstream FileOut;
	GhiFile(FileOut, str);

	system("pause");
	return 0;
}