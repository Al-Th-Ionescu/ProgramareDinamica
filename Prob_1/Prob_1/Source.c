#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main()
{
	int n, * v, j, i, s, * t, *contor;
	FILE* f, *g;
	f = fopen("date.in", "r");
	g = fopen("date.out", "w"); 
	fscanf(f, "%d", &n);
	v = calloc((n+1), sizeof(int));
	t = calloc(n+1, sizeof(int));
	contor = calloc(n + 1, sizeof(int));
	for (i = 1; i <= n; i++)
		fscanf(f, "%d", &v[i]);
	fscanf(f, "%d", &s);
	fclose(f);
	j = n+1;
	conditie:
	while (j != 0)
	{
		j--;
		if (v[j] <= s)
		{
			t[j] = v[j];
			break;
		}
		j--; 
	}
	printf("%d ~~", j);
		i = j;
		while (i > 0)
		{
			printf("%d ", t[i]);
			if (s == t[i])
			{
				fprintf(g, "%d", i);
				break;
			}
			if (s >= t[i])
			{
				if (s >= t[i] + v[i - 1])
				{	
					t[i - 1] = t[i] + v[i - 1];
					if (contor[i] == 0)
					fprintf(g, "%d ", i);
					}
				else if (s < t[i] + v[i - 1])
				{
					t[i - 1] = t[i];
					contor[i-1]=1;
					if (contor[i] == 0)
					fprintf(g, "%d ", i);

				}
				i--;
			}
			else
			{
				i--;
			}
			if (i == 0) {
				memset(contor, 0, j* sizeof(int));
				fseek(g, 0, SEEK_SET);
				goto conditie;
			}
		}
	
	fclose(g);
	free(contor);
	free(v);
	free(t);
	return 0;
}