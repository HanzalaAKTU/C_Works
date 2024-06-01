#include <stdio.h>

void triangle_pattern(int size);
void diamond_pattern(int size);

int main()
{
    int option=0;
    int size;

    do
    {
        printf("Enter option 1 to Pascal's Triangle Pattern\n");
        printf("Enter option 2 to Diamond\n");
        printf("Enter option 3 to exit\n");
        
        printf("Make your choice:");
        scanf("%d", &option);

        if (option==1)
        {
            printf("Enter the pattern size:");
            scanf("%d",&size);   
            printf("\n");         

            triangle_pattern(size);
        }

        if (option==2)
        {
            printf("Enter the pattern size:");
            scanf("%d",&size);
            printf("\n"); 

            diamond_pattern(size);
        }
        
        
    } while (option!=3);
    

}

void diamond_pattern(int size)
{    
    int heigh;
    heigh = size/2 + 1;
    for (int i = 1; i <= heigh; i++)
    {
        for (int j = 1;  j <= heigh-i; j++)
        {
            printf(" ");
        }
    
        for (int j = 1; j <= i*2-1; j++)
        {
            printf("*");
        }
        printf("\n");
    }  
      
   for (int i = heigh-1; i > 0; i--)
    {
        for(int j = 1;j <= heigh-i; j++)
        {
            printf(" ");
        }

        for(int j=1; j<= i*2-1;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void triangle_pattern(int size)
{
  int heigh;

  heigh = size * 2;
  for(int i = 1; i <= size; i++)
  {
        for(int j = 1; j <= i; j++) 
        {
          if(j == 1 )
                for(int k = 1; k <= heigh - i; k++)
                  printf(" ");
          printf("* ");
        }
        printf("\n");
  }
    
}
