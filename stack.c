#include <stdio.h>
#include <stdlib.h>
#include <stack.h>

/*Function for to push the data into the stack*/
void c_push(char *array, int size, int *top, char ch)
{
		/*store the data in the stack*/
		array[(*top)++] = ch;
}


/*Function for to pop the data from the stack*/
char c_pop(char *array,int *top)
{
	/*check if the stack is empty or not*/
	if (*top == 0)

		return '\0';

	else
		
		/*return the address*/
		return array[--(*top)];
}

/*Function for to print the top value of the stack*/
char c_peak(char *array, int top)
{
	/*check if the stack is empty or not*/
	if(top == 0)

		return '\0';

	else
		
		return array[--top];
}


/*Function for to check the stack is full or not*/
int is_full(int size, int top)
{
	/*check if the top is equal to size or not*/
	if (top == size)
	{
		/*if it is true return 1*/
		return 1;
	}
	else
	{
		/*if it is false return 0*/
		return 0;
	}
}


/*Function for to check the stack is empty or not*/
int is_empty(int top)
{
	/*check if the top is equal to 0 or not*/
	if (top == 0)
	{
		/*if it is true return 1*/
		return 1;
	}
	else
	{
		/*if it is false return 0*/
		return 0;
	}
}


/*Function for to push the data into the stack*/
void push(int *array, int size, int *top, int value)
{
	/*check if the stack is full or not*/
	if (is_full(size, *top))

		printf("Stack is full\n");

	else

		/*store the data in the stack*/
		array[(*top)++] = value;
}


/*Function for to pop the data from the stack*/
int pop(int *array,int *top)
{
	/*check if the stack is empty or not*/
	if (is_empty(*top))

		return 0;

	else

		/*return the address*/
		return array[--(*top)];

}

