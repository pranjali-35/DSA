#include <stdio.h>

void toh(int n, char source, char dest, char aux){
    if(n == 1){
        printf("Move disc %d from %c to %c\n",n,source,dest);
        return;
    }toh(n-1, source, aux, dest);
    printf("Move disc %d from %c to %c\n",n,source, dest);
    toh(n-1,aux,dest,source);
}

int main()
{
    int n;
    printf("Enter number of discs : ");
    scanf("%d",&n);
    
    toh(n,'A','C','B');

    return 0;
}
