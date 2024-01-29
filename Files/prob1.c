/*
  Author: Joshua C. Gonzales
  Date: December 3, 2023
  Description: This program takes arguments from the command line.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fun1(int val1, char **val2, char *letters, int *len, int *numlen, char *rfile, char *wfile);
void fun2(FILE *file1, char *word, char *letters, int *len, int wordCnt, int *numlen, FILE *file2);

int main(int val1, char **val2) {
  char letters[11] = "\0";
  char word[30];
  int wordCnt = 0;

  int len;
  int numlen;
  char rfile[30] = "\0"; // read file
  char wfile[30] = "\0"; // write file

  fun1(val1, val2, letters, &len, &numlen, rfile, wfile);

  // opens the read and write file
  FILE *file1 = fopen(rfile, "r");
  FILE *file2 = fopen(wfile, "w");

  // checks to see if the read and write file are accessible
  if (file1 == NULL || file2 == NULL) {
    fprintf(stderr, "Files didn't open correctly\n");
    exit(-1);
  }

  fun2(file1, word, letters, &len, wordCnt, &numlen, file2);

  fclose(file1);
  fclose(file2);

  return 0;
}

// assigns the arguments to a variable
void fun1(int val1, char **val2, char *letters, int *len, int *numlen, char *rfile, char *wfile)
{
  for (int count = 0; count < val1; count++) {
    if (strcmp(val2[count], "--letters") == 0)
    {
      char *ptr = val2[count + 1], *ptr2;
      for (int cnt = 0;; cnt++, ptr = NULL) {
        ptr2 = strtok(ptr, ",");

        if (ptr2 == NULL)
          break;
        letters[cnt] = *ptr2;
      }
    }
    if (strcmp(val2[count], "--len") == 0)
      *len = atoi(val2[count + 1]);
    if (strcmp(val2[count], "-c") == 0)
      *numlen = atoi(val2[count + 1]);
    if (strcmp(val2[count], "-f") == 0)
      strcpy(rfile, val2[count + 1]);
    if (strcmp(val2[count], "--out") == 0)
      strcpy(wfile, val2[count + 1]);
  }
}

// writes the contents in the write file
void fun2(FILE *file1, char *word, char *letters, int *len, int wordCnt, int *numlen, FILE *file2)
{
  while (fscanf(file1, " %29[^\n]s", &word[0]) != EOF) {
    for (int cnt = 0; cnt < sizeof(letters); cnt++) {
      if (word[0] == letters[cnt] && strlen(word) == *len) {
        wordCnt++;
        if (wordCnt > *numlen) {
          break;
        }
        printf("%s\n", word);
        fprintf(file2, "%s\n", word);
      }
    }
  }
}
