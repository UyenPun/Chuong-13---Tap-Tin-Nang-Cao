#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Đọc dữ liệu từ file và lưu vào chuỗi HoTen.
void DocFile(FILE *&FileIn, int *&a, int &n)
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
	n = 100; // Cho trước.

	// Cấp phát con trỏ.
	a = (int *)malloc( n * sizeof(int *));
	
	int dem = 0;
	// Nếu chưa đi đến cuối file thì trả về 0, nếu đã đến cuối thì trả về khác 0.
	while(feof(FileIn) == 0) // Cách 2: while(!feof(FileIn))
	{
		fscanf(FileIn, "%d", &a[dem++]);
	}

	n = dem; // Cập nhật lại n.

	realloc(a, n * sizeof(int *)); // Cập nhật lại bộ nhớ.

	fclose(FileIn); // Đóng file lại.
}

void HoanVi(int &a, int &b)
{
	int Temp = a;
	a = b;
	b = Temp;
}

void SapXepTang(int *a, int n)
{
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(a[i] > a[j])
			{
				HoanVi(a[i], a[j]);
			}
		}
	}
}

void GhiFile(FILE *&FileOut, int *a, int n)
{
	FileOut = fopen("OUTPUT.TXT", "w"); // Mở tập tin để ghi.

	for(int i = 0; i < n; i++)
	{
		fprintf(FileOut, "%d ", a[i]);
	}

	fclose(FileOut); // Đóng tập tin lại.
}

int main()
{
	FILE *FileIn, *FileOut;

	int *a, n;

	DocFile(FileIn, a, n);

	SapXepTang(a, n);

	GhiFile(FileOut, a, n);

	free(a); // Giải phóng con trỏ.
	

	getch();
	return 0;
}