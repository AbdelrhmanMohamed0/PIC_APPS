#include <stdio.h>

#define GET_BIT(VAR, BIT_NUMBER) (((VAR) >> (BIT_NUMBER)) & 1)

#define SUM_ARRAY(arr, size)       \
    int sum = 0;                   \
    for (int i = 0; i < size; i++) \
        sum += arr[i];             \
    printf("sum of array equal %d \n", sum);

int count_number_of_ones(int num);
unsigned char reverse_binary(unsigned char num);

int main(void)
{

    int x = 5;
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int num1;
    unsigned char num2 = 13;

    printf("bit value is %d \n", GET_BIT(x, 2));

    SUM_ARRAY(array, 10);

    printf("please enter number \n");
    scanf("%d", &num1);
    printf("number of ones in number %d is %d \n", num1, count_number_of_ones(num1));

    num2 = reverse_binary(num2);
    printf("reversed binary is ");
    for (int i = 7; i >= 0; i--)
        printf("%d", GET_BIT(num2, i));

    return 0;
}

int count_number_of_ones(int num)
{
    int count = 0;
    for (int i = 0; i < 32; i++)
        if (1 & (num >> i))
            count++;
    return count;
}

unsigned char reverse_binary(unsigned char num)
{
    unsigned char reversed = 0;
    unsigned char mask = 1;
    for (int i = 0; i < 8; i++)
    {
        unsigned char bit = GET_BIT(num, i);
        reversed |= bit << (7 - i);
    }
    return reversed;
}
