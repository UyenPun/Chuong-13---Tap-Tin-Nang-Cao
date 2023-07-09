#include <stdio.h>
#include <conio.h>

void NhapDuLieu(int &a, int &b, int &c)
{
	printf("\nNhap a = ");
	scanf("%d", &a);

	printf("\nNhap b = ");
	scanf("%d", &b);

	printf("\nNhap c = ");
	scanf("%d", &c);
}

void GhiFile(FILE *&FileOut, int a, int b, int c)
{
	FileOut = fopen("OUTPUT.TXT", "w");
	if(FileOut != NULL)
	{
		fprintf(FileOut, "a = %d\nb = %d\nc = %d", a, b, c);
	}

	fclose(FileOut);
}

int main()
{
	int a, b, c;
	FILE *FileOut;
	
	NhapDuLieu(a, b, c);
	GhiFile(FileOut, a, b, c);

	getch();
	return 0;
}