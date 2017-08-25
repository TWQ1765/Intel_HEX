#ifndef _INTEL_HEX_H
#define _INTEL_HEX_H
#include <stdio.h>  //for FILE datatype
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>
struct point {
  int x; 
};


uint8_t * iHexToArray(char *line);
int iHexVerifyLine(char * line);
FILE* handler(char *file);
char* getiHexLine( FILE *file_handler);
char* iHexSelectLoad(char *file,int * line_num); 
int recordType(char* line);
uint8_t* iHexGetAddress(int* r_type,char *i_hex_array1,char *i_hex_array2);
int getAddress16bit(uint8_t *i_hex_array);
int getAddress32bit(uint8_t *i_hex_array1,uint8_t *i_hex_array2);
int getAddressStart(uint8_t *i_hex_array);
uint8_t* getOnlyData(uint8_t *i_hex_array);
//try zone______________________________________

//int* iHexSelectLoad(char *file,int * line_num);
//char* iHexLineGet(FILE * file_handler);
//uint8_t* swapvalue(uint8_t*hexvaluehigh,uint8_t*hexvaluelow);swap not needded
//struct value function();

#endif // _INTEL_HEX_H
