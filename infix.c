#include <stdio.h>
#include <string.h>
#include <stack.h>

/*function for to set the flags*/
int set_flag(char ch)
{
	/*check if the ch is open  and closed brackets*/
	if (ch == '(' || ch == ')')

		/*if it is true,return 0*/
		return 0;

	/*check if the ch is + AND -*/
	else if (ch == '+' || ch == '-')

		/*if it is true, return 1*/
		return 1;

	/*check if the ch is / and * */
	else if (ch == '*' || ch == '/')

		/*if it is true, return 2*/
		return 2;
}

/*function for infix to  postfix conversion*/
void infix_postfix_conversion(char *infix, char *postfix)
{
	char stack[100];

	int stack_size = 100, i_index, j_index = 0, top = 0, s_flag, i_flag, stop = 0;

	char s_peak, ch, oper;

	//for loop to run upto infix ch is not equal to null character
	for (i_index = 0; infix[i_index] != '\0'; i_index++)
	{
		//check if the char is in between 0 and 9 or not
		if (infix[i_index] >= '0' && infix[i_index] <= '9')
		{
			//if it is true then storing the ch to the another ch array, and incrementing it
			postfix[j_index++] = infix[i_index];
		}
		else
		{
			//check if the ch is space or not
			if (postfix[j_index - 1] != ' ')
			{
				//if the postfix char array is not having space,then adding one space
				postfix[j_index++] = ' ';
			}

			//check if the ch is open bracket
			if (infix[i_index] == '(')

				//push bracket into stack
				c_push(stack, stack_size, &top, infix[i_index]);

			//check if ch is closed bracket
			else if (infix[i_index] == ')')
			{
				//run upto ch is equl to open bracket
				while ((ch = c_pop(stack, &top)) != '(')

					//incrementing the char array value, storing the popped operator
					postfix[j_index++] = ch;
			}
			else
			{
				//check if top is 0 or not
				if (top == 0)

					//push operator into stack
					c_push(stack, stack_size, &top, infix[i_index]);

				else
				{
					//set the flag for inserting operator
					i_flag = set_flag(infix[i_index]);
					
					while (1)
					{
						//invoking the function call peak to extract the top valuue of the stack
						s_peak = c_peak(stack, top);
						
						//set the flag for operator stored in the stack
						s_flag = set_flag(s_peak);

						//compare if the s_flag is less than i_flag
						if (s_flag < i_flag)
						{
							//push the operator into stack if the operator has higher precedence than the alredy present in the stack
							c_push(stack, stack_size, &top, infix[i_index]);
							
							break;
						}
						else
						{
							//storing the popped operator
							oper = c_pop(stack, &top);

							//check if oper is null or not
							if (oper == '\0')
							{
								//push the null char into stack
								c_push(stack, stack_size, &top, infix[i_index]);

								//set the flag
								stop = 1;
							}
							else
							{
								//store the popped char into the postfix char array and incrementing
								postfix[j_index++] = oper;

								//clear the flag
								stop = 0;
							}
							
							//check if the flag is non zero or not
							if (stop)
								//if it is true then break
								break;
						}
					}
				}
			}
		}
	}
	/*pop the remaining the operator*/
	while ((ch = c_pop(stack, &top)) != '\0')

		//storing the popped ch into postfix char array
		postfix[j_index++] = ch;

	//terminating with the null character
	postfix[j_index] = '\0';

	//printing the expression
	printf("%s\n", postfix);

}

//function for evaluation
void infix_postfix_evaluation(char *postfix)
{
	int stack[100];

	char buffer[50];

	int value_1, value_2, number, i_index = 0, j_index = 0, result, top = 0, size = 50;

	//check upto null
	while (postfix[i_index] != '\0')
	{
		j_index = 0;

		//check if the ch is in between 0 and 9
		while (postfix[i_index] != '\0' && postfix[i_index] != ' ' && postfix[i_index] >= '0' && postfix[i_index] <= '9')
		{
			buffer[j_index++] = postfix[i_index];

			i_index++;
		}

		buffer[j_index] = '\0';

		//check if the j_index is not equal to 0
		if (j_index != 0)
		{
			sscanf(buffer, "%d", &number);

			push(stack, size, &top, number);
		}

		//check upto null
		if (postfix[i_index] != '\0' && postfix[i_index] != ' ')
		{
			//pop 2 values
			value_1 = pop(stack,&top);

			value_2 = pop(stack,&top);

			//case statement for arithmetic
			switch (postfix[i_index])
			{
				case '+':

					//addition
					result = value_1 + value_2;

					push(stack, size, &top, result);

					break;

				case '-':

					//substraction
					result = value_2 - value_1;
					
					push(stack, size, &top, result);

					break;

				case '*':

					//multiplication
					result = value_1 * value_2;

					push(stack, size, &top, result);

					break;

				case '/':

					//division
					result = value_2 / value_1;

					push(stack, size, &top, result);

					break;
			}
		}
		if (postfix[i_index] != '\0')
			i_index++;
	}
	printf("%d\n", pop(stack, &top));
}

/*function for to reverse the expression*/
void reverse_expression(char *str)
{
	int len = 0;
	int i_index, temp = 0;

	/*compute the length of the string*/
	len = strlen(str);

	/*for loop to count the characters */
	for (i_index = 0; i_index < (len / 2); i_index++)
	{
		/*swapping the character*/
		temp = str[i_index];
		str[i_index] = str[(len - 1) - i_index];
		str[(len - 1) - i_index] = temp;
	}
}

/*Function for infix to prefix conversion*/
void infix_prefix_conversion(char *infix, char *prefix)
{
	char stack[100];

	int stack_size = 100, i_index, j_index = 0, top = 0, s_flag, i_flag, stop = 0;

	char s_peak, ch, oper;
	
	/*invoking the function call to reverse the expression*/
	reverse_expression(infix);

	for (i_index = 0; infix[i_index] != '\0'; i_index++)
	{
		//check if the char is in between 0 and 9
		if (infix[i_index] >= '0' && infix[i_index] <= '9')
		{
			prefix[j_index++] = infix[i_index];
		}
		else
		{
			//check if the ch is space
			if (prefix[j_index - 1] != ' ')
			{
				prefix[j_index++] = ' ';
			}

			//check if the ch is (
			if (infix[i_index] == ')')

				//push into stack
				c_push(stack, stack_size, &top, infix[i_index]);


			//check if ch is )
			else if (infix[i_index] == '(')
			{
				//run upto ch is nt equal to (
				while ((ch = c_pop(stack, &top)) != ')')

					prefix[j_index++] = ch;
			}

			else
			{
				//check if top is 0 or not
				if (top == 0)

					//push into stack
					c_push(stack, stack_size, &top, infix[i_index]);

				else
				{
					//set the flag
					i_flag = set_flag(infix[i_index]);
					
					while (1)
					{
						s_peak = c_peak(stack, top);
						
						//set the flag
						s_flag = set_flag(s_peak);

						//compare s_flag and i_flag
						if (s_flag <= i_flag)
						{
							//push into stack
							c_push(stack, stack_size, &top, infix[i_index]);
							
							break;
						}
						else
						{
							oper = c_pop(stack, &top);

							//check if oper is null or not
							if (oper == '\0')
							{
								//push into stack
								c_push(stack, stack_size, &top, infix[i_index]);

								stop = 1;
							}
							else
							{
								prefix[j_index++] = oper;

								stop = 0;
							}
							
							if (stop)
								break;
						}

					}
				}
			}
		}
	}
	
	while ((ch = c_pop(stack, &top)) != '\0')

		prefix[j_index++] = ch;

	prefix[j_index] = '\0';

	/*invoking the function call to reverse the expression*/
	reverse_expression(prefix);
	
	/*printing the expression*/
	printf("%s\n", prefix);
}

/*function for prefix evaluation*/
void infix_prefix_evaluation(char *prefix)
{
	int stack[100];

	char buffer[50];

	int value_1, value_2, number, i_index = strlen(prefix), j_index = 0, result, top = 0, size = 50;

	//check upto null
	while (i_index >= 0)
	{
		j_index = 0;

		//check if the ch is in between 0 and 9
		while (i_index >= 0 && prefix[i_index] != ' ' && prefix[i_index] >= '0' && prefix[i_index] <= '9')
		{
			buffer[j_index++] = prefix[i_index];

			i_index--;
		}

		buffer[j_index] = '\0';

		/*invoking the function call to reverse the expression*/
		reverse_expression(buffer);
		
		//check if the j_index is not equal to 0
		if (j_index != 0)
		{
			sscanf(buffer, "%d", &number);

			push(stack, size, &top, number);
		}

		//check if the index is greater and equal to 0 or not
		if (i_index >= 0 && prefix[i_index] != ' ')
		{
			//pop 2 values
			value_1 = pop(stack,&top);

			value_2 = pop(stack,&top);

			//case statement for arithmetic
			switch (prefix[i_index])
			{
				case '+':

					//addition
					result = value_1 + value_2;

					push(stack, size, &top, result);

					break;

				case '-':

					//substraction
					result = value_1 - value_2;
					
					push(stack, size, &top, result);

					break;

				case '*':

					//multiplication
					result = value_1 * value_2;

					push(stack, size, &top, result);

					break;

				case '/':

					//division
					result = value_1 / value_2;

					push(stack, size, &top, result);

					break;
			}
		}
		if (i_index >= 0)
			i_index--;
	}
	printf("%d\n", pop(stack, &top));
}

