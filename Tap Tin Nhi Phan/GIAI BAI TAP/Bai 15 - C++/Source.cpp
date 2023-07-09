#include <iostream>
#include <fstream>
using namespace std;

// Đọc dữ liệu từ file vào chương trình.
void DocFile(ifstream &FileIn, int &a, int &b, int &c)
{
	FileIn.open("INPUT.TXT", ios::in);

	if(!FileIn)
	{
		cout << "\nKhong tim thay tap tin INPUT.TXT";
		system("pause");
		exit(0); // Kết thúc toàn bộ chương trình.
	}

	FileIn >> a >> b >> c;

	FileIn.close();
}

// Xử lý và ghi kết quả ra file.
void GhiFile(ofstream &FileOut, int a, int b, int c)
{
	FileOut.open("OUTPUT.TXT", ios::out);
	
	if(FileOut != NULL)
	{
		// Xử lý giải phương trình.
		if(a == 0) // bx + c = 0
		{
			if(b == 0)
			{
				if(c == 0)
				{
					FileOut << "Phuong trinh co vo so nghiem";
				}
				else
				{
					FileOut << "Phuong trinh vo nghiem";
				}
			}
			else
			{
				float x = (float)-c / b;
				FileOut << "Phuong trinh co 1 nghiem duy nhat x = " << x;
			}
		}
		else
		{
			float Denta = b * b - 4 * a * c;
			if(Denta < 0)
			{
				FileOut << "Phuong trinh vo nghiem";
			}
			else if(Denta == 0)
			{
				float x = (float)-b / (2 * a);
				FileOut << "Phuong trinh co nghiem kep: x1 = x2 = " << x;
			}
			else // Denta > 0
			{
				float x1 = (-b + sqrt(Denta)) / (2 * a);
				float x2 = (-b - sqrt(Denta)) / (2 * a);
				FileOut << "Phuong trinh co 2 nghiem phan biet:\nx1 = " << x1 << "\nx2 = " << x2;
			}
		}
	}

	FileOut.close();
}

int main()
{
	int a, b, c;
	ifstream FileIn;
	ofstream FileOut;

	DocFile(FileIn, a, b, c);
	GhiFile(FileOut, a, b, c);

	system("pause");
	return 0;
}