#ifndef _INTEL_HEX_H
#define _INTEL_HEX_H
#include <stdio.h>  //for FILE datatype
#include <stdint.h>
#include <stdlib.h>
struct point {
  int x; 
};


int iHexGetLength(char * line);
int iHexGetAddress(char * line);
int iHexGetCode(char *line);
uint8_t * iHexGetArrayofData(char *line);
int iHexVerifyLine(char * line);
FILE* handler(char *file);
char* getiHexLine(FILE * fileHandler);

uint8_t* swapvalue(uint8_t*hexvaluehigh,uint8_t*hexvaluelow);
struct value function();
#endif // _INTEL_HEX_H
