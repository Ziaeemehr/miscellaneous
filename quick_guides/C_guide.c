//How to dynamically allocate a 2D array in C?


1) Using a single pointer:

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int r = 3, c = 4;
    int *arr = (int *)malloc(r * c * sizeof(int));
    int i, j, count = 0;
    for (i = 0; i <  r; i++)
      for (j = 0; j < c; j++)
         *(arr + i*c + j) = ++count;
      
    for (i = 0; i <  r; i++)
      for (j = 0; j < c; j++)
         printf("%d ", *(arr + i*c + j));
   /* Code for further processing and free the 
      dynamically allocated memory */
   return 0;
}

2) Using an array of pointers

int main()
{
    int r = 3, c = 4, i, j, count; 
    int *arr[r];
    for (i=0; i<r; i++)
         arr[i] = (int *)malloc(c * sizeof(int));
    // Note that arr[i][j] is same as *(*(arr+i)+j)
    count = 0;
    for (i = 0; i <  r; i++)
      for (j = 0; j < c; j++)
         arr[i][j] = ++count; // Or *(*(arr+i)+j) = ++count
 
    for (i = 0; i <  r; i++)
      for (j = 0; j < c; j++)
         printf("%d ", arr[i][j]);
   return 0;
}

3) Using pointer to a pointer
int main()
{
    int r = 3, c = 4, i, j, count;
    int **arr = (int **)malloc(r * sizeof(int *));
    for (i=0; i<r; i++)
         arr[i] = (int *)malloc(c * sizeof(int));
    // Note that arr[i][j] is same as *(*(arr+i)+j)
    count = 0;
    for (i = 0; i <  r; i++)
      for (j = 0; j < c; j++)
         arr[i][j] = ++count;  // OR *(*(arr+i)+j) = ++count
 
    for (i = 0; i <  r; i++)
      for (j = 0; j < c; j++)
         printf("%d ", arr[i][j]);
    return 0;
}

4) Using double pointer and one malloc call for all rows

int main()
{
    int r=3, c=4;
    int **arr;
    int count = 0,i,j;

    arr  = (int **)malloc(sizeof(int *) * r);
    arr[0] = (int *)malloc(sizeof(int) * c * r);
 
    for(i = 0; i < r; i++)
        arr[i] = (*arr + c * i);
  
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            arr[i][j] = ++count;  // OR *(*(arr+i)+j) = ++count
  
    for (i = 0; i <  r; i++)
        for (j = 0; j < c; j++)
            printf("%d ", arr[i][j]);
    return 0;
}

  