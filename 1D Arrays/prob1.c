/*
	Author: Joshua Gonzales
	Date: 10-16-2023
	Description: This program switches user input to title case or toggle case
*/
#include<stdio.h>

int main (void)
{
	char input;
	
	while(1)
	{
		printf("\tPlease choose an option from the menu: ");
		printf("\n\t\t1. Title case");
		printf("\n\t\t2. Toggle case");
		printf("\n\t\t3. Quit");
		printf("\n\tEnter a menu number: ");
		scanf(" %c", &input);
		
		if(input == '1')
		{
				char string[41] = {"\0"};
				int size = sizeof(string);
				
				printf("\tEnter a string max 40 long: ");
				scanf(" %[^\n]s", string);
				
				//Title case function

				for(int count = 0; count < size; count++)
				{
					if((char)string[count] >= 'A' && (char)string[count] <= 'z')
					{
					for(count = 0; string[count] != '\0'; count++) 
						{
							//Checks if first letter is capital then proceeds with the conversion
							if(string[count] == ' ' && (char)string[count + 1] >= 65 && (char)string[count + 1] <= 90)
							{
								for(int cnt2 = count + 2; string[cnt2] != ' ' && string[cnt2] != '\0'; cnt2++)
								{
									if(string[cnt2] >= 65 && string[cnt2] <= 90)
									{
										char letter = (char)string[cnt2] + 32;
										string[cnt2] = letter;
									}
								
									else
									{
									char letter = (char)string[cnt2];
									string[cnt2] = letter;
									}
								}
							}
							
							//Checks if first letter is lowercase then proceeds with the conversion
							else if(string[count] == ' ' && (char)string[count + 1] >= 97 && (char)string[count + 1] <= 122)
							{
								char letter = string[count + 1] - 32;
								string[count + 1] = letter;
								
								for(int cnt2 = count + 2; string[cnt2] != ' ' && string[cnt2] != '\0'; cnt2++)
								{
									if(string[cnt2] >= 65 && string[cnt2] <= 90)
									{
										char letter = (char)string[cnt2] + 32;
										string[cnt2] = letter;
									}
								
									else
									{
									char letter = (char)string[cnt2];
									string[cnt2] = letter;
									}
								}
							}
							
							else if(count == 0 && (char)string[count] >= 65 && (char)string[count] <= 90)
							{
								for(int cnt2 = count + 1; string[cnt2] != ' ' && string[cnt2] != '\0'; cnt2++)
								{
									if(string[cnt2] >= 65 && string[cnt2] <= 90)
									{
										char letter = (char)string[cnt2] + 32;
										string[cnt2] = letter;
									}
								
									else
									{
									char letter = (char)string[cnt2];
									string[cnt2] = letter;
									}
								}
							}
							
							else if(count == 0 && (char)string[count] >= 97 && (char)string[count] <= 122)
							{
								char letter = string[count] - 32;
								string[count] = letter;
								
								for(int cnt2 = count + 1; string[cnt2] != ' ' && string[cnt2] != '\0'; cnt2++)
								{
									if(string[cnt2] >= 65 && string[cnt2] <= 90)
									{
										char letter = (char)string[cnt2] + 32;
										string[cnt2] = letter;
									}
								
									else
									{
									char letter = (char)string[cnt2];
									string[cnt2] = letter;
									}
								}
							}	
						}
						
						printf("\n\tYour converted string: ");
						printf("\n\t\t%s", string);
						printf("\n=======================================================");
						printf("\n");
						break;
					}
					else
					{
						printf("\n********** ONLY INPUT LETTERS **********");
						printf("\n\tTry Again\n");
						break;
					}
				}				
		}
		else if(input == '2')
		{
			char string[41] = {"\0"};
			int size = sizeof(string);
			
			//Toggle case function
				
			printf("\tEnter a string max 40 long: ");
			scanf(" %[^\n]s", string);
			
			for(int count = 0; count < size; count++)
				{
					if((char)string[count] >= 'A' && (char)string[count] <= 'z')  
					{
						for(int count = 0; string[count] != '\0'; count++) 
							{
								if((char)string[count] >= 65 && (char)string[count] <= 90)
								{
									char letter = (char)string[count] + 32;
									string[count] = letter;
								}
								else if((char)string[count] >= 97 && (char)string[count] <= 122)
								{
									char letter = (char)string[count] - 32;
									string[count] = letter;
								}
							}				
						
						printf("\n\tYour converted string: ");
						printf("\n\t\t%s", string);
						printf("\n=======================================================");
						printf("\n");
						break;
					}
					else
					{
						printf("\n********** ONLY INPUT LETTERS **********");
						printf("\n\tTry Again\n");
						break;
					}
				}
		}
		else if(input == '3' || input == 'q' || input == 'Q')
		{
			printf("\n\tQuitting ....");
			break;
		}
		else
		{
			printf("\n******** NO SUCH OPTION IN MENU ********");		
			printf("\n\tTry Again\n");
		}
	}

	return 0;
}
