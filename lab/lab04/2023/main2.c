#include <stdio.h>

void draw_square(int size) 
{
    int i, j;
    for (i = 0; i < size; i++) 
    {
        for (j = 0; j < size; j++) 
        {
            if (i == 0 || i == size-1 || j == 0 || j == size-1) 
                printf("* ");
             
            else 
                printf("  ");
            
        }
        printf("\n");
    }
}

void draw_triangle(int size) 
{
    int i, j;
    
    for (i = 0; i < size; i++) 
    {
        for (j = 0; j < size-i-1; j++) 
            printf(" ");
        
        for (j = 0; j < 2*i+1; j++) 
        {
            if (i == 0 || i == size-1 || j == 0 || j == 2*i) 
                printf("*");
            
            else 
                printf(" ");
            
        }

        printf("\n");
    }
}

void write_shapes_to_file() 
{
    FILE *f = fopen("shapes.txt", "w");
    char shape_type;
    int size;
    while (1) 
    {
        printf("Enter the shape type (s for square, t for triangle, or e to exit): ");
        scanf(" %c", &shape_type);
       
        if (shape_type == 'e') 
            break;
        
        printf("Enter the size of the shape (between 3 and 10): ");
        scanf("%d", &size);
       
        if (shape_type == 's') 
        {
            draw_square(size);
            fprintf(f, "square,%d\n", size);
        } 
       
        else if (shape_type == 't') 
        {
            draw_triangle(size);
            fprintf(f, "triangle,%d\n", size);
        } 
       
        else 
        {
            printf("Invalid shape type. Please try again.\n");
            continue;
        }
    }
    fclose(f);
}

int main() 
{
    write_shapes_to_file();
    return 0;
}
