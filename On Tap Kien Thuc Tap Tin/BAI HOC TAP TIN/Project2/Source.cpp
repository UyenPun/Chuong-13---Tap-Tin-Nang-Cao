#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Đọc dữ liệu từ file và lưu vào 2 biến a, b.
void DocFile(FILE *&FileIn, int &a, int &b)
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
	
	fscanf(FileIn, "%d%d", &a, &b); // Đọc dữ liệu vào 2 số.

	/* Nếu làm chi tiết thì là thế này.
	fscanf(FileIn, "%d", &a);
	fscanf(FileIn, "%d", &b);
	*/

	fclose(FileIn); // Đóng file lại.
}

void GhiFile(FILE *&FileOut, int a, int b)
{
	FileOut = fopen("OUTPUT.TXT", "w"); // Mở tập tin để ghi.

	fprintf(FileOut, "%d + %d = %d\n", a, b, a + b);

	fclose(FileOut); // Đóng tập tin lại.
}

int main()
{
	int a, b;
	FILE *FileIn, *FileOut;

	DocFile(FileIn, a, b);
	GhiFile(FileOut, a, b);

	getch();
	return 0;
}