#include <stdio.h>
#include <stdlib.h>

void print_array(int* array, int n)
{
    printf("[");
    int i=0;
    if(n!=0)
    {
        printf("%d", array[i]);
        i++;
        for(; i<n; i++)
        {
            printf(", %d", array[i]);
        }
    }
    printf("]\n");
    return;
}

void quickSortAux(int* array, int i, int j)
{
    if(j-i<2)   
        return;

    
    int pivot=array[i];

    int i_copy=i, j_copy=j, tmp;

    while(j-i>=1)
    {
        if(array[i]<=pivot)
            i++;

        else if(array[j-1]>pivot)
            j--;

        else
        {
            tmp= array[i];
            array[i]=array[j-1];
            array[j-1]=tmp;
            i++;
            j--;
        }
    }

    //I swap the first and the last element of the first sub-array because I know the first element (my pivot) is the biggest 
    tmp=array[i_copy];
    array[i_copy]=array[i-1];
    array[i-1]=tmp;

    //I call the first quicksort un the left sub-array without the last element because it is already in the right position
    quickSortAux(array, i_copy, i-1);
    quickSortAux(array, i, j_copy);
}

void quickSort(int* array, int n)
{
    quickSortAux(array, 0, n);
    return;
}

int main()
{
    int arr[]= {5, 4, 9, 11, 2, 1, 8, 5};
    printf("Solution: [1, 2, 4, 5, 5, 8, 9, 11]\n");
    quickSort(arr, 8);
    printf("Your solution: ");
    print_array(arr, 8);
    return 0;
}