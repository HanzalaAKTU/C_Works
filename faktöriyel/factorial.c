#include <stdio.h>
#include <stdlib.h>

int main()
{
	int t, sum;
	sum=1;
	printf("Which number do you want to print faxtorial: \n");
	scanf("%d", &t);
	while(1<=t)
	{
		sum=sum*t;
		t--;
	}
	printf("sum=%d",sum);
	
	return 0;
}
