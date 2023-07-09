#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void DocFile(FILE *&FileIn, char *str)
{
	FileIn = fopen("INPUT.TXT", "r");

	if(!FileIn)
	{
		printf("\nKhong tim thay tap tin INPUT.TXT");
		getch();
		exit(0);
	}

	fgets(str, 100000, FileIn);

	fclose(FileIn);
}

int main()
{
	char str[100];
	FILE *FileIn;

	DocFile(FileIn, str);
	printf("\nChuoi doc duoc la: %s", str);

	getch();
	return 0;
}