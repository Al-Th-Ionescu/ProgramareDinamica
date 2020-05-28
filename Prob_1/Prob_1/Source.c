#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

int main()
{
	int n, * v, j, i, s, * t;
	FILE* f, *g;
	f = fopen("date.in", "r");
	g = fopen("date.out", "w"); 
	fscanf(f, "%d", &n);
	v = malloc((n+1) * sizeof(int));
	t = calloc(n+1, sizeof(int));
	for (i = 1; i <= n; i++)
		fscanf(f, "%d", &v[i]);
	fscanf(f, "%d", &s);
	fclose(f);
	j = n;

	while (j != 0)
	{
		if (t[j] < s)
		{
			t[j] = v[j];
			break;
		}
	}
	
		i = j;
		while (i > 0)
		{
			if (s == v[i])
			{
				fprintf(g, "%d", i);
				break;
			}
			if (s >= t[i] + v[i - 1] && i != 1)
			{

				t[i - 1] = t[i] + v[i - 1];
				fprintf(g, "%d ", i);
				i--;
			}
			else
			{
				t[i - 1] = 0;
				i--;
			}

			printf("%d ", t[i]);
		}
	
	fclose(g);
	free(v);
	free(t);
	return 0;
}