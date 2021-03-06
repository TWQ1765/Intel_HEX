#include "intel_hex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>

#define M (1024*1024) 

///*//test Hex is right or not. ex.):10000000560E08EC00F0020E020E020E06EF00F094\n
int iHexVerifyLine(char * line)
{
  char *lineptr = line;
  char temp_hex;
  int i =0;
  int sum_hex=0;
  int get_hex= 0;
  int start_symbol = 0;
  
  sscanf(&line[0] , "%c" , &start_symbol);//read simbol ':'
  if (start_symbol != ':')
  { 
    return 0;
  }
  else 
  {    
    while((line[i+1] != '\n'))//read the code until the end of line
    {
      sscanf(&line[i+1], "%2x" , &get_hex);
      i=i+2;
      sum_hex=sum_hex+get_hex;
    }
  }
	return (sum_hex & 0xff) == 0;// check intel Hex checksum
}  
//*/ 

//* //function open file
FILE* handler(char *file)//return as pointer type FILE 'FILE *'
{
  FILE *file_handler;              //pointer fileHandler
  file_handler = fopen(file , "r");
  return file_handler;             // pointer return
}
//*/

///*// fgets() only able to get 1st line*******current
char* getiHexLine( FILE *file_handler)
{
  char *hex_line = (char*)malloc(1024);
  fgets(hex_line, 1024, file_handler);
  return hex_line;
}
//*/
/*
*----------------function call-----------------
*	1.FILE* handler(char *);
*	2.char* getiHexLine( FILE *);
*-----------------------------------------------*/
//*// load selected element from file
char* iHexSelectLoad(char *file, int line_num) // warning*****change char* -> int*
{
  FILE* file_handler = handler(file);
  char *selecte_ihex;// =(char *)malloc(sizeof(char)*buf_size); 
	
    for (int i =0 ; i <= line_num ; i++) //chage line_num to *line_num
    {
      selecte_ihex = getiHexLine(file_handler);
    }
  return selecte_ihex;
}
//*/

/*-------read data start at 4th of array ihex-------------------
 * 	1. check and do only record type == 00 
 * 	2. get the size of the array then know load how many time
 *	3. does uint8_t can store large number?
 *     ans = only can read 32bit of data.
 * 	4. need to put into a string? ans = no put as array
 *  5. seen from the informaion of a intel_hex the 1st set of it 
 *		is the total number of data. Do not wasting time to count it.
 *   
 *--------------------------------------------------------------*/
//*// loading only address.
uint8_t* getOnlyData(uint8_t *i_hex_array) 
{
	int j=0;
	int k=4;
	int total_element = i_hex_array[0];
	
	uint8_t* data = (uint8_t*)malloc(total_element*sizeof(uint8_t));
	for( k ; j < total_element ; k++ )
	{
		data[j] = (i_hex_array[k]);// i already =(i-1) ?ans = no 
		j++;
	}
	return data;
}
//*/

/*/// load all record type from all element ***not use
int8_t* allRecordTypeToMemory(char* line1,char* line2)
{
	int r_type1 = recordType(line1);
	uint8_t* i_hex_array1=iHexToArray(line1);
	uint8_t* i_hex_array2=iHexToArray(line2);
	int8_t* address = iHexGetAddress(r_type1,i_hex_array1,i_hex_array2);
	
	
	return address;
}
*/


/*-----------------------------------------------	
 *	1.
 *	2.	
 *
 *-----------------------------------------------*/ 
//*/// load all data from all element******************WE ARE HERE
ADDRESSDATA  iHexGetAddressAndData(char* line1,char* line2)
{
	ADDRESSDATA addressData;//* addressData
	
	uint8_t *i_hex_array1;
	uint8_t *i_hex_array2;
	
	if (recordType(line1)==4 || recordType(line1) + recordType(line2)==4) //check r_type=4
	{
		i_hex_array1 = iHexToArray(line1);
		i_hex_array2 = iHexToArray(line2);
		addressData.address = iHexGetAddress(4,i_hex_array1,i_hex_array2);
		addressData.data = getOnlyData(i_hex_array2);
	}
	else if (recordType(line1)==0 || recordType(line1) + recordType(line2)== 0) //check r_type=0
	{
		i_hex_array1 = iHexToArray(line1);
		i_hex_array2 = iHexToArray(line2);
		addressData.address = iHexGetAddress(0,i_hex_array1,i_hex_array2);
		addressData.data = getOnlyData(i_hex_array1);
	}
	else //r_type = 5
	{
		i_hex_array1 = iHexToArray(line1);
		i_hex_array2 = iHexToArray(line2);
		addressData.data= 0;
		addressData.address = iHexGetAddress(5,i_hex_array1,i_hex_array2);
	}
	return addressData;
}
//*/


/*-------Shifting-(<<)-in Hexdecimal------------------
 * hexdecimal   ~     binary
 *   0x0F0F     =   0000111100001111
 *___result__________________________start Shifting (0x0F0F<<4)
 *   0x0F0F0	=   00001111000011110000
 *---------------------------------------------------*/
///*// get address 16bit 
int  getAddress16bit(uint8_t *i_hex_array)
 {
	uint8_t upper_address[]={0x00000000};
	printf("Hex_array[1] = %x",i_hex_array[2]<<8); 
	int address = upper_address[0] + (i_hex_array[1]<<8) + i_hex_array[2];
	return address;  
 } 
//*/

///*// get address 32bit 
int  getAddress32bit(uint8_t *i_hex_array1,uint8_t *i_hex_array2)
 {
	int  address = (i_hex_array1[4]<<24) + (i_hex_array1[5]<<16) + \
				(i_hex_array2[1]<<8) + i_hex_array2[2];
  int test_address = (i_hex_array1[5]<<16) + (i_hex_array2[2]<<0);
  printf("test_address = %x\n",test_address); //test Shifting only
  return address;  
 } 
//*/

//*//get start linear Address for record type = 05
int  getAddressStart(uint8_t *i_hex_array)
{
	int  startAddress = (i_hex_array[4]<<24)+ (i_hex_array[5]<<16) + \
					   (i_hex_array[6]<<8) + (i_hex_array[7]);
	return startAddress;
}
//*/
    
//*//Record type
int recordType(char* line)
{
  uint8_t* i_hex_array=iHexToArray(line);
  int r_type = i_hex_array[3];
  return r_type;
}  
//*/


///*//read as 0xXX (8byte) element from file
uint8_t* iHexToArray(char *line)
{
  int length = 0;
  char temp;
  uint8_t *result;
  
  while(1)
  {
    sscanf(&line[length+1], "%2c", &temp);
    if(line[length+1] != '\n') 	//change line[length+1] to...(char*)line[length+1]
    { 
      length = length + 2;		//find total length
    }
    else
    {
      result = malloc(length/2);
      break;
    }
  }
  
  for(int i=0;i<length;i+=2)
  {
    sscanf(&line [i+1], "%2x", &result[i/2]);
  }
  return result;
}
//*/

/*------------------------------------------------------------
*  record type         detail                
*      00       Data
*      01       End Of File
*      02       Extended Segment Address ( ignored )
*      03       Start Segment Address (For 80x86 processors,ignored)
*      04       Extended Linear Address
*      05       Start Linear Address 
*---------------------------------------------------------------
*----------------function call-----------------
*	1.int getAddress16bit(uint8_t *) 
*	2.int getAddress32bit(uint8_t *,uint8_t *)
*	3.int getAddressStart(uint8_t *)
*-----------------------------------------------*/
//*//try iHexGetAddress*****************function r_type()
int iHexGetAddress(int r_type,uint8_t *i_hex_array1,uint8_t *i_hex_array2)
{
  int address;
	switch(r_type)
	{
		case 0://record type = 0
			address = getAddress16bit(i_hex_array1);
			break;
		case 1://record type = 01
			address = -1;	//returning the last address memory
			break;
		case 4://record type = 04
			address = getAddress32bit(i_hex_array1,i_hex_array2);
			break; 	
		case 5://record type = 05
			address = getAddressStart(i_hex_array1);
			break; 		
		default:            
			address = -1;//returning the last address memory
			break;
	}
  return address;
}  
//*/
void IHexInterpret_test(char* i_hex_line , char* memory)
{
	memory[M];
	int r_type = recordType(i_hex_line); 
	uint8_t* i_hex_array = iHexToArray(i_hex_line);
	uint8_t* data = getOnlyData(i_hex_array);
	int address = getAddress16bit(i_hex_array);
	for (int i=0 ; i<i_hex_line[0] ; i++)
	{
		memory[address+i]=data[i];
	}
	
}

//need iHexVerifyLine() to verify i_hex 1st
void IHexInterpret(char* i_hex_line1 , char* i_hex_line2, char* memory)
{
	memory[M];
	int r_type1 = recordType(i_hex_line1);
	int r_type2 = recordType(i_hex_line2);
	
	uint8_t* i_hex_array1 = iHexToArray(i_hex_line1);
	uint8_t* i_hex_array2 = iHexToArray(i_hex_line2);
	
	uint8_t* data;
	int address;
	if (r_type1==4 || (r_type2+r_type1 == 4))
	{	
		data = getOnlyData(i_hex_array2);
		address = iHexGetAddress(r_type1,i_hex_array1,i_hex_array2);
		for (int i=0 ; i<i_hex_line2[0] ; i++)
		{
			memory[address+i]=data[i];
		}
	}
	else if(r_type1==0 || (r_type2+r_type1 == 0))
	{
		data = getOnlyData(i_hex_array1);
		address = iHexGetAddress(r_type1,i_hex_array1,i_hex_array2);
		for (int i=0 ; i<i_hex_line1[0] ; i++)
		{
			memory[address+i]=data[i];
		}
	}
	else
	{
		address = iHexGetAddress(r_type1,i_hex_array1,i_hex_array2);
	}
	
}

 //main 
 void iHexLoadToMemory(char* file_name , char* memory)
 {
	 
	 char *i_hex_line0 = iHexSelectLoad(file_name,0);
	 char *i_hex_line1 = iHexSelectLoad(file_name,1);
	 memory[M];
	 int i = 0;
	 while(iHexVerifyLine(i_hex_line0))
	 {
		char *i_hex_line0 = iHexSelectLoad(file_name,i);
		char *i_hex_line1 = iHexSelectLoad(file_name,i+1);
		i++;
		IHexInterpret(i_hex_line0 ,  i_hex_line1, memory);
	 } 
	 
 }