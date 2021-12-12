#include <stdio.h>
#include <stdlib.h>

void non_repeating_element(int *arr,int n){
    int count = 1,j;
    for(int i = 0 ; i < n ; i++){
        for(j = 0 ; j < n ; j++){
            if(*(arr+i) == *(arr+j) && i != j)
                break;
        }if(j == n)
            ++count;
        if(count == 4){
            printf("Third non repeating element is : %d",*(arr+i));
            break;
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int *arr = (int *)malloc(n*sizeof(int));
    for(int i = 0; i < n ; i++)
        scanf("%d",(arr+i));
    non_repeating_element(arr,n);
    
    return 0;
}
