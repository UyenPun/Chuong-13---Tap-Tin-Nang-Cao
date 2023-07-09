#include <iostream>
#include <fstream>
using namespace std;

void NhapMang(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << "\nNhap vao a[" << i << "] = ";
		cin >> a[i];
	}
}

void GhiFile(ofstream &FileOut, int *a, int n)
{
	FileOut.open("TapTin.DAT", ios::out | ios::binary);

	if(FileOut != NULL)
	{
		FileOut.write((char *)a, n * sizeof(int));
	}

	FileOut.close();
}

int main()
{
	int n = 5;
	int *a = new int[n];

	NhapMang(a, n);
	ofstream FileOut;
	GhiFile(FileOut, a, n);

	delete[] a;

	system("pause");
	return 0;
}