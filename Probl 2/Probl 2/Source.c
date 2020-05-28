#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

int minim(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int** t, **smin;
	int n, i, j, pmin;
	FILE* f, * g;
	f = fopen("date.in", "r");
	g = fopen("date.out", "w");
	fscanf(f, "%d", &n);
	t = (int**)calloc(n, sizeof(int*));
	smin = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++)
		for (j = 0; j < i + 1; j++)
		{
			t[i] = (int*)calloc(i + 1, sizeof(int));
			smin[i] = (int*)calloc(i + 1, sizeof(int));
		}
	for (i = 0; i < n; i++)
		for (j = 0; j < i+1; j++)
			fscanf(f, "%d", &t[i][j]);
	fclose(f);
	smin[0][0] = t[0][0];
	for (i = 1; i < n; i++)
		for (j = 0; j < i + 1; j++)
			if (j == 0)
				smin[i][j] = t[i][j] + smin[i - 1][j];
			else
				if (j == i)
					smin[i][j] = t[i][j] + smin[i - 1][j - 1];
				else
					smin[i][j] = t[i][j] + minim(smin[i - 1][j], smin[i - 1][j - 1]);
	pmin = 0;
	for (j = 1; j < n; j++)
		if (smin[n - 1][j] < smin[n - 1][pmin]) pmin = j;
	fprintf(g, "%d", smin[n - 1][pmin]);
	fclose(g);
	for (i = 0; i < n; i++)
		{
			free(t[i]);
			free(smin[i]);
		}
	free(t);
	free(smin);
}