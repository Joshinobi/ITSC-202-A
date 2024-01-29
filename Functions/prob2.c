/*
	Author: Joshua Gonzales
	Date: November 9, 2023
	Description: This program generates security strings for a security code.
*/

#include "header2.h"

int main()
{
	while(1)
	{
		char validString[10][21] = {"\0"};
		
		srand(time(NULL));
		int len = 0;
		int securityCode = 0;
				
		printf("\033[0;35mEnter the length of the security string: \33[0m");
		scanf(" %d", &len);
		
		//Checks the length of the security string
		if(len >= 12 && len <= 20)
		{
			genString(validString, len, securityCode);
			printStrings(validString, len);
		}
		else
			printf("\t\033[0;31mValue entered should be between 12 and 20 inclusive!!! Try again.\33[0m\n");
	}
	return 0;
}

void genString(char validString[][21], int len, int securityCode)
{
	int code = 0;
	//Checks if the security code entered is within a specified range
	printf("\033[0;35mEnter your security code: \33[0m");
	scanf(" %d", &code);
	if(code > 2999 && code <= 9000)
	{
		char securityStr[21] = {"\0"};
		int cntr = 0;

		for(;;)
		{
			for(int count = 0; count < len; count++)
			{
				//Generates random printable characters from the ASCII table
				securityStr[count] = 32 + (rand() % 94);
				int ordinal = (int)securityStr[count];
				securityCode = convert(count, ordinal, securityCode, len);
			}
			
			if(securityCode == code)
			{
				for(int col = 0; col < len; col++)
				{
					//Stores the security strings that matches the code into the validString array
					validString[cntr][col] = securityStr[col];
				}
						
				cntr++;
				if(cntr > 9)
				{
					break;
				}
			}
			
			securityCode = 0;
		}		
	}
	else
		printf("\t\033[0;31mSecurity code should be 4 digits and between 3000 and 9000.\33[0m\n");	
}

//Converts each security string into a numeric code
int convert(int count,int ordinal, int securityCode, int len)
{
	int tempSum = ordinal * (len - count);
	securityCode = securityCode + tempSum;
	
	return securityCode;
}

//Displays the contents of validString array
void printStrings(char validString[][21], int len)
{		
	int securityCode = 0;

	for(int row = 0; row < 10; row++)
	{
		for(int col = 0; col < len; col++)
		{
			int tempSum = (int)validString[row][col] * (len - col);
			securityCode = securityCode + tempSum;
		}
			
		printf(" \033[0;32mSecurity String:\33[0m %s \033[0;34m--\33[0m \033[0;32mSecurity Code:\33[0m %d\n", validString[row], securityCode);
					
		securityCode = 0;
	}

	exit(0);
}

