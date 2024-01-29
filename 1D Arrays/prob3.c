/*
	Author: Joshua Gonzales
	Date: 10-18-2023
	Description: This program displays the equivalent address and hexadecimal value of an input
*/
#include<stdio.h>

int main (void)
{
	int arr1[6];
	char arr2[6];
	int count;
	
	printf("============================================\n");
	
	//Asks the user for integers
	for(count = 0; count < 6; count++)
	{
		printf("\033[0;32mEnter integer number %d: \33[0m", count+1);
		scanf(" %d", &arr1[count]);
	}
	
	printf("===========================================================\n");
	
	//Asks the user for characters
	printf("\033[0;31mEnter 6 characters separated by space: \33[0m");
	scanf(" %c %c %c %c %c %c", &arr2[0], &arr2[1], &arr2[2], &arr2[3], &arr2[4], &arr2[5]);
	
	printf("===========================================================\n\n");
	printf("\33[0;33m  Element\tAddress\t\tHexadecimal Value\tDecimal Value\33[0m ");
	printf("\n=======================================================================\n");
	
	//Displays integer array details
	for(count = 0; count < 6; count++)
	{
		printf("Integer[%d]\t%p\t\t0x%05x\t\t%d\n", count, &arr1[count], arr1[count], arr1[count]);
	}
	
	printf("=======================================================================\n");
	printf("\33[0;33m  Element\tAddress\t\tHexadecimal Value\tCharacter Value\33[0m ");
	printf("\n=======================================================================\n");
	
	//Displays charater array details
	for(count = 0; count < 6; count++)
	{
		printf("ArrChar[%d]\t%p\t\t0x%05x\t\t%c\n", count, &arr2[count], arr2[count], arr2[count]);
	}
	
	return 0;
}
