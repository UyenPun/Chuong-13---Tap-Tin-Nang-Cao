#include <stdio.h>
#include <conio.h>

int main()
{
	FILE *FileIn = fopen("INPUT.TXT", "r"); // Mở file để đọc.

	// Kiểm tra xem tập tin có tồn tại hay không ?
	if(!FileIn)
	{
		printf("\nKhong tim thay tap tin INPUT.TXT");
		getch();
		return 0; // Kết thúc chương trình.
	}

	// Xử lý.
	int a, b; // 2 biến để đọc dữ liệu vào.
	fscanf(FileIn, "%d%d", &a, &b); // Đọc dữ liệu vào 2 số.
	
	/* Nếu làm chi tiết thì là thế này.
	fscanf(FileIn, "%d", &a);
	fscanf(FileIn, "%d", &b);
	*/

	fclose(FileIn); // Đóng file lại.

	FILE *FileOut = fopen("OUTPUT.TXT", "w"); // Mở tập tin để ghi.

	fprintf(FileOut, "%d + %d = %d\n", a, b, a + b);

	fclose(FileOut); // Đóng tập tin lại.

	getch();
	return 0;
}