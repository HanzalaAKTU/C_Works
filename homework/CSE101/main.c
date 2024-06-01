#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"arduino-serial-lib.h"
#include <time.h>

#define BUFFER_SIZE 100
#define TIME_OUT 1000

short menu();
void count_press();
void send_command(char* command);
void clearScreen();
void delay(int number_of_seconds) ;

int main()
{
	send_command("turn_on_led\n");
	while(1)
	{
		int selection;
		char command[20];
		selection = menu();
		char* response;

		switch (selection)
		{
			case 0: 
				exit(0);
				break;

			case 1: 
				strcpy( command, "turn_on_led\n"); 
				break;

			case 2: 
				strcpy( command, "turn_off_led\n"); 
				break;

			case 3: 
				strcpy( command, "flash_led\n");
			 	break;

			case 4: 
				strcpy( command, "square ");
				printf("Enter a number: ");
				char number[10];
				scanf("%s",number);
				strcat(command,number);
				strcat(command, "\n");
				break;

			case 5: 
				count_press(); 
				break;
		}

		if(selection != 5)
			send_command(command);

		printf("Press Enter to continue\n");
		getchar();
		getchar();	
		clearScreen();
	}

	return 0;
}

short menu()
{

	printf(
	"## WELCOME TO GTU ARDUINO LAB          ##\n"
	"## STUDENT NAME: MUHAMMED HANZALA AKTU ##\n"
	"## PLEASE SELECT FROM THE FOLLOWING    ##\n"
	"## MENU :                              ##\n"
	"(1) TURN ON LED ON ARDUINO\n"
	"(2) TURN OFF LED ON ARDUINO\n"
	" (3) FLASH ARDUINO LED 3 TIMES\n"
	"(4) SEND A NUMBER TO ARDUINO TO COMPUTE SQUARE BY ARDUINO\n"
	"(5) Button press counter \n(0) EXIT\nPLEASE SELECT:");
	
	int selection;
	scanf("%d",&selection);

	if(selection < 0 || selection > 5)
		return menu();
	else
		return selection;
}

void send_command(char* command)
{
	char serialPort[] = "/dev/ttyUSB0"; 
	int baud = 9600;
	int fd = serialport_init(serialPort,baud);		

	serialport_write(fd,command);
	
	char buffer[BUFFER_SIZE];

	serialport_read_until(fd,buffer,'\n',BUFFER_SIZE,TIME_OUT);
	printf("\nmessage: %s\n",buffer);
}

void count_press()
{
	char serialPort[] = "/dev/ttyUSB0"; 
	int baud = 9600;
	int fd = serialport_init(serialPort,baud);		
	char buffer[BUFFER_SIZE] = "first";
	char old[10];
	serialport_write(fd,"count_press\n");
	clearScreen();
	printf("click: 0");
	while(1)
	{
		serialport_read_until(fd,buffer,'\n',BUFFER_SIZE,2000);
		clearScreen();
		printf("click: %s",buffer);
		delay(1);
	}
	
}

void take_response(int* fd)
{
	char buffer[BUFFER_SIZE];
	serialport_read_until(*fd,buffer,'.',BUFFER_SIZE,TIME_OUT);
	printf("message: %s",buffer);
}

void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds) 
        ; 
} 

void clearScreen()
{
	printf("\e[1;1H\e[2J");					// clears the screen
}

