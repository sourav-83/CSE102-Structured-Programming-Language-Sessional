#include<stdio.h>
#include<stdlib.h>

int** create_array(int row, int col)
{
    int ** matrix = (int **) malloc(sizeof(int*)*row);
    for (int i=0;i<row;i++)
    {
        *(matrix+i)= (int *) malloc(sizeof(int)*col);
    }
    for (int i=0;i<row; i++)
    {
        for (int j=0;j<col;j++)
        {
            scanf("%d",  ((*(matrix+i))+j) );
        }
    }

    return matrix;

}

void printMatrix(int **arr, int row, int col)
{



 for (int i=0;i<row; i++)
    {
        for (int j=0;j<col;j++)
        {
            printf("%d ",  *((*(arr+i))+j) );
        }
        printf ("\n");
    }





}

int ** rotate(int **arr, int row, int col)
{


 for (int i=0;i<row; i++)
    {
        for (int j=0;j<col;j++)
        {
            if (i!=j )
            {
               int temp =   (*((*(arr+i))+j) );
           (*((*(arr+i))+j) ) = (*((*(arr+j))+i) );
           (*((*(arr+j))+i) ) = (*((*(arr+i))+j) );



            }


        }


    }



    for (int i=0;i<col/2; i++)
    {
        for (int j=0;j<row;j++)
        {
           int temp =   (*((*(arr+j))+i) );
           (*((*(arr+j))+i) ) = (*((*(arr+i))+j) );
           (*((*(arr+i))+j) ) = temp;


        }
    }

  return arr;  }






void freematrix (int ** arr, int row, int col)
{
    for (int i=0;i<row; i++)
    {
        free (*(arr+i));
    }

    free (arr);
}


int main()
{
    int row, col;
    scanf("%d %d",&row, &col);
    printf("Taking matrix input from user:\n");
    int **arr = create_array(row,col);
    printf("Printing the matrix:\n");
    printMatrix(arr,row,col);
    arr= rotate(arr,row,col);
        printf("After rotating the matrix\n");
        printMatrix(arr,row,col);

      freematrix(arr,row,col);

}

/*4 3
1 2 3
2 5 4
3 1 1
4 9 2

5 3
2 3 1
5 4 2
1 1 5
9 2 3
3 5 4

2 4
2 1 3 1
5 2 4 5
*/
