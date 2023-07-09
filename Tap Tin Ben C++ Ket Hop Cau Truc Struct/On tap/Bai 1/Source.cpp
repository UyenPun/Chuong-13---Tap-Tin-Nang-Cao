#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream FileIn("INPUT.TXT");

	if(!FileIn)
	{
		cout << "\nKhong tim thay tap tin INPUT.TXT";
		system("pause");
		return 0; // Kết thúc.
	}

	int a, b;

	FileIn >> a >> b;

	FileIn.close();


	ofstream FileOut("OUTPUT.TXT");

	int Tong = a + b;

	FileOut << Tong;

	FileOut.close();

	system("pause");
	return 0;
}