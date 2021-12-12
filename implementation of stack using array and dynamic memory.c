#include<stdio.h>
#include<stdlib.h>

int* push(int *start_ptr, int *top)
{
	int *ptr = NULL;
	if(start_ptr == NULL)
		ptr = (int*)calloc(1,sizeof(int));
	else
		ptr = (int*)realloc(start_ptr,sizeof(int)*((*top)+1));
	if (ptr == NULL)
		printf("Memory unavailable\n");
	else{
		(*top)+=1;
		start_ptr = ptr;
		printf("Enter data : ");
		scanf("%d",&start_ptr[(*top)]);
	}return start_ptr;
}

int* pop(int *start_ptr, int *top)
{	
	int *ptr = NULL;
	if(start_ptr == NULL)
		printf("Stack is empty\n");
	else{	
	    printf("Element poped : %d\n",start_ptr[(*top)]);
		(*top)-=1;
		if((*top) != -1)
			ptr = (int*)realloc(start_ptr,sizeof(int)*(*top));	
		start_ptr = ptr;
	}return start_ptr;
}

void peek(int *start_ptr, int top)
{
	if(start_ptr == NULL)
		printf("Stack is empty\n");
	else
		printf("Element on peek : %d",start_ptr[top]);
}

void display(int *start_ptr, int top)
{
	if(top == -1)
		printf("Stack is empty\n");
	else{
		for(int i = top ; i > -1 ; i--)
			printf("%d ",start_ptr[i]);
		printf("\n");
	}
}

int main()
{
	int top = -1,choice;
	int *stack_ptr = NULL;
	do
	{
		printf("\nEnter ur choice:\n1.Push\n2.Pop\n3.Peek\n4.Display\n0.Exit\n");
		scanf("%d",&choice);
		
		switch(choice){
			case 0:
			    break;
			case 1:
			    stack_ptr = push(stack_ptr,&top);
				break;
			case 2:
			    stack_ptr = pop(stack_ptr,&top);
				break;
			case 3:
			    peek(stack_ptr,top);
				break;
			case 4:
			    display(stack_ptr,top);
				break;
			default:
			    printf("\nInvalid option");
				break;
		}
	}while(choice);
}
