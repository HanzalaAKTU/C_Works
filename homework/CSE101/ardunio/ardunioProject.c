#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>

#define MAX 20

void intro_func()
{
    printf("\n");
}

void delay_func(int delay_time)     //Arduino'dan gelecek verileri beklemek icin zaman gecirten fonksiyon
{									
	int i,j,k;

	for( i=0;i<delay_time;i++)
    {
		for( j=0;j<9999;j++)
        {
			for( k=0;k<20;k++)
            { 

            }
		}
	}
}

void red ()                         //renk degistirme kodu
{                                   
    printf("\033[1;31m");
}

void black () 
{
    printf("\033[0;30m");
}

void reset ()                          //olusturmus oldugumuz rengi resetler
{                                   
    printf("\033[0m");
}

int main()
{
    char portArdunio = open("/dev/ttyS0", O_RDWR | O_NOCTTY | O_NDELAY );
    char selection[MAX];
    red ();
    intro_func();
    reset();
    printf("\n\n");
    
    printf("--!*/    WELCOME TO GTU ARDUINO LAB            /*!--\n");      
	printf("--!*/    STUDENT NAME: MUHAMMED HANZALA AKTU   /*!--\n");
	printf("--!*/    PLEASE SELECT FROM THE FOLLOWING      /*!--\n");
    
    do
    {
        printf("\n---------------***************---------------\n");
        printf("\n--!*/ \t\tARDUINO MENU\t\t /*!--\n\n");
	    printf("[1] TURN ON LED ON ARDUINO\n");
	    printf("[2] TURN OFF LED ON ARDUINO\n");
	    printf("[3] FLASH ARDUINO LED 3 TIMES\n");
	    printf("[4] SEND A NUMBER TO ARDUINO TO COMPUTE SQUARE BY ARDUINO\n");
	    printf("[5] BUTTON PRESS COUNTER\n");
	    printf("[0] EXIT\n");

        printf("\nSELECT MENU(0-5):");
        scanf("%s",selection);

        while(getchar()!= '\n');

        switch (selection[0])
        {
            case '1':
                
                portArdunio = open("/dev/ttyS0", O_RDWR | O_NOCTTY | O_NDELAY );
                write(portArdunio,"1",2);														// Arduinoya '1' karakterini gonderir

	            printf("\n       -LED TURNED ON-      \n\n");
                close(portArdunio);
                break;
            
            case '2':
                portArdunio = open("/dev/ttyS0", O_RDWR | O_NOCTTY | O_NDELAY );

                write(portArdunio,"2",2);														// Arduinoya '2' karakterini gonderir

	            printf("\n       -LED TURNED OF-      \n\n");
                close(portArdunio);
                break;
            
            case '3':
                
                portArdunio = open("/dev/ttyS0", O_RDWR | O_NOCTTY | O_NDELAY );
                write(portArdunio,"3",2);														// Arduinoya '3' karakterini gonderir

	            printf("\n  -LED FLASHED 3 TIMES ON ARDUNIO-  \n\n");
                close(portArdunio);
                break;

            case '4':
                portArdunio = open("/dev/ttyS0", O_RDWR | O_NOCTTY | O_NDELAY );			// Serial baglantiyi kurmayi saglsr
                delay_func(500);

                write(portArdunio,"4",1);														// Arduinoya '4' karakterini gonderir

                char num[10];      						                                        //Kullanicidan sayi alir
                        
                int lenght;										                                //Kullanicidan alinan sayinin uzunlugunu
                char recieve_data[MAX];						                                    //Arduino hesapladıktan sonra saklanacak yer
                char read_byte;								                                    //Okunan her byten saklnadigi yer
                int result;									                                    //Sonucun atanacagi degisken 

                printf("----------------------------\n");		
                printf("Enter the number :  ");
                scanf("%s",num);							//Kullanıcıdan hesaplanması istedigi sayı alinir		

                lenght=strlen(num);							//Strlen uzunlugu belirlenir

               
                portArdunio = open("/dev/ttyS0", O_RDWR | O_NOCTTY | O_NDELAY );
                write(portArdunio,num,lenght);

                printf(" Calculating \n");	
                        
                delay_func(9000);								//Arduinonun hesapi icin tanin sure 
                                        
                read_byte = read(portArdunio,recieve_data,9);		//Arduinodan verileri okur	
                        
                result = atoi(recieve_data);						//String integer'a cevirir  
                printf("\n=  Square of %s^2 : %d  =\n\n",num,result);	//Sonucu ekrana yazdırır	

                close(portArdunio); 
                break;
            
            case '0':
	            printf("\n=    EXITING THE PROGRAM    =\n\n");
                break;
            
            default:
                break;
        }
    }
    while(selection[0] !='0' );

    return 0;
}