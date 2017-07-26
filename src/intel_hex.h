#ifndef _INTEL_HEX_H
#define _INTEL_HEX_H
#include <stdio.h>  //for FILE datatype
struct point {
  int x; 
};


int iHexGetLength(char * line);
int iHexGetAddress(char * line);
int iHexGetCode(char *line);
int iHexGetArrayOfData(char * line , char *buffer);
int iHexVerifyLine(char * line);
FILE* handler(char *file);
char* getiHexLine(FILE * fileHandler);


#endif // _INTEL_HEX_H
