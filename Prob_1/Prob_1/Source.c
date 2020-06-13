#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int sp[100001];

int main()
{
	FILE* f, * g;
	f = fopen("date.in", "r");
	g = fopen("date.out", "w");
	int* m, n, s, ss, i;
	fscanf(f, "%d", &n);
	m = malloc((n+1) * sizeof(int));
	for (i = 1; i <= n; i++)
		fscanf(f, "%d", &m[i]);
	fscanf(f, "%d", &s);
	fclose(f);
	sp[0] = 1;
	for (i = 1; i <= n; i++)
		for (ss = s - m[i]; ss >= 0; ss--)
			if (sp[ss] && sp[ss + m[i]] == 0)
				sp[ss + m[i]] = i;
	if (sp[s])
	{
		int sc = s;
		while (sc)
		{
			fprintf(g, "%d ", sp[sc]);
			sc -= m[sp[sc]];
		}
	}
	else fprintf(g, "nu se poate obtine suma");
	fclose(g);
	free(m);
	return 0;

			

}