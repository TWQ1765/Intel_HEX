#ifndef _INTEL_HEX_H
#define _INTEL_HEX_H

struct point {
  int x; 
};

int iHexGetLength(char * line);
 
int iHexGetAddress(char * line);
int iHexGetCode(char *line);
int iHexGetArrayOfData(char * line , char *buffer);
int iHexVerifyLine(char * line);




#endif // _INTEL_HEX_H
