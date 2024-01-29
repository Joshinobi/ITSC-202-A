/*
	Author: Joshua Gonzales
	Date: 10-18-2023
	Description: This program counts the number of aplhabets, numbers, and symbols in a string
*/
#include<stdio.h>

int main (void)
{
	char string[41];
	int symCount = 0;
	int numCount = 0;
	int alphaCount = 0;
				
	printf("Enter string <= 40 long: ");
	scanf(" %[^\n]s", string);
	
	for(int count = 0; string[count] != '\0'; count++)
	{
		if((char)string[count] >= '0' && (char)string[count] <= '9')
			numCount++;
			
		else if((char)string[count] >= 'A' && (char)string[count] <= 'Z')
			alphaCount++;
		
		else if((char)string[count] >= 'a' && (char)string[count] <= 'z')
			alphaCount++;
		
		else if((char)string[count] >= ' ' && (char)string[count] <= '/')
			symCount++;
		
		else if((char)string[count] >= ':' && (char)string[count] <= '?')
			symCount++;
			
		else if((char)string[count] >= '[' && (char)string[count] <= '_')
			symCount++;
			
		else if((char)string[count] >= '{' && (char)string[count] <= '~')
			symCount++;
	}
	
	printf("Your string contained: ");
	printf("\n\t %d numerical digits", numCount);
	printf("\n\t %d symbols", symCount);
	printf("\n\t %d alphabet characters", alphaCount);
	
	return 0;
}

