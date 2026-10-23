#include <stdio.h>

int main()
{
    char op;
    float a, b, result;

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op); // Notice the leading space before %c to clear the newline buffer

    printf("Enter two numbers: ");
    scanf("%f %f", &a, &b);

    switch (op)
    {
        case '+': 
            result = a + b; 
            printf("Result = %.2f\n", result); 
            break;
        case '-': 
            result = a - b; 
            printf("Result = %.2f\n", result); 
            break;
        case '*': 
            result = a * b; 
            printf("Result = %.2f\n", result); 
            break;
        case '/': 
            if (b = 0)
            {
                printf("Cannot be divided by zero\n");
            }
            else
            {
                result = a / b;
                printf("Result = %.2f\n", result);
            }
            break; 
        default: 
            printf("Invalid operator\n");
    }

    return 0;
}
