#include <stdio.h>
#include <stdlib.h>


int main() 
{
	int a, b;
	while(1)
	{
		printf("\nPlease enter a number: ");
		scanf("%d", &a);
		printf("Please enter a number: ");
		scanf("%d", &b);
		int choice;
		printf("Addition:0, Subsraction:1, Exit:-1\n Your choice: ");
		scanf("%d", &choice);
		
		if(choice == 0)
			printf("%d + %d = %d", a, b, a+b);
		
		else if(choice == 1)
			printf("%d - %d = %d", a, b, a-b);
		
		else if(choice == -1)
			break;
		
		else
			printf("Invalid operation");
		
		return 0;
	}

	
	return 0;
}
