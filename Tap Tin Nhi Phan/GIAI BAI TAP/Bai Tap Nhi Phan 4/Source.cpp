#include <iostream>
#include <fstream>
using namespace std;

void XuatMang(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << "    ";
	}
}

void DocFile(ifstream &FileIn, int *&a, int &n)
{
	FileIn.open("TapTin.DAT", ios::in | ios::binary);

	if(!FileIn)
	{
		cout << "\nKhong tim thay tap tin TapTin.DAT";
		system("pause");
		exit(0);
	}

	FileIn.seekg(0, ios::end); // Cho con trỏ nhảy đến cuối tập tin.
	n = ((int)FileIn.tellg() + 1) / sizeof(int);
	FileIn.seekg(0, ios::beg);

	a = new int[n];

	FileIn.read((char *)a, n * sizeof(int));

	FileIn.close();
}

int main()
{
	int n, *a;
	ifstream FileIn;

	DocFile(FileIn, a, n);
	XuatMang(a, n);
	
	delete[] a;

	system("pause");
	return 0;
}