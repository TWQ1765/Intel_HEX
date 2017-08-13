#include "intel_hex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>
//#define SWAP(a, b) do { typeof(a) temp = a; a = b; b = temp; } while (0)//swap function


///*//test Hex is right or not. :10000000560E08EC00F0020E020E020E06EF00F094
int iHexVerifyLine(char * line)
{
  char *lineptr = line;
  char temp_hex;
  int i =0;
  int test=0;
  int sum_hex=0;
  int get_hex= 0x123;
  int start_simbol = 0;
  
  sscanf(&line[0] , "%c" , &start_simbol);//read simbol ':'
  if (start_simbol != 0x3a)//if 1st are not start with ':' return test=0
  { 
    return test = 0;
  }
  else 
  {    
    while(line[i+1] != NULL)//read the code until the end of line
    {
      sscanf(&line[i+1], "%2c" , &temp_hex);
      sscanf(&line[i+1], "%2x" , &get_hex);
      i=i+2;
      sum_hex=sum_hex+get_hex;
      test = ((sum_hex & 0xff)<=0);//check value of test should = 1
    }
  }
 return test;
}  
//*/ 

///* //function open file
FILE* handler(char *file)//return as pointer type FILE 'FILE *'
{
  FILE *file_handler;              //pointer fileHandler
  
  file_handler = fopen(file , "r");
 
  return file_handler;             // pointer return
}
///*/

//*// fgets() only able to get 1st line
char* getiHexLine(FILE * file_handler)
{
  char hex_line[1028];
  return fgets(hex_line,1028, file_handler);
}
//*/

//*// fgets()2 read all element in the file
char* iHexLineGet(FILE * file) //:04001000230E1200A9\n
{ 
  int i,j;
  int buf_size = 1000; 
  char *str[10];
  char **i_hex[i];
  int sample[10000];
  int *i_hex_mem = (int *)malloc(sizeof(int)*buf_size); /*Stored in heap segment*/
  FILE *fptr = fopen(file,"r");
  if (fptr)
  {
      i_hex[i] = malloc(buf_size);
	 // i_hex_mem[j] = malloc(buf_size);
	  
      while (fgets(i_hex[i], buf_size , fptr))
      {
        i++;
        i_hex[i] = malloc(buf_size);
      }
	   i_hex[i] = malloc(10*sizeof(char));
      
     // printf("the 3rd line - %s",i_hex[2]);
	   printf("ihex - %s",*i_hex);
	  printf("Number of elements :%d\n", strlen(i_hex[1]));
	  printf("No-----------All elemennt in file--------------------\n");
      for( j=0 ; j<i ; j++)
      {
		//sscanf(i_hex[j] , "%s" , *sample);  
        printf("%d - %s",j,&*i_hex[j]);
		//*(i_hex_mem+j) = i_hex[j];
		//memcpy(i_hex[j],&sample ,sizeof sample);
      }
	  printf("-------------End of file elemennt--------------------\n");
	  //sscanf(i_hex[1] , "%s" , *sample);
	  printf("Number of elements :%d\n", sizeof(i_hex[j]));
	  printf("Number of elements :%d\n", sizeof(i_hex));
	 // printf("Number of elements :%d\n", strlen(i_hex_mem[1]));
	  //printf("i_hex_mem :%d\n", *i_hex_mem[2]);
	  //printf("i_hex_mem %d\n", &i_hex_mem[2]);
	  printf("sample %s\n", *sample);
	///*
      for(int x=0 ; x<i ; x++)
      {
		//free(i_hex_mem[x]);  
        free(i_hex[x]);
        
        fclose(fptr);
        return i_hex[2]; // only return one array?
      }
	//*/
  }
}

//*/

//*//try fseek();
   
//*/


///*// get address 16bit 
 int getAddress16bit(uint8_t *i_hex_array)
 {
  int address = (i_hex_array[1]<<1) + i_hex_array[2];
  
  return address;  
 } 
//*/

///*// get address 32bit 
 int getAddress32bit(uint8_t *i_hex_array1,uint8_t *i_hex_array2)
 {
  int address = (i_hex_array1[9]<<8) + i_hex_array1[10] + (i_hex_array2[1]<<8) + i_hex_array2[2];
  
  return address;  
 } 
//*/
    
//*//Record type****************
int recordType(char* line)
{
 // uint8_t* iHexGetArrayofData();
  uint8_t* array_data=iHexGetArrayofData(line);
  int r_type = array_data[3];
  return r_type;
}  
//*/

/*//read byte from file
uint8_t read_byte_from_file(FILE * file, uint8_t * char_to_put, int * total_chars_read)
{
	//Holds combined nibbles.
	uint8_t hexValue;
	//Get first nibble.
	*char_to_put = fgetc (file);
	clear_special_char(file, char_to_put, total_chars_read);
	//Put first nibble in.
	hexValue = (Ascii2Hex(*char_to_put));
	//Slide the nibble.
	hexValue = ((hexValue << 4) & 0xF0);
	//Put second nibble in.
	*char_to_put = fgetc (file);
	clear_special_char(file, char_to_put, total_chars_read);
	//Put the nibbles together.
	hexValue |= (Ascii2Hex(*char_to_put));
	//Return the byte.
	*total_chars_read += 2;

	return hexValue;
}

*/

///*//read as 0xXX (8byte) element from file
uint8_t* iHexGetArrayofData(char *line)
{
  int length = 0;
  char temp;
  uint8_t *result;
  
  while(1){
    sscanf(&line[length+1], "%2c", &temp);
    
    if(line[length+1] != NULL){
      length = length + 2;
    }
    else{
      result = malloc(length/2);
      break;
    }
  }
  for(int i=0;i<length;i+=2){
    sscanf(&line [i+1], "%2x", &result[i/2]);
  }
  return result;
  
}
//*/


  /*------------------------------------------------------------
   *  record type         mean                
   *      00       Data
   *      01       End Of File
   *      02       Extended Segment Address ( ignored )
   *      03       Start Segment Address (For 80x86 processors,ignored)
   *      04       Extended Linear Address
   *      05       Start Linear Address ( ignored )
   *---------------------------------------------------------------*/
/*//try iHexGetAddress*****************function r_type()
int iHexGetAddress(char * line)
{
  uint8_t* array_data[]=iHexGetArrayofData(line);
  int r_type = recordType(line); // get return 
  
  switch(r_type)
  {
    case 0:
      uint8_t* address = &array_data[4];
      break;
    case 1:
      uint8_t* address = NULL;
      break;
    case 4:
     uint8_t* address = &array_data[4];
     break; 
       
  }
 
  return address;
}  
*/

/**__TRY_ZONE_(can be ignore)_______________________________________________________________________*/

/*//try1
int hex_file_line_count(FILE * file_to_count)
{
	int line_count = 0;
	char got_char;

	while(got_char != EOF)
	{
		got_char = fgetc(file_to_count);
		if (got_char == ':'){line_count++;}
	}
	rewind(file_to_count);
	return line_count;
}

char*readLine(File* fileHandler)
*/
/*//try2

   char ch;
   char str[100];
   printf("Enter any character \n");
   scanf("%c", &ch);
   printf("Entered character is %c \n", ch);
   printf("Enter any string ( upto 100 character ) \n");
   scanf("%s", &str);
   printf("Entered string is %s \n", str);

*/ 
/*//try3 
int main()
{
    int v;
    if (scanf("%d", &v) == 1) {
        printf("OK\n");
    } else {
        printf("Not an integer.\n");
    }
    return 0;
}
*/
/*//remember tyr4 grom trying scanf ()
int main(){
  int x;
  scanf("%d" , &x);
  printf("This is a test value must be int : %d\n" , x);
}
*/
/*//try memcpy();
   char * ihex[] = malloc();
*/
/*/try read all element at file 
int readAll(char *file)
{
    
    for(int i = 0; s[i] != '\0'; ++i);
    for(int j = 0: )

    printf("Length of string: %d", i);
    
    return i;
}  
//*/
/* //swap value  test value:  0x20                0x98       //not needed
uint8_t* swapvalue(uint8_t* hexvaluehigh,uint8_t* hexvaluelow)//return as pointer type FILE 'FILE *'
{
 
  //hexvalue.hexvaluehigh;        //a
  //hexvalue.hexvaluelow;         //b
  
  SWAP(hexvaluehigh,hexvaluelow); //defined
                                  //printed:         0x98        0x20
  printf("hexvaluehigh = %x , hexvaluelow = %x",hexvaluehigh,hexvaluelow);
  return hexvaluehigh;//*return one value
}
*/

/* //real allocate high byte & low byte format************not needed
uint8_t* realdata(char *data)//return as pointer type FILE 'FILE *'
{
  uint8_t* hexvalue[];
  uint8_t* hexvaluehigh;  //a
  uint8_t* hexvaluelow;   //b
  hexvalue[]  =iHexGetArrayofData(data);
  for(int i=4 ; i< ; i+=2)
  {
    sscanf(&hexvalue [i+1], "%2x", &hexvaluehigh[i/2]);
    
  }
}
*/
