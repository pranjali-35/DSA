/*Program to find second non-repeating element in an array*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    
    int *arr = (int *)malloc(n*(sizeof(int)));
    printf("Enter the array elements : ");
    for(int i = 0 ; i < n ; i ++)
        scanf("%d",(arr+i));
    
    int counter;
    
    for(int i = 0 ; i < n ; i++){
        int count = 0;
        for(int j = 0 ; j < n ; j++){
            if(i != j){
                if((arr+i) == (arr+j))
                    count++;
            }
        }if(count == 0)
            counter++;
        if(counter == 3){
            printf("Second non-repeating element is %d",*(arr+i));
        }
    }

    return 0;
}
