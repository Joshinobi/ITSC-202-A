/*
	Author: Joshua Gonzales
	Date: 10-21-2023
	Description: This program converts binary to decimal and hexadecimal
*/
#include<stdio.h>
#include<string.h>

int main (void)
{
	printf("===========================================\n");
	while(1)
	{
		char bits[8] = {"\0"};	
		
		printf("Enter an 8 bit binary number: ");
		scanf(" %s", bits);
		
		int bitSize = strlen(bits);
		
		//Determines if the binary has 8 digits 		
		if(bitSize == 8)
		{
		
			//Checks to see if binary is equal to 1 or 0
			for(int count = 7; count >= 0; count--)
			{
				if(bits[count] !=  '0' && bits[count] != '1')
				{
					int bitCount = count + 1;
					printf("  >>>> Bit: %d is not binary digit ----> Quitting Program <<<<\n", bitCount);
					printf("===========================================");
					return 0;
				}
			}
					
			char hexVal[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
			char bits3[4] = {"\0"};
			char bits4[4] = {"\0"};
			
			int hex1;
			int hex2;
			
			int decVal = 0, dec2 = 0, dec3 = 128;
			
			//Converts binary to decimal
			
			for(int count = 0; count < 9; count++)
			{
				if(bits[count] == '1')
				{
					decVal = dec2 + dec3;
					dec2 = decVal;
					dec3 = dec3/2;
				}
				else if(bits[count] == '0')
				{
					dec3 = dec3/2;
				}
				else if(bits[count] == '1' && count == 8)
					dec3 = 1;
			}	
			
			bits3[0] = bits[0];
			bits3[1] = bits[1];
			bits3[2] = bits[2];
			bits3[3] = bits[3];
			
			bits4[0] = bits[4];
			bits4[1] = bits[5];
			bits4[2] = bits[6];
			bits4[3] = bits[7];
	
			dec2 = 0;
			dec3 = 8;
			
			//Converts decimal to hexadecimal
			
			for(int count = 0; count < 4; count++)
			{
				if(bits3[count] == '1')
				{
					hex1 = dec2 + dec3;
					dec2 = hex1;
					dec3 = dec3/2;
				}
				else if(bits3[count] == '0')
				{
					dec3 = dec3/2;
				}
				else if(bits3[count] == '1' && count == 3)
					dec3 = 1;
			}
			
			dec2 = 0;
			dec3 = 8;
			
			for(int count = 0; count < 4; count++)
			{
				if(bits4[count] == '1')
				{
					hex2 = dec2 + dec3;
					dec2 = hex2;
					dec3 = dec3/2;
				}
				else if(bits4[count] == '0')
				{
					dec3 = dec3/2;
				}
				else if(bits4[count] == '1' && count == 3)
					dec3 = 1;
			}		
			
			printf("  >>>> Decimal equivalent: %d -> Hex: 0x%c%c <<<<\n", decVal, hexVal[hex1], hexVal[hex2]);
					
			//Determines if there are even or odd numbers of 1's
			int oneCount = 0;
			
			for(int count = 0; count < 9; count++)
			{
				if(bits[count] == '1')
					oneCount++;		
			}
			
			if(oneCount %2)
			{
				printf("  >>>> odd number of 1's <<<<\n\n");		
			}
			else if(oneCount == 0)
			{
				printf("  >>>> No ones entered <<<<\n\n");		
			}
			else
			{
				printf("  >>>> even number of 1's <<<<\n\n");	
			}
			
			//Asks if the user would like to enter a binary number again
			
			char input;
			
			printf("Would you like to try again? ");
			scanf(" %c", &input);
			
			if(input == 'y' || input == 'Y')
				printf("===========================================\n");
			else if(input == 'n' || input == 'N')
			{
				printf("Quitting\n");
				printf("===========================================\n");
				return 0;
			}
			else
				printf("Invalid input!\n");
		}
		else
		{
			printf("You didn't enter the correct number of digits\n");
			printf("Quitting\n");
			printf("===========================================");
			break;
		}
	}
			
	return 0;
}
