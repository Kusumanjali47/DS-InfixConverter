#include <stdio.h>
#include <stdlib.h>
#include <infix.h>


/*Main program*/
int main()
{
	int option;

	char ch;

	char infix[100];

	char postfix[100];

	do
	{
		//read the option
		printf("Enter the option : \n\t1.Infix_Postfix Conversion\n\t2.Evaluation\nChoose : ");
		scanf("%d", &option);

		switch (option)
		{
			case 1:

				//read the expression
				printf("Enter the Expression : \n");

				scanf("\n%[^\n]", infix);

				//invoking the function call to convert infix to prefix
				infix_postfix_conversion(infix, postfix);

				break;

			case 2:

				printf("The evaluated value is : ");

				//invoke the function call to evaluate the value
				infix_postfix_evaluation(postfix);

				break;

			default :

				//print the message
				printf("check option : \n");

				break;

		}

		/*Read the option to continue.....*/
		printf("Do you want to continue(y/n) :");

		scanf("\n%c", &ch);

	} while (ch == 'y');

	return 0;
}
