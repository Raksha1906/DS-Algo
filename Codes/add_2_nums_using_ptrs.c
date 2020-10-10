#include<stdio.h>
int main()
{
    int a,b,*a1,*b1,sum;
    printf("enter first number: ");
    scanf("%d",&a);
    printf("enter second number: ");
    scanf("%d",&b);
    a1= &a;
    b1 = &b;
    sum = *a1+*b1;
    printf("sum of two numbers is: %d",sum);
    return 0;
}
