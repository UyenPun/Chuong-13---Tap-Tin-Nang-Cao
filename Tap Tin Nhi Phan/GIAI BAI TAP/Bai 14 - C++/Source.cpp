#include <iostream>
#include <fstream>
using namespace std;

void NhapDuLieu(int &a, int &b, int &c)
{
	cout << "\nNhap a = ";
	cin >> a;

	cout << "\nNhap b = ";
	cin >> b;

	cout << "\nNhap c = ";
	cin >> c;
}

void GhiFile(ofstream &FileOut, int a, int b, int c)
{
	FileOut.open("OUTPUT.TXT", ios::out);
	if(FileOut != NULL)
	{
		FileOut << "a = " << a << endl << "b = " << b << endl << "c = " << c << endl;
	}

	FileOut.close();
}

int main()
{
	int a, b, c;
	ofstream FileOut;
	
	NhapDuLieu(a, b, c);
	GhiFile(FileOut, a, b, c);

	system("pause");
	return 0;
}