#include <stdio.h>

int main() 
{
    int a[10][10], b[10][10], sum[10][10];
    int i, j, r, c;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter first matrix elements:\n");
    for (i = 0; i < r; i++) 
    {
        for (j = 0; j < c; j++) 
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter second matrix elements:\n");
    for (i = 0; i < r; i++) 
    {
        for (j = 0; j < c; j++) 
        {
            scanf("%d", &b[i][j]);
        }
    }

    for (i = 0; i < r; i++) 
    {
        for (j = 0; j < c; j++) 
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("Sum of the entered matrices:\n");
    for (i = 0; i < r; i++) 
    {
        for (j = 0; j < c; j++) 
        {
            printf("%d\t", sum[i][j]);
        }
        printf("\n"); 
    }

    return 0;
}
