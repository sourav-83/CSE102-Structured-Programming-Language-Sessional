#include <stdio.h>
#include <string.h>

int main ()
{


    char str[5*104];
    printf ("Enter the string: ");

   fgets(str, 5*104, stdin);
    size_t length = strlen(str)-1;
    if (length==0) {printf ("0");}
    else {
    int max = 1;
    for (int i=0; i<length; i++)
    {
        for (int j=i+1; j<length; j++)
        {
            int temp = 0;
            for (int k=j-1; k>=i; k--)
            {
                if (str[k]==str[j]) {temp=1; break;}

            }
             if (temp==0) {if (j-i+1>max) {max=j-i+1;} }
             else if (temp==1) {break;}
        }
    }


   printf ("%d", max);
    }

 return 0;

}
