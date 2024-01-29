/*
	Author: Joshua C. Gonzales
	Date: October 2, 2023
	Description: This program takes 5 float numbers and 5 integer numbers 
*/

#include<stdio.h>

int main (void)
{	
	float flt1, flt2, flt3, flt4, flt5;
	float check_float, floats_sum, floats_mean, int_mean, int_sum;
	
	int int1, int2, int3, int4, int5;
	int check_int;
	
	int start = 1;
	
	while(start)
	{
		printf("\tEnter a float: ");
		scanf(" %f", &flt1);
		
		check_int = flt1;
		
		if(check_int != flt1)
		{
			start = 0;
		}
		else if(check_int == flt1)
		{
			printf("\tNot a float!\n");
			return 0;
		}
	}
	
	start = 1;

	while(start)
	{
		printf("\tEnter a float: ");
		scanf(" %f", &flt2);
		
		check_int = flt2;
		
		if(check_int != flt2)
		{
			start = 0;
		}
		else if(check_int == flt2)
		{
			printf("\tNot a float!\n");
			return 0;
		}
	}
	
	start = 1;
	
	while(start)
	{
		printf("\tEnter a float: ");
		scanf(" %f", &flt3);
		
		check_int = flt3;
		
		if(check_int != flt3)
		{
			start = 0;
		}
		else if(check_int == flt3)
		{
			printf("\tNot a float!\n");
			return 0;
		}
	}
	
	start = 1;
	
	while(start)
	{
		printf("\tEnter a float: ");
		scanf(" %f", &flt4);
		
		check_int = flt4;
		
		if(check_int != flt4)
		{
			start = 0;
		}
		else if(check_int == flt4)
		{
			printf("\tNot a float!\n");
			return 0;
		}
	}
	
	start = 1;
	
	while(start)
	{
		printf("\tEnter a float: ");
		scanf(" %f", &flt5);
		
		check_int = flt5;
		
		if(check_int != flt5)
		{
			start = 0;
		}
		else if(check_int == flt5)
		{
			printf("\tNot a float!\n");
			return 0;
		}
	}
	
	floats_sum = flt1 + flt2 + flt3 + flt4 + flt5;
	floats_mean = (flt1 + flt2 + flt3 + flt4 + flt5)/5;
	
	printf("\t\tThe sum is: %.2f\n", floats_sum);
	printf("\t\tThe average is: %.2f\n", floats_mean);
	
	while(1)
	{
		if(floats_sum >= 45.5)
		{
			printf("\t\tThe sum is greater than 45.5\n\n");
			break;
		}
		else
		{
			printf("\t\tThe sum is less than 45.5\n\n");
			break;
		}
	}
		
	start = 1;
	
	printf("\tEnter five integers; space separated: ");
	scanf(" %d %d %d %d %d", &int1, &int2, &int3, &int4, &int5);
	
	int_sum = int1 + int2 + int3 + int4 + int5;
	int_mean = int_sum/5;
	
	int sum = int_sum;
	
	printf("\t\tThe sum is: %d\n", sum);
	printf("\t\tThe average is: %.2f\n", int_mean);
	
	while(1)
	{
		if(sum %2 == 0)
		{
			printf("\t\tThe sum is even\n");
			break;
		}
		else
		{
			printf("\t\tThe sum is odd\n");
			break;
		}
	}
	
	return 0;
}
