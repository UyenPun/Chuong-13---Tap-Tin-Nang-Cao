#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct PhanSo
{
	int TuSo, MauSo;
};
typedef struct PhanSo PHANSO;

void DocFile(FILE *&FileIn, PHANSO &a, PHANSO &b)
{
	FileIn = fopen("INPUT.TXT", "r");

	if(!FileIn)
	{
		printf("\nKhong tim thay tap tin INPUT.TXT");
		getch();
		exit(0); // Kết thúc chương trình.
	}

	// Xử lý.
	fscanf(FileIn, "%d", &a.TuSo); // Đọc vào tử số.
	/*
	Cách xử lý 1.
	char c;
	fscanf(FileIn, "%c", &c);*/
	
	// Cách xử lý 2: Dịch con trỏ chỉ vị.
	fseek(FileIn, 1, SEEK_CUR); // Dịch 1 byte kể từ vị trí hiện tại.
	
	fscanf(FileIn, "%d", &a.MauSo); // Đọc vào mẫu số.

	fscanf(FileIn, "%d", &b.TuSo);
	
	fseek(FileIn, 1, SEEK_CUR); // Dịch 1 byte kể từ vị trí hiện tại.

	fscanf(FileIn, "%d", &b.MauSo);

	fclose(FileIn);
}

int TimUCLN(int a, int b)
{
	if(a < 0)
	{
		a *= -1;
	}

	if(b < 0)
	{
		b *= -1;
	}

	while(a != b)
	{
		if(a > b)
		{
			a -= b;
		}
		else
		{
			b -= a;
		}
	}
	return a;
}

void RutGon(PHANSO &x)
{
	int ucln = TimUCLN(x.TuSo, x.MauSo);
	x.TuSo /= ucln;
	x.MauSo /= ucln;
}

PHANSO operator +(PHANSO a, PHANSO b)
{
	PHANSO Tong;
	Tong.TuSo = a.TuSo * b.MauSo + a.MauSo * b.TuSo;
	Tong.MauSo = a.MauSo * b.MauSo;
	RutGon(Tong);
	return Tong;
}

PHANSO operator -(PHANSO a, PHANSO b)
{
	PHANSO Hieu;
	Hieu.TuSo = a.TuSo * b.MauSo - a.MauSo * b.TuSo;
	Hieu.MauSo = a.MauSo * b.MauSo;
	RutGon(Hieu);
	return Hieu;
}

PHANSO operator *(PHANSO a, PHANSO b)
{
	PHANSO Tich;
	Tich.TuSo = a.TuSo * b.TuSo;
	Tich.MauSo = a.MauSo * b.MauSo;
	RutGon(Tich);
	return Tich;
}

PHANSO operator /(PHANSO a, PHANSO b)
{
	PHANSO NghichDao;
	NghichDao.TuSo = b.MauSo;
	NghichDao.MauSo = b.TuSo;

	PHANSO KetQua = a * NghichDao;
	RutGon(KetQua);
	return KetQua;
}

void GhiFile(FILE *&FileOut, PHANSO a, PHANSO b)
{
	FileOut = fopen("OUTPUT.TXT", "w");
	
	PHANSO Tong, Hieu, Tich, Thuong;
	Tong = a + b;
	Hieu = a - b;
	Tich = a * b;
	Thuong = a / b;

	fprintf(FileOut, "Tong: %d/%d\n", Tong.TuSo, Tong.MauSo);
	fprintf(FileOut, "Hieu: %d/%d\n", Hieu.TuSo, Hieu.MauSo);
	fprintf(FileOut, "Tich: %d/%d\n", Tich.TuSo, Tich.MauSo);
	fprintf(FileOut, "Thuong: %d/%d\n", Thuong.TuSo, Thuong.MauSo);

	fclose(FileOut);
}

int main()
{
	PHANSO a, b;
	FILE *FileIn, *FileOut;
	DocFile(FileIn, a, b);
	GhiFile(FileOut, a, b);

	getch();
	return 0;
}