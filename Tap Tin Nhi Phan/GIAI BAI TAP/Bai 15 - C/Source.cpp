#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

// Đọc dữ liệu từ file vào chương trình.
void DocFile(FILE *&FileIn, int &a, int &b, int &c)
{
	FileIn = fopen("INPUT.TXT", "r");

	if(!FileIn)
	{
		printf("\nKhong tim thay tap tin INPUT.TXT");
		getch();
		exit(0); // Kết thúc toàn bộ chương trình.
	}

	fscanf(FileIn, "%d%d%d", &a, &b, &c);

	fclose(FileIn);
}

// Xử lý và ghi kết quả ra file.
void GhiFile(FILE *&FileOut, int a, int b, int c)
{
	FileOut = fopen("OUTPUT.TXT", "w");
	
	if(FileOut != NULL)
	{
		// Xử lý giải phương trình.
		if(a == 0) // bx + c = 0
		{
			if(b == 0)
			{
				if(c == 0)
				{
					fprintf(FileOut, "Phuong trinh co vo so nghiem");
				}
				else
				{
					fprintf(FileOut, "Phuong trinh vo nghiem");
				}
			}
			else
			{
				float x = (float)-c / b;
				fprintf(FileOut, "Phuong trinh co 1 nghiem duy nhat: x = %f", x);
			}
		}
		else
		{
			float Denta = b * b - 4 * a * c;
			if(Denta < 0)
			{
				fprintf(FileOut, "Phuong trinh vo nghiem");
			}
			else if(Denta == 0)
			{
				float x = (float)-b / (2 * a);
				fprintf(FileOut, "Phuong trinh co nghiem kep: x1 = x2 = %f", x);
			}
			else // Denta > 0
			{
				float x1 = (-b + sqrt(Denta)) / (2 * a);
				float x2 = (-b - sqrt(Denta)) / (2 * a);
				fprintf(FileOut, "Phuong trinh co 2 nghiem phan biet:\nx1 = %f\nx2 = %f", x1, x2);
			}
		}
	}

	fclose(FileOut);
}

int main()
{
	int a, b, c;
	FILE *FileIn, *FileOut;

	DocFile(FileIn, a, b, c);
	GhiFile(FileOut, a, b, c);

	getch();
	return 0;
}