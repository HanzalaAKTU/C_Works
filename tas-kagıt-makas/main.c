#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() 
{
	 srand(time(NULL));
	 	 
		int kullanicideger=0, pcdeger=0, ksonuc=0, pcsonuc=0;	
		while(ksonuc!=5&&pcsonuc!=5)
		{		
			printf( "tas=1, makas=2, kagit=3 \nDeger giriniz:" );
			scanf("%d", &kullanicideger);
	
			pcdeger=rand()%3+1;
	
			printf("Bilgisayar degeri= %d\n", pcdeger);
			
			if(kullanicideger==1 && pcdeger==1)
				printf(" Berabere\n");
			
			else if(kullanicideger==1 && pcdeger==2)
			{   
			    printf(" Tebrikler siz kazandiniz\n");
				ksonuc++;
			}
			else if(kullanicideger==1 && pcdeger==3)
			{
				printf(" Bilgisayar kazandi\n");
				pcsonuc++;
			}
			else if(kullanicideger==2 && pcdeger==1)
			{
				printf(" Bilgisayar kazandi\n");
				pcsonuc++;
			}
			else if(kullanicideger==2 && pcdeger==2)
				printf(" Berabere\n");
			
			else if(kullanicideger==2 && pcdeger==3)
			{
				printf(" Tebrikler siz kazandiniz\n");
				ksonuc++;
			}
			else if(kullanicideger==3 && pcdeger==1)
			{
				printf(" Tebrikler siz kazandiniz\n");
				ksonuc++;
			}
			else if(kullanicideger==3 && pcdeger==2)
			{
				printf(" Bilgisayar kazandi\n");
				pcsonuc++;
			}
			else if(kullanicideger==3 && pcdeger==3)
				  printf(" Berabere\n");
			
		}

		if (pcsonuc==5)
			printf("\nBilgisayar kazandi");
			
		else if	(ksonuc==5)
			printf("\nTebrikler Kazandiniz");
		
}
