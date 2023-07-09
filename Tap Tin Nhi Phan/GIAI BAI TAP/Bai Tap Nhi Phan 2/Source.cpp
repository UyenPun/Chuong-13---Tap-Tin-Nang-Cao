#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void XuatMang(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%4d", a[i]);
	}
}

void DocFile(FILE *&FileIn, int *&a, int &n)
{
	FileIn = fopen("TapTin.DAT", "rb");

	if(!FileIn)
	{
		printf("\nKhong tim thay tap tin TapTin.DAT");
		getch();
		exit(0);
	}

	fseek(FileIn, 0, SEEK_END); // Cho con trỏ nhảy đến cuối tập tin.
	n = (ftell(FileIn) + 1) / sizeof(int);
	rewind(FileIn); // fseek(FileIn, 0, SEEK_SET); Cho con trỏ chạy về đầu.
	
	a = (int *)malloc(n * sizeof(int));

	fread(a, sizeof(int), n, FileIn);

	fclose(FileIn);
}

int main()
{
	int n, *a;
	FILE *FileIn;

	DocFile(FileIn, a, n);
	XuatMang(a, n);
	
	free(a);

	getch();
	return 0;
}