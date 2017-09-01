#ifndef _INTEL_HEX_H
#define _INTEL_HEX_H
#include <stdio.h>  //for FILE datatype
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>

typedef struct ADDRESSDATA ADDRESSDATA;
struct ADDRESSDATA{
    int address;
    uint8_t * data;
};

uint8_t * iHexToArray(char *line);
int iHexVerifyLine(char *line);
FILE* handler(char *file);
char* getiHexLine( FILE *file_handler);
char* iHexSelectLoad(char *file,int line_num); 
int recordType(char* line);
int iHexGetAddress(int r_type,uint8_t *i_hex_array1,uint8_t *i_hex_array2);
int getAddress16bit(uint8_t *i_hex_array);
int getAddress32bit(uint8_t *i_hex_array1,uint8_t *i_hex_array2);
int getAddressStart(uint8_t *i_hex_array);
uint8_t* getOnlyData(uint8_t *i_hex_array);


ADDRESSDATA  iHexGetAddressAndData(char* line1,char* line2);
void IHexInterpret(char* i_hex_line1 , char* i_hex_line2, char* memory);
void IHexInterpret_test(char* i_hex_line , char* memory);
#endif // _INTEL_HEX_H
