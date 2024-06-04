#include <stdio.h>
 
	int main () 
{
	int satir,n,j,bosluk;
	char a;

	printf("karakterinizi giriniz");
	scanf("%c",&a);
 
	printf("uzunlugunu yaziniz");
	scanf("%d",&n);
 
	for(satir=1; satir<=n; satir++)
	{ 
		for(bosluk=1; bosluk<=n-satir; bosluk++)
 			printf(" "); 
 			
		for(j=1; j<=2*satir-1; j++) 
			printf("%c",a);
 
		printf("\n");
 
	}
 
	for(satir=n-1; satir>=1; satir--)
	{ 
		for(bosluk=1; bosluk<=n-satir; bosluk++)
			printf(" ");
 
		for(j=1; j<=2*satir-1; j++)
			printf("%c",a); 
		
		printf("\n"); 
	}
	
return(0); 

}
