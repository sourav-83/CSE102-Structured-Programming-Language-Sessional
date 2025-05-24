#include <stdio.h>
#include <stdlib.h>

int numberoftokens=0;
char **strTokenize(char *str, char delim)
{
    int  length=0;
    while(1)
    {

        length++;
        if (*(str+length)==0) {break;}
    }

    int i=0,current=0;
    //printf ("length=%d\n",length);
    while (i<length)
    {
        if (*(str+i)==delim && current!=0) {numberoftokens++; current=0;}
        else if (*(str+i)!=delim) {current++;}
        if (i==length-1 && current!=0) {numberoftokens++;}
        i++;
    }


    //printf("numberoftokens=%d\n", numberoftokens);

    int *sizeoftokens = (int*) malloc (numberoftokens*sizeof(int));

     i=0;
     current=0;
     int k=0;
    while (i<length)
    {
        if (*(str+i)==delim && current!=0) {*(sizeoftokens+k)=current; k++; current=0;}
        else if (*(str+i)!=delim) {current++;}
        if (i==length-1 && current!=0) {*(sizeoftokens+k)=current;}
        i++;
    }

    int z=0;
   // while ( *(sizeoftokens+z)) {printf("%d\n",*(sizeoftokens+z)); z++;}



    char **matrix= (char**) malloc (numberoftokens*sizeof(char *));
    for (int i=0; i<numberoftokens; i++)
    {
        *(matrix+i)=(char*) malloc (((*(sizeoftokens+i))+1)*sizeof(char));
    }


     int j=0;
     int starting=0;
    for (j=0; j<length; j++)
    {

    if (*(str+j)!=delim) {starting = j; break;}

    }

    //printf("starting=%d\n", starting);

    j=0, k=0;
   for (int i=starting; i<length; i++)
   {
    if (*(str+i)!=delim)  {*(*(matrix+j)+k)=*(str+i); k++;}
    else if(*(str+i-1)!=delim) {*(*(matrix+j)+k)=0; k=0; j++;}

    }

    *(*(matrix+numberoftokens-1)+ *(sizeoftokens+numberoftokens-1))=0;


 free(sizeoftokens);

return matrix;

}
void _printTokens(char **tokens)
{

     printf ("The tokens are:\n");

   for (int i=0;i<numberoftokens ;i++)
   {
       for (int j=0; ;j++)
       {


            printf ("%c",(*(*(tokens+i)+j)));

              if ((*(*(tokens+i)+j))==0) { break;}


       }
       printf ("\n");



      // printf ("%s\n",(*(tokens+i)) );



   }

}
void _printTokensUnique(char **tokens)
{
    printf ("The unique tokens are:\n");

   for (int i=0;i<numberoftokens ;i++)
   {

      int temp=0, temp2=0;
      for (int j=0; j<i; j++)
      {   temp=0;
          int k=0;
          while ((*(*(tokens+i)+k )) || (*(*(tokens+j)+k) ) )
          {
             if ((*(*(tokens+i)+k )) != (*(*(tokens+j)+k) ) ) {temp=1; break;}

             k++;
          }

          if (temp==0) {temp2=1;}
      }

         if (temp2!=1 || i==0)
         {

               for (int j=0; ;j++)
       {
           if ((*(*(tokens+i)+j))==0) {break;}

            printf ("%c",(*(*(tokens+i)+j)));
       }
       printf ("\n");





         }

      temp2=0;

   }
}
void _freeTokens(char **tokens)
{


   for (int i=0; i<numberoftokens;i++)
   {


       free (*(tokens+i));

   }


 free(tokens);



}

int main(char **args)
{
    int string_length;
    scanf("%d", &string_length);

    char delim;
    scanf(" %c", &delim);

    char *str = (char *)malloc(sizeof(char) * (string_length + 1));
    scanf("%s", str);


    char **tokens = strTokenize(str, delim);
    _printTokens(tokens);
    _printTokensUnique(tokens);
    _freeTokens(tokens);
    return 0;
}
