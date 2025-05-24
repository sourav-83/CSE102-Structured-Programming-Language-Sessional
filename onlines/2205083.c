#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

char str[1000];
fgets(str,1000,stdin);
int length = strlen(str);
char largest [1000];

int max = 0; int current=0;

for (int i=0; i<length; i++)
{
    if (str[i]!=' ' && str[i]!='.') {current++;
    if (current>max) {
            for (int j=0; j<current; j++) {
                largest[j]=str[i-current+1+j];
            }
            largest[current]=0;
        max=current;


    }



    }
    else {current=0;}
}

printf ("The largest word is '%s'", largest);

    return 0;
}
