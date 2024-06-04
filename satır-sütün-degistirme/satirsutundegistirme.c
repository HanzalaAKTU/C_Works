#include <stdio.h>
#include <time.h>

main()
{
	srand(time(NULL));

	int random[3][6];
	int random2[6][3];
	int i, j, sayi;

	for(i=0; i<3; i++)
	{
		for(j=0; j<6; j++)
		{
			sayi = rand()%25+20;	
			printf("%d ", sayi);
			random[i][j] = sayi;
		}
		printf("\n");
	}
	for(i=0; i<6; i++)
	{
		for(j=0; j<3; j++)
		{
			random2[i][j] = random[j][i];
			printf("%d ", random2[i][j]);
		}
		printf("\n");
	}
}
