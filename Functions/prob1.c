/*
	Author: Joshua Gonzales
	Date: November 6, 2023
	Description: This program checks to determine if entered strings are palindromes.
*/

#include "header1.h"

int main (void)
{
	char string[COUNT][31] = {{"\0"}};
	int maxLen = 0;
	int success;
	
	//Asks the use to enter strings
	for(int count = 0; count < COUNT; count++)
	{
		printf("\tEnter string %d: ", count + 1);
		scanf(" %[^\n]s", string[count]); 
	}
	printf("============================================================\n\n");
	
	maxLen = getStrings(string);
	
	success = isPalindrome(string);
	
	printf("============================================================\n");
	printf("\n\tNumber of Palindromes found: %d\n", success);	
	printf("\tThe length of the longest string is: %d", maxLen);
	
	exit(0);
}

//Counts the length of the longest string
int getStrings(char string[COUNT][31])
{
	int maxLen = 0;
	
	for(int count = 0; count < COUNT; count++)
	{
		int curLen = strlen(string[count]);
		
		if(curLen > maxLen)
		{
			maxLen = curLen;
		}
	}
	
	return maxLen;
}

//Returns the number of palindromes in the entered strings
int isPalindrome(char string[COUNT][31])
{
	int checkPal = 0;
	int countPal = 0;
	
	for(int count = 0; count < COUNT; count++)
	{
		checkPal = reverseStr(string[count]);
		
		if(checkPal == 1)
		{
			countPal++;
			printf("\tReversed string %d: %s\t (Palindrome)\n", count + 1, string[count]);
		}
		else
			printf("\tReversed string %d: %s\t (Not a Palindrome)\n", count + 1, string[count]);
	}
	
	return countPal;
}

//Reverses each string and checks if it is a string is a palindrome
int reverseStr(char str[])
{
	int first1 = 0;
	int last1 = strlen(str) - 1;
	
	while(first1 < last1)
	{	
		char temp = str[first1];
		str[first1] = str[last1];
		str[last1] = temp;
		first1++;
		last1--;
	}
	
	int first2 = 0;
	int last2 = strlen(str) - 1;
	
	if(str[first2] == str[last2])
		return 1;
	return 0;
}
