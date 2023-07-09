#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int DemSoKyTuChuCai(ifstream &FileIn)
{
	int dem = 0;
	FileIn.open("INPUT.TXT", ios::in);

	if(!FileIn)
	{
		cout << "\nKhong tim thay tap tin INPUT.TXT";
		system("pause");
		exit(0);
	}

	char c;
	while(!FileIn.eof())
	{
		FileIn.get(c); // Đọc vào 1 ký tự từ tập tin và lưu vào biến c.
		if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		{
			dem++;
		}
	}
	FileIn.close();
	return dem;
}

void GhiFile(ofstream &FileOut, int SoLuong)
{
	FileOut.open("OUTPUT.TXT", ios::out);
	
	if(FileOut != NULL)
	{
		FileOut << "So luong ky tu la chu cai la: " << SoLuong;
	}

	FileOut.close();
}

int main()
{
	ifstream FileIn;
	ofstream FileOut;
	int SoLuong = DemSoKyTuChuCai(FileIn);

	GhiFile(FileOut, SoLuong);

	system("pause");
	return 0;
}