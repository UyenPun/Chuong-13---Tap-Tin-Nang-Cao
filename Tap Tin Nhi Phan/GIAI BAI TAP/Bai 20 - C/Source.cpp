#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int DemSoTu(FILE *&FileIn)
{
	int dem = 0;
	FileIn = fopen("INPUT.TXT", "r");

	if(!FileIn)
	{
		printf("\nKhong tim thay tap tin INPUT.TXT");
		getch();
		exit(0);
	}

	while(!feof(FileIn))
	{
		char str[30];
		fscanf(FileIn, "%s", str);
		dem++;
		printf("\nTu thu %d la: %s", dem, str);
	}
	fclose(FileIn);
	return dem;
}

void GhiFile(FILE *&FileOut, int SoLuong)
{
	FileOut = fopen("OUTPUT.TXT", "w");
	
	if(FileOut != NULL)
	{
		fprintf(FileOut, "So luong tu la: %d", SoLuong);
	}

	fclose(FileOut);
}

int main()
{
	FILE *FileIn, *FileOut;
	int SoLuong = DemSoTu(FileIn);

	GhiFile(FileOut, SoLuong);

	getch();
	return 0;
}