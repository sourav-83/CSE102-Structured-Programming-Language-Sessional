#include <stdio.h>

int main ()
{
    int num1,num2;
    char sign;
    scanf ("%d %c %d", &num1, &sign, &num2);

    if (sign!='+' && sign!='-' && sign!='*' && sign!='/') {printf("Error");}
    else if (num2==0 && sign=='/') {printf("Error");}
    else if (sign=='+') {printf("%d", num1+num2);}
    else if (sign=='-') {printf("%d", num1-num2);}
    else if (sign=='*') {printf("%d", num1*num2);}
    else if (sign=='/') {

            float ans =  (float) num1 / num2;

            printf("%f", ans);

                        }





}
