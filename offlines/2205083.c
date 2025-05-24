#include <stdio.h>


int main ()
{
    int n;
    scanf ("%d", &n);
    for (int i=1; i<=n; i++)
    {
        printf ("Case %d\n", i);
        unsigned int k;
        scanf ("%u", &k);
        unsigned int querycopy = k;
        int queryonecount = 0;


        int rem = 0;
        int places = 1;

        while (querycopy)
        {
            rem=querycopy%2;
            querycopy=querycopy/2;
            if (rem==1) {queryonecount++;}
            places=places*10;

        }



        unsigned int max,min, maxdif, mindif;
        int m;
        scanf("%d", &m);
        for (int i=1; i<=m; i++)
        {
        unsigned int onecount=0;
        unsigned int candidate;
        scanf ("%u", &candidate);
        unsigned int candidatecopy = candidate;
        int bin = 0;
        int remainder = 0;
        int place = 1;
        int steps = 0;
        while (candidate)
        {
            remainder=candidate%2;
            candidate=candidate/2;
            bin=bin+(remainder*place);
            if (remainder==1) {onecount++;}
            place=place*10;
            steps++;
        }

        if (i==1) {max=candidatecopy; min=candidatecopy;
        if (onecount>=queryonecount) {maxdif=onecount-queryonecount;}
          else {maxdif=queryonecount-onecount;}
          if (onecount>=queryonecount) {mindif=onecount-queryonecount;}
          else {mindif=queryonecount-onecount;}   }

        else {

          unsigned int dif;
          if (onecount>=queryonecount) {dif=onecount-queryonecount;}
          else {dif=queryonecount-onecount;}


          if (dif<mindif) {mindif=dif; min=candidatecopy;}
          else if (dif== mindif && candidatecopy<min) {mindif=dif; min=candidatecopy;}
          if (dif>maxdif ) {maxdif=dif; max=candidatecopy;}
          else if (dif== maxdif && candidatecopy>max) {maxdif=dif; max=candidatecopy;}

        }

       for (int k= steps; k<32; k++) {printf("0");}
       printf ("%u\n", bin);

        }


        int bin = 0;
        int remainder = 0;
        int place = 1;
        int steps = 0;
        while (k)
        {
            remainder=k%2;
            k=k/2;
            bin=bin+(remainder*place);
            place=place*10;
            steps++;
        }
         for (int l= steps; l<32; l++) {printf("0");}
         printf ("%u\n", bin);
         printf ("Number with Minimum Difference: %u\n", min);
         printf ("Number with Maximum Difference: %u\n", max);

    }

        return 0;
}
