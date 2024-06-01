#include <stdio.h>


void drawStickman(int position, char armStatus) {
    printf("\n");
    for (int i = 0; i < position; i++)
            printf(" ");
    printf("  O\n"); 
    if(armStatus== 's'){
         for (int i = 0; i < position; i++)
            printf(" "); 
    	printf(" /|\\\n");
	}
	else{
         for (int i = 0; i < position; i++)
            printf(" ");
		printf("  |\n"); 
	}
    for (int i = 0; i < position; i++)
            printf(" ");
    printf("  |\n");
    for (int i = 0; i < position; i++)
            printf(" ");
    printf(" / \\\n"); 

    
    for (int i = 0; i < position; ++i) {
        printf(" ");
    }
    printf("^"); 
    printf("\n");
}


int moveStickman(int position, char move) {
    switch (move) {
        case 'a': 
            position -= 2;
            break;
        case 'd': 
            position += 2;
            break;
        case 's': 

            break;
        default:
            printf("Invalid move. Please use 'a', 'd', or 's'.\n");
    }
    return position;
}

int main() {
    int position = 0; 
    char armStatus = 'n'; 

    char move;
    do {
        drawStickman(position, armStatus);
        printf("Enter move ('a' for left, 'd' for right, 's' to switch arms, 'e' to exit): ");
        scanf(" %c", &move);
    if(move=='s'){
    	armStatus= (armStatus=='n') ? 's' : 'n';
	}else{
		position= moveStickman(position,move);
	}
    } while (move !='e');

    printf("Exiting the program. Goodbye!\n");
        return 0;
}