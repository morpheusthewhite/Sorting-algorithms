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

void Merge(int* array, int i, int j, int k, int *temp_array)
{
    
    int j_copy=j, k_copy=k, i_copy=i, written=0;

    //merging phase
    while(i!=j_copy && j!=k_copy)
    {
        if(array[i]<array[j])
        {
            temp_array[i_copy+ written] = array[i];
            i++;
        }
        else
        {
            temp_array[i_copy+ written] = array[j];
            j++;
        }
        written++;
    }
    while(i!=j_copy)
    {
        temp_array[i_copy+written]= array[i];
        i++;
        written++;
    }
    while(j!=k_copy)
    {
        temp_array[i_copy+written]= array[j];
        j++;
        written++;
    }
    
    //moving from the temp array to the original one
    for(;written>0; written--)
        array[i_copy+written-1]=temp_array[i_copy+written-1];
    return;
}

void mergeSort_aux(int* array, int i, int j, int* temp_array)
{
    if(j-i==1)return;
    else
    {
        int k= (j + i) / 2;
        mergeSort_aux(array, i, k, temp_array);
        mergeSort_aux(array, k, j, temp_array);
        
        Merge(array, i, k, j, temp_array);
    }
    return;
}

void mergeSort_recursive(int* array, int n)
{
    int* temp_array= malloc(sizeof(int)*n);
    mergeSort_aux(array, 0, n, temp_array);
    free(temp_array);
    return;
}

int min(int x, int y)
{
    if (x < y)  return x;
    return y;
}

void mergeSort_iterative(int* array, int n)
{
    int size=1, end, first_array_position=0, second_array_position=1;
    int* temp_array= malloc(sizeof(int)* n);
    while(size!= n)
    {
        //end is the min (to avoid out of bound)
        end=min(second_array_position+size, n);

        Merge(array, first_array_position, second_array_position, end, temp_array);
        first_array_position=end;
        if(end+size>=n)
        {
            size++;
            first_array_position=0;
            second_array_position= min (first_array_position + size, n);
        }
        else
        {
            second_array_position=min (end + size, n);
        }
    }
    return;
}

int main()
{
    int arr[]= {5, 4, 9, 11, 2, 1, 8};
    printf("Solution: [1, 2, 4, 5, 8, 9, 11]\n");
    mergeSort_iterative(arr, 7);
    printf("Your solution: ");
    print_array(arr, 7);
    return 0;
}