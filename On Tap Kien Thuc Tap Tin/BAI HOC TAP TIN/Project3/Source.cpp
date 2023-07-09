#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Đọc dữ liệu từ file và lưu vào chuỗi HoTen.
void DocFile(FILE *&FileIn, char HoTen[30])
{
	FileIn = fopen("INPUT.TXT", "r"); // Mở file để đọc.

	// Kiểm tra xem tập tin có tồn tại hay không ?
	if(!FileIn)
	{
		printf("\nKhong tim thay tap tin INPUT.TXT");
		getch();
		exit(0); // Kết thúc chương trình.
	}

	// Xử lý.
	
	fgets(HoTen, 30, FileIn);

	fclose(FileIn); // Đóng file lại.
}

void GhiFile(FILE *&FileOut, char HoTen[30])
{
	FileOut = fopen("OUTPUT.TXT", "w"); // Mở tập tin để ghi.

	fprintf(FileOut, "Chao %s", HoTen);

	fclose(FileOut); // Đóng tập tin lại.
}

int main()
{
	char HoTen[30];
	FILE *FileIn, *FileOut;

	DocFile(FileIn, HoTen);
	GhiFile(FileOut, HoTen);

	getch();
	return 0;
}