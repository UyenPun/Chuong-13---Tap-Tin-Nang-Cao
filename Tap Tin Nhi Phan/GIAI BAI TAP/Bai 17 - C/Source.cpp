#include <stdio.h>
#include <conio.h>

void GhiFile(FILE *&FileOut, char *str)
{
	FileOut = fopen("OUTPUT.TXT", "w");

	if(FileOut != NULL)
	{
		fprintf(FileOut, "Chuoi ban nhap vao la: %s", str);
	}

	fclose(FileOut);
}

int main()
{
	char str[30];
	printf("\nMoi ban nhap vao chuoi: ");
	gets(str);

	FILE *FileOut;
	GhiFile(FileOut, str);

	getch();
	return 0;
}