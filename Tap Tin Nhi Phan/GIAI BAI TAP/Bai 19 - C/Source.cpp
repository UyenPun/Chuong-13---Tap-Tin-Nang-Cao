#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int DemSoKyTuChuCai(FILE *&FileIn)
{
	int dem = 0;
	FileIn = fopen("INPUT.TXT", "r");

	if(!FileIn)
	{
		printf("\nKhong tim thay tap tin INPUT.TXT");
		getch();
		exit(0);
	}

	char c;
	while((c = fgetc(FileIn)) != EOF)
	{
		if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		{
			dem++;
		}
	}
	fclose(FileIn);
	return dem;
}

void GhiFile(FILE *&FileOut, int SoLuong)
{
	FileOut = fopen("OUTPUT.TXT", "w");
	
	if(FileOut != NULL)
	{
		fprintf(FileOut, "So luong ky tu la chu cai la: %d", SoLuong);
	}

	fclose(FileOut);
}

int main()
{
	FILE *FileIn, *FileOut;
	int SoLuong = DemSoKyTuChuCai(FileIn);

	GhiFile(FileOut, SoLuong);

	getch();
	return 0;
}