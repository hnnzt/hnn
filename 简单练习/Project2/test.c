#include <stdio.h>
#include <math.h>
int main()
{
	int n, m, i;
	for (n = 101; n<200; n = n + 2)
	{
		m = sqrt(n);
		for (i = 2; i <= m; i++)
		if (n%i == 0)break;
		if (i >= m + 1)
		{
			printf("%d ", n);
			system("pause");
		}
	}
	return 0;
}

