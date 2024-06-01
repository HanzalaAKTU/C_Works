#include<stdio.h>

void write_file(FILE *f,int num)
{
    f = fopen("orders.txt","a");
    if(f == NULL) printf("File cannot open!\n");

    fprintf(f," %d",num);
    fclose(f);

    printf("The result is written to the results.txt file.\n");
}

void readOrders( void(*print_day)(int d2))
{
    FILE *f;
    int flag,d1,d2;
  
    f = fopen("orders.txt","r");
    if(f == NULL) printf("File cannot open!\n");
    
    fscanf(f,"%d %d",&d1,&d2);
    fclose(f);

    printf("%d",d1);
    print_day(d2);
    
}

void print_days(int d2)
{
    if(d2==0) printf(",Day: Sunday");
    if(d2==1) printf(",Day: Monday");
    if(d2==2) printf(",Day: Tuesday");
    if(d2==3) printf(",Day: Wednesday");
    if(d2==4) printf(",Day: Thursday");
    if(d2==5) printf(",Day: Friday");
    if(d2==6) printf(",Day: Saturday");          
}

int main()
{
    int flag,d1,d2;
    int i,today;
    FILE *f;

    enum Products {Harddisk=0,Monitor,Keyboard,Mouse};
    enum Days {Sunday=0,Monday,Tuesday,Wednesday,Thursday,Friday,Saturday};
    enum Selections {Buy=1,Orders,Prices,Exit};

    do
    {

        printf("\n\tWelcome to the TechMarket.\n");
        printf("\t1. Buy Product \n");
        printf("\t2. Orders \n");
        printf("\t3. All Orders Prices \n");
        printf("\t4. EXIT\n");
        printf("---------------------------------\n");

        enum Selections ask1;
        scanf("%u",&ask1);

        if (ask1==Exit)
        {
            break;
        }
        
        if (ask1==Buy)
        {
            printf("\n\tSelect Your Product\n");
            printf("\t0. HARDDISK \n");
            printf("\t1. MONITOR \n");
            printf("\t2. KEYBOARD \n");
            printf("\t3 MOUSE \n");
            printf("---------------------------------\n");
    
            
            enum Products ask2;
            scanf("%u",&ask2);
        
            printf("Select Your Arrival Day[0-6] :\n");
            printf("Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday\n");
            printf("---------------------------------\n");
        
            enum Days ask3;
            scanf("%u",&ask3);

            f = fopen("orders.txt","a");
            if(f == NULL) printf("File cannot open!\n");
            fprintf(f," %u %u",ask2,ask3);
            fclose(f);
        }
            
        if (ask1==Orders)
        {
            printf("Product ID: ");
            
            readOrders(&print_days);    
        }    

        
        
    }
    while (1);
}