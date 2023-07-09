#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void NhapMang(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("\nNhap vao a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void GhiFile(FILE *&FileOut, int *a, int n)
{
	FileOut = fopen("TapTin.PPT", "wb");

	if(FileOut != NULL)
	{
		fwrite(a, sizeof(int), n, FileOut);
	}

	fclose(FileOut);
}

int main()
{
	int n = 5;
	int *a = (int *)malloc(n * sizeof(int));

	NhapMang(a, n);
	FILE *FileOut;
	GhiFile(FileOut, a, n);

	free(a);

	getch();
	return 0;
}