/*
	Author: Joshua C. Gonzales
	Date: December 6, 2023
	Description: This program creates a hexdump for a chosen file
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

void fun1(FILE *file);
int fun2(FILE *file, int ch);
void fun3(FILE *file);

int print = 0, total = 0; // variable that counts the number of printable ascii characters
int oset = 0; //variable for the offset

int main (void)
{
	int ch, a;
	char input[30];
	int cnt = 0, line = 0;
	
	printf("\033[1;31mFilename of binary to hexdump:\033[0m ");
	scanf("%s", input);
	printf("\n");
	
	__fpurge(stdin);
	// opens file selected by the user
	FILE *file = fopen(input, "r");
	
	// checks to see if the file is accessible
	if(!file)
	{
		fprintf(stderr, "File didn't open correctly\n");
		exit(-1);
	}
	
	fun1(file);
	
	printf("\n===============================================================================================\n");
	printf("| Offset |\t\t\tHexadecimal Data\t\t\t| Character Format |\n");
	printf("===============================================================================================\n");
	
	
	while (1)
	{
		for(line = 0;; line++)
		{
			ch = fun2(file, ch);
			
			if(ch != EOF)
			{
				if(line == 10)
				{
					printf("\t\t\t10 Lines Printed ... Pausing\n");
					printf("\t\t\t   \033[1;31mPRESS ENTER TO CONTINUE\033[0m\n");
					getchar();
					line = 0;
				}
			}
			
			else
			{
				fseek(file, 0, SEEK_SET);
				fun3(file);
				
				return 0;
			}
		}
	}
	
	fclose(file);
	
	return 0;

}

// function that produces the magic number and file type
void fun1(FILE *file)
{
	int b;
	int cnt = 0;
	int ftype[3];
	
	printf("\033[1;31mMagic Number:\033[0m ");
	// prints character as a hexadecimal
	while(cnt < 4 && (b = fgetc(file)) != EOF)
	{
		ftype[cnt] = b;
		printf("\033[0;33m%02X\033[0m", b);
		cnt++;
	}
	cnt = 0;
	
	printf(" \033[1;31mFileType:\033[0m ");
	// checks if the character is printable or not
	for(int count = 0; count < 4; count++)
	{
		if((char)ftype[count] >= ' ' && (char)ftype[count] <= '~') 
			printf("\033[0;33m%c\033[0m", ftype[count]);
		else
			printf("\033[0;33m.\033[0m", ftype[count]);
	}
	
	fseek(file, 0, SEEK_SET);
}

// produces the offset, hexadecimal data, and character format from the file
int fun2(FILE *file, int ch)
{
	int cnt = 0;
	int arr[16];
	
	printf("| %06X |", oset);
	// prints character as a hexadecimal	
	while(cnt < 16 && (ch = fgetc(file)) != EOF)
	{
		arr[cnt] = ch;
		printf(" %02X ", ch);
		cnt++;
		if(cnt == 8)
			printf(" ");
	}
	cnt = 0;
		
	printf("| ");
	// checks if the character is printable or not
	for(int count = 0; count < 16; count++)
	{
		total++;
		if((char)arr[count] >= ' ' && (char)arr[count] <= '~')
		{ 
			printf("%c", arr[count]);
			print++;
		}
		else
		{
			printf(".", arr[count]);
		}
	}
	oset += 16;
	printf(" |\n");		
	
	return ch;	
}

// prints the final output of the program
void fun3(FILE *file)
{
	int a;
	
	printf("\n\033[1;31mMagic Number:\033[0m \033[0;33m0x\033[0m");
				
	for(int count = 0; count < 4 && (a = fgetc(file)) != EOF; count++)
	{
		printf("\033[0;33m%02X\033[0m", a);
	}
				
	printf("\n");
	// determines if the file is a text file
	
	float percent = (float)print / total * 100;
	if(percent >= 75)
		printf("\033[0;34mThis is definitely a text file: >= 75%% ascii\033[0m");
	else if(percent >= 25 && percent < 75)
		printf("\033[0;34mThis file is probably a text file: between 25 and 74%% ascii\033[0m");
	else
		printf("\033[0;34mThis is definitely a binary file: < 25%% ascii\033[0m");
}
