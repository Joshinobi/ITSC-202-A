#ifndef _HEADER2_H
#define _HEADER2_H	1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void genString(char validString[][21], int len, int securityCode);

int convert(int count,int ordinal, int securityCode, int len);

void printStrings(char validString[][21], int len);

#endif
