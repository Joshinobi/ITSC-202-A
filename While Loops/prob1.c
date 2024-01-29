/*
	Author: Joshua C. Gonzales
	Date: Sep 29, 2023
	Description: This program prints a pattern
*/

#include<stdio.h>
#include<stdlib.h>

int main (void)
{	
	int start = 1, row, col, size;
	float crss;
	
	while(start)
	{
		printf("Enter the box size: ");
		scanf(" %d", &size);
		crss = size/2;
		
		if(size %2 && size >= 7)
		{
			for(row = 0; row < size; row++)
			{
				for(col = 0; col < size; col++)
				{
					if(row == 0 || row == crss - 1 || row == crss || row == crss + 1 || row == size - 1)
						printf(" *");
					else if(col == 0 || col == crss - 1 || col == crss || col == crss + 1 || col == size - 1)
						printf(" *");
					else
						printf("  ");
				}
				printf("\n");
			}
			start = 0;
		}
		else
		{
			printf("Your size should be odd number or >= 7. \n");
			printf("\tTry again!!! \n\n");
			break;
		}
	}
	
	return 0;
}
