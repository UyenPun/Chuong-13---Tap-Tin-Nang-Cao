#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int DemSoLuongTu(ifstream &FileIn)
{
	int dem = 0;
	FileIn.open("INPUT.TXT", ios::in);

	if(!FileIn)
	{
		cout << "\nKhong tim thay tap tin INPUT.TXT";
		system("pause");
		exit(0);
	}

	while(!FileIn.eof())
	{
		string str;
		FileIn >> str;
		dem++;
		cout << "\nTu thu " << dem << " la: " << str;
	}
	FileIn.close();
	return dem;
}

void GhiFile(ofstream &FileOut, int SoLuong)
{
	FileOut.open("OUTPUT.TXT", ios::out);
	
	if(FileOut != NULL)
	{
		FileOut << "So luong tu la: " << SoLuong;
	}

	FileOut.close();
}

int main()
{
	ifstream FileIn;
	ofstream FileOut;
	int SoLuong = DemSoLuongTu(FileIn);

	GhiFile(FileOut, SoLuong);

	system("pause");
	return 0;
}