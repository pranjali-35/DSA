#include <stdio.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
char postfix[SIZE];
int top = -1;

int isOperator(char item){
    if(item == '^' || item == '+' || item == '-' || item == '*' || item == '/')
        return 1;
    return 0;
}

void push(int item){
    if(top == SIZE-1){
        printf("Stack overflow\n");
        return;
    }top++;
    stack[top] = item-'0';
}

void evaluate(char item){
    int a, b, ans;
    a = stack[top];
    top--;
    b = stack[top];
    top--;
    
    switch(item){
        case '+':
            ans = b+a;
            break;
        case '-':
            ans = b-a;
            break;
        case '*':
            ans = b*a;
            break;
        case '/':
            ans = b/a;
            break;
        case '^':
            ans = b^a;
            break;
        default :
            ans = 0;
    }top++;
    stack[top] = ans;
}

int main()
{
    int i,item;
    printf("Enter the postfix expression : ");
    gets(postfix);
    int len_postfix = strlen(postfix);
    for(i = 0 ; i < len_postfix ; i++){
        item = postfix[i];
        if(item >= '0' && item <= '9'){
            push(item);
        }else if(isOperator(item) == 1){
            evaluate(postfix[i]);
        }
    }printf("Result : %d\n",stack[top]);

    return 0;
}
