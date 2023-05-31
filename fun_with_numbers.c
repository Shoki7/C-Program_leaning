/*
The provided code is a C program that allows the user to input a number of 2 to 5 digits and perform different operations based on the number's digit count.
Topics Covered are:
Variables, Data types, Operators
Loops, conditionals
*/
#include<stdio.h>
#include<math.h>
int main()
{

    int number, operation;;
    int base, exponent, result;
    int digit1, digit2, digit3, product;
    int firstDigit, lastDigit, sum_2;
    int digit, reversedNumber = 0, sum = 0;
    int newNumber = 0, multiplier = 1;
    printf("Enter a number (2-5 digits):");
    scanf("%d",&number);
    if(number >= 10 && number <= 99)
    {
        base = number / 10;
        exponent = number % 10;
        result = pow(base, exponent);
        printf("%d raised to the power %d is %d\n", base, exponent, result);
    }
    else if(number >= 100 && number <= 999)
    {
        digit1 = number / 100;
        digit2 = (number / 10) % 10;
        digit3 = number % 10;
        product = digit1 * digit2 * digit3;
        printf("The product of the digits is: %d\n", product);
    }
    else if(number >= 1000 && number <= 9999)
    {
        firstDigit = number / 1000;
        lastDigit = number % 10;
        sum_2 = firstDigit + lastDigit;
        printf("The sum of the first and last digits is: %d\n", sum_2);
    }
    else if(number >= 10000 && number <= 99999)
    {
        printf("Choose an operation:\n");
        printf("1. Sum of all digits\n");
        printf("2. Reverse of the number\n");
        printf("3. Add one to each digit and create a new number\n");
        scanf("%d", &operation);
        int tempNumber = number;
        // Calculate sum of all digits
        while (tempNumber != 0)
        {
            digit = tempNumber % 10;
            sum += digit;
            tempNumber /= 10;
        }

       // Reverse the number
        tempNumber = number;
        while (tempNumber != 0)
        {
            digit = tempNumber % 10;
            reversedNumber = reversedNumber * 10 + digit;
            tempNumber /= 10;
        }

        // Add one to each digit and create a new number
        tempNumber = number;
        while (tempNumber != 0)
        {
            digit = tempNumber % 10;
            digit = (digit + 1) % 10;  // Adding 1 and taking the remainder to handle carrying
            newNumber = newNumber + digit * multiplier;
            multiplier *= 10;
            tempNumber /= 10;
        }

        switch (operation)
        {
            case 1:
                printf("Sum of all digits: %d\n", sum);
                break;
            case 2:
                printf("Reversed number: %d\n", reversedNumber);
                break;
            case 3:
                printf("New number with one added to each digit: %d\n", newNumber);
                break;
            default:
                printf("Invalid operation choice.\n");
                break;
        }

    }
    return 0;
}
