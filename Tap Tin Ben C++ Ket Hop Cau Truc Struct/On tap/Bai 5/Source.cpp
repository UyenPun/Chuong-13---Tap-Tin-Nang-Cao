#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct SinhVien
{
	string HoTen, SoDienThoai;
	int Ngay, Thang, Nam;
	float DiemToan, DiemLy, DiemHoa;
};
typedef struct SinhVien SINHVIEN;

void Nhap1SinhVien(ifstream &FileIn, SINHVIEN &x)
{
	getline(FileIn, x.HoTen, '-');
	x.HoTen.erase(x.HoTen.begin() + x.HoTen.length() - 1); // Xóa ky tu cuoi cung.

	FileIn.seekg(1, 1); // Bỏ đi khoảng trắng.

	FileIn >> x.SoDienThoai;

	FileIn.seekg(3, 1); // Dịch qua 3 bytes.

	FileIn >> x.Ngay;

	FileIn.seekg(1, 1); // Bỏ đi dấu /

	FileIn >> x.Thang;

	FileIn.seekg(1, 1); // Bỏ đi dấu /

	FileIn >> x.Nam;

	FileIn.seekg(3, 1); // Dịch qua 3 bytes.

	FileIn >> x.DiemToan >> x.DiemLy >> x.DiemHoa;

	// Có biến này để mà đọc cái ký tự cuối dòng.
	string temp;
	getline(FileIn, temp);
}

float TinhDiemTrungBinh(SINHVIEN x)
{
	return (x.DiemToan + x.DiemLy + x.DiemHoa) / 3;
}

void Xuat1SinhVien(ofstream &FileOut, SINHVIEN x)
{
	FileOut << "\nHo ten: " << x.HoTen;
	FileOut << "\nSo dt: " << x.SoDienThoai;
	FileOut << "\nSinh ngay " << x.Ngay << " thang " << x.Thang << " nam " << x.Nam;
	FileOut << "\nDiem toan: " << x.DiemToan;
	FileOut << "\nDiem ly: " << x.DiemLy;
	FileOut << "\nDiem hoa: " << x.DiemHoa;
	FileOut << "\nDiem trung binh: " << TinhDiemTrungBinh(x);

	FileOut << "\n\n-------------------------------------------\n";
}



void HoanVi(SINHVIEN &a, SINHVIEN &b)
{
	SINHVIEN Temp = a;
	a = b;
	b = Temp;
}

void NhapMangSinhVien(ifstream &FileIn, vector<SINHVIEN> &arr)
{
	while(!FileIn.eof())
	{
		SINHVIEN x;
		Nhap1SinhVien(FileIn, x);
		arr.push_back(x);
	}
}

void XuatMangSinhVien(ofstream &FileOut, vector<SINHVIEN> arr)
{
	for(int i = 0; i < arr.size(); i++)
	{
		Xuat1SinhVien(FileOut, arr[i]);
	}
}

void SapXepGiamDanTheoDiemTrungBinh(vector<SINHVIEN> &arr)
{
	for(int i = 0; i < arr.size() - 1; i++)
	{
		for(int j = i + 1; j < arr.size(); j++)
		{
			if(TinhDiemTrungBinh(arr[i]) < TinhDiemTrungBinh(arr[j]))
			{
				HoanVi(arr[i], arr[j]);
			}
		}
	}
}

int main()
{
	ifstream FileIn("INPUT.TXT");

	vector<SINHVIEN> arr;

	NhapMangSinhVien(FileIn, arr);

	FileIn.close();

	ofstream FileOut("OUTPUT.TXT");

	SapXepGiamDanTheoDiemTrungBinh(arr);
	XuatMangSinhVien(FileOut, arr);

	FileOut.close();

	system("pause");
	return 0;
}