#include <iostream>
#include <fstream>
#include <vector>
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

	vector<int> arr;

	/* 
	vector có 2 cơ chế:
	Cơ chế 1: Nếu biết trước số lượng phần tử sẽ cấp phát:
	thì dùng resize(<Số lượng>)

	Cơ chế 2: Nếu không biết trước số lượng phần tử sẽ
	cấp phát thì dùng push_back(<Phần tử>)

	Lời khuyên nè: Dùng cơ chế 2 nhé

	*/

	int SoLuong;
	FileIn >> SoLuong;

	for(int i = 1; i <= SoLuong; i++)
	{
		int x; // Khởi tạo 1 đồi tượng x.
		FileIn >> x; // Đọc dữ liệu từ file vào x.

		arr.push_back(x); // Đưa x vào trong vector.
	}

	FileIn.close();


	ofstream FileOut("OUTPUT.TXT");

	int Max = arr[0];

	for(int i = 1; i < arr.size(); i++)
	{
		if(arr[i] > Max)
		{
			Max = arr[i];
		}
	}

	FileOut << Max;
	
	FileOut.close();

	system("pause");
	return 0;
}