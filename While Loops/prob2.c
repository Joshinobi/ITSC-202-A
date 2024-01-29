/*
	Author: Joshua C. Gonzales
	Date: Sep 29, 2023
	Description: This program asks for a user's input then displays the equivalent ascii value
*/

#include<stdio.h>
#include<stdlib.h>

int main (void)
{	
	char val, ans = 'Y';
	
	while(ans)
	{
		printf("\tEnter any printable ascii character: ");
		scanf(" %c", &val);
		printf("\t\tYou entered: %c\n", val);
		printf("\t\tThe ascii value of the character is: %d\n", val);
		printf("\tAgain (Y/N): ");
		scanf(" %c", &ans);
		printf("===================================================\n\n");
		
		if(ans == 'Y' || ans == 'y')
		{
			ans = 'Y';
		}
		else if(ans == 'N' || ans == 'n')
		{
			printf("\n\tQuiting...");
			break;
		}
		else
		{
			printf("\tInvalid input!\n");
			break;
		}
	}
		
	return 0;
}
