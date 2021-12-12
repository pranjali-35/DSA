#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char item){
    if(top >= SIZE -1){
        printf("Stack overflow\n");
        return;
    }top = top+1;
    stack[top] = item;
}

char pop(){
    char item;
    if(top < 0){
        printf("Stack is empty\n");
        return;
    }item = stack[top];
    top = top-1;
    return item;
}

int isOperator(char item){
    if(item == '^' || item == '+' || item == '-' || item == '*' || item == '/')
        return 1;
    return 0;
}

int precedence(char item){
    if(item == '^')
        return (3);
    else if(item == '*' || item == '/')
        return (2);
    else if(item == '+' || item == '-')
        return (1);
    return (0);
}

void InfixToPostfix(char infix[], char postfix[]){
    int i = 0, j = 0;
    char item, x;
    push('(');
    strcat(infix,")");
    item = infix[i];
    while(item != '\0'){
        if(item == '(')
            push(item);
        else if(isdigit(item) || isalpha(item)){
            postfix[j] = item;
            j++;
        }else if(isOperator(item) == 1){
            x = pop();
            while(isOperator(x) == 1 && precedence(x) >= precedence(item)){
                postfix[j] = x;
                j++;
                x = pop();
            }push(x);
            push(item);
        }else if(item == ')'){
            x = pop();
            while(x != '('){
                postfix[j] = x;
                j++;
                x = pop();
            }
        }else{
            printf("\nInvalid Infix expression\n");
            exit(1);
        }i++;
        item = infix[i];
    }postfix[j] = '\0';
}

int main()
{
    char infix[SIZE],postfix[SIZE];
    printf("Enter infix expression : ");
    gets(infix);
    InfixToPostfix(infix,postfix);
    printf("Postfix expression : ");
    puts(postfix);

    return 0;
}