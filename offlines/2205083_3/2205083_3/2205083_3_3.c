#include <stdio.h>
#include <string.h>

int main ()
{
    char s[20], p[20];
    printf ("Enter the string 's' : ");
    scanf ("%s", &s);
    printf ("Enter the string 'p' : ");
    scanf ("%s", &p);

    int flag = 0;
    size_t length  = strlen(s);
    size_t length2  = strlen(p);

    int temp=0;
    int starindex; int dotindex,dotstarindex,starindex4,dotindex4;
    for (int i=0; i<length2; i++)
    {
        if (i<length2-1 && p[i]=='.' && p[i+1]=='*') {temp=1;dotindex=i; dotstarindex=i+1;}
        if (p[i]=='*' && p[i-1] !='.') {if (i!=length2-1 && p[i+1]=='.') {;}temp=2; starindex=i;}
        if (i<length2-1 && p[i]=='.' && p[i+1]!='*' ) {if (i!=0 && p[i-1]=='*') {;}else  {temp=3;} }
        if (i<length2-1 && p[i]=='*' && p[i+1]=='.') {temp=4;starindex4=i;dotindex4=i+1;}
    }

    int temp5var1=0, temp5var2=0, temp5dotindex, temp5starindex;

    for (int i=0; i<length2; i++)
    {
      if (p[i]=='.') {temp5var1=1; temp5dotindex=i;}
      else if (p[i]=='*') {temp5var2=1; temp5starindex=i;}
    }

    if (temp!=1 && temp!=4 && temp5var1==1 && temp5var2==1) {temp=5;}







   if (temp==0 && length2>length && (length2-length)/2>0) {

        printf("false");

   }
   else if (temp==3)
    {
        if (length2!=length) {printf("false");}
        else {

            for (int i=0; i<length2; i++)
                {
                    if (p[i]=='.')

                        {p[i]=s[i];}

                }

            int flag=0;

            for (int i=0; i<length; i++)
            {
                if (s[i]!=p[i]) {flag=1; break;}
            }

            if (flag==0) {printf ("true");}
            else {printf ("false");}
        }

    }

    else if (temp==0)
    {

         if (length2!=length) {printf("false");}
         else{



            int flag=0;

            for (int i=0; i<length; i++)
            {
                if (s[i]!=p[i]) {flag=1; break;}
            }

            if (flag==0) {printf ("true");}
            else {printf ("false");}




         }



    }


    else if (temp==2)
    {

        if (length2>length) {


               int flag=0;
        for (int i=0; i<starindex-1; i++) {if(s[i]!=p[i]) {flag=1; break;}   }

        for (int i=starindex+1; i<length2; i++) {if (p[i]!=s[i-2]) {flag=1; break;}    }


              if (flag==1) {  printf("false");}
              else {printf("true");}

               }
        else if (length2==length)
        {
            for (int i=0; i<length2; i++)
            {
                if (p[i]=='*') {p[i]=p[i-1];}
            }


            int flag=0;

            for (int i=0; i<length; i++)
            {
                if (s[i]!=p[i]) {flag=1;  break;}
            }

            if (flag==0) {printf ("true");}
            else {printf ("false");}



        }

        else {


            int diff=length-length2;

             int x=1; int starindexcopy=starindex; char temp=p[starindex-1];
             for (int k=length2-1;k>starindex; k--)
        {
            p[length-x]=p[k]; x++;
        }




            for (int k=0; k<=diff; k++)
            {
                p[starindexcopy+k]=temp; starindex++;
            }


          int flag=0;

            for (int i=0; i<length; i++)
            {
                if (s[i]!=p[i]) {flag=1; break;}
            }

            if (flag==0) {printf ("true");}
            else {printf ("false");}


        }


    }


    else if (temp==1)
    {

        int flag=0;

            for (int i=0; i<dotindex; i++)
            {
                if (s[i]!=p[i]) {flag=1; break;}
            }



            int lastremaining=length2-dotstarindex-1;
            for (int i=0; i<lastremaining; i++)
            {
                if (s[length-i-1]!=p[length2-i-1]) {flag=1; break;}
            }




            if (flag==0) {printf ("true");}
            else {printf ("false");}





    }

    else if (temp==4)
    {
        p[dotindex4]=s[length-(length2-dotindex4)];



               int flag=0;
        for (int i=0; i<starindex4-1; i++) {if(s[i]!=p[i]) {flag=1; break;}   }

        for (int i=starindex4+1; i<length2; i++) {if (p[i]!=s[i-2]) {flag=1; break;}    }


              if (flag==1) {  printf("false");}
              else {printf("true");}




    }

     else if (temp==5)
     {


               int flag=0;
        for (int i=0; i<temp5starindex-1; i++) {if(s[i]!=p[i] && p[i]!='.') {flag=1; break;}   }

        for (int i=temp5starindex+1; i<length2; i++) {if (p[i]!=s[i-2] && p[i]!='.') {flag=1; break;}    }


              if (flag==1) {  printf("false");}
              else {printf("true");}





     }


            return 0;


}
