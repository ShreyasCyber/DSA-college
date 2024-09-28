
#include <stdio.h>

int count = 0; // Global variable

void toh(int n, char source, char dest, char temp) {
    if (n > 0) {
        toh(n - 1, source, temp, dest);// 1st n-1
        count++; 
        printf("\nMove %d from tower %c to tower %c", n, source, dest);
        toh(n - 1, temp, dest, source);// 2nd n-1
    }
}

int main() {
    int n;
    
    printf("Enter the number: ");
    scanf("%d", &n); 
    
    toh(n, 'A', 'B', 'C');  // calling 
    
    printf("\n Total number of moves: %d\n", count);  
    
    return 0;
}

