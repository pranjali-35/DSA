#include <stdio.h>
#include <stdlib.h>

void reverse(int *arr, int start, int end)
{
    int temp;
    if (start >= end)
        return;
    temp = *(arr+start);  
    *(arr+start) = *(arr+end);
    *(arr+end) = temp;
    reverse(arr, start+1, end-1);  
}    
 
void display(int *arr, int size)
{
    for (int i = 0 ; i < size ; i++)
        printf("%d ", *(arr+i));
 
    printf("\n");
}
 
int main()
{
    int n;
    scanf("%d",&n);
    int *arr = (int *)malloc(n*sizeof(int));
    for(int i = 0 ; i < n ; i++)
        scanf("%d",(arr+i));
    printf("Original array : ");
    display(arr, n);
    reverse(arr, 0, n-1);
    printf("Reversed array : ");
    display(arr, n);
    
    return 0;
}
