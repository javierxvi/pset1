#include <cs50.h>
#include <stdio.h>

int main(void) {
    int h; 
    
    do {
        h = get_int("Height: ");
    }
    while ((h <= 0) || (h > 8));
    
    for (int i = 0; i < h; i++) {
    
        for (int a = h-1-i; a > 0; a--) {
            printf(" ");
        }
        
        for (int b = h-1-i; b < h; b++) {
            printf("#");
        }
        
        printf("  ");
        
        for (int c = 0; c < i+1; c++) {
            printf("#");
        }
        
        printf("\n");
    }
}
