#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	if(N == 1)	{	printf("1\n");	return 0;	}
	if(N == 2)	{	printf("2\n");	return 0;	}

	int a = 1, b = 2, c;
	int i;
	for(i=1;i<N-1;i++)
	{
		c = a + b;
		if(c >= 15746)	c -= 15746;
		a = b;
		b = c;
	}

	printf("%d\n", c % 15746);

	return 0;
}