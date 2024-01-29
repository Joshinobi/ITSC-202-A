/*
  Author: Joshua C. Gonzales
  Date: December 4, 2023
  Description: This program parses the contents of the numbers.txt file
*/

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	double num;
	int cnt1 = 0, cnt2 = 0;
	int numcnt = 0, belowcnt = 0, abovecnt = 0;
	
	FILE *numfile = fopen("numbers.txt", "r");
	FILE *above = fopen("above60.txt", "w");
	FILE *below = fopen("below60.txt", "w");
	
	if(!numfile || !above || !below)
	{
		fprintf(stderr, "Files didn't open correctly\n");
		exit(-1);
	}
	
	// extracts the decimal numbers from the file
	while(fscanf(numfile, "%*[^:]:%lf", &num) == 1) // "%*[^:]:%lf" - ignores characters before ':'
	{
		// checks if the decimal number is less than or equal to 60.00
		if(num <= 60.00)
		{
			fprintf(below, "%.2f ", num);
			numcnt++;
			belowcnt++;
			cnt1++;
			
			if(cnt1 == 10)
			{
				fprintf(below, "\n");
				cnt1 = 0;
			}
		}
		
		// checks if the decimal number is greater than 60.00
		else if(num > 60.00)
		{
			fprintf(above, "%.2f ", num);
			numcnt++;
			abovecnt++;
			cnt2++;
			
			if(cnt2 == 10)
			{
				fprintf(above, "\n");
				cnt2 = 0;
			}
		}
	}
	
	// prints the how much numbers are in each of the files
	printf("\tnumbers.txt contains: %d numbers\n", numcnt);
	printf("\tabove60.txt contains: %d numbers\n", abovecnt);
	printf("\tbelow60.txt contains: %d numbers", belowcnt);
	
	fclose(numfile);
	fclose(above);
	fclose(below);
	
	return 0;
}
