#include "intel_hex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>
//#define SWAP(a, b) do { typeof(a) temp = a; a = b; b = temp; } while (0)//swap function


///*//test Hex is right or not. :10000000560E08EC00F0020E020E020E06EF00F094\n
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
	return (sum_hex & 0xff) == 0;
}  
//*/ 

/* //function open file---------try Exception
FILE* handler(char *file)//return as pointer type FILE 'FILE *'
{
  		
  FILE *file_handler;              //pointer fileHandler
  file_handler = fopen(file , "r");
  if(file_handler = NULL)
  {
	  throwException("File dose not exit, do you mean %s",file);
  }
  return file_handler;             //pointer return
}
*/

//* //function open file-------the main code
FILE* handler(char *file)//return as pointer type FILE 'FILE *'
{
  FILE *file_handler;              //pointer fileHandler
  file_handler = fopen(file , "r");
  //fclose(file);
  return file_handler;             // pointer return
}
//*/

///*// fgets() only able to get 1st line*************current
char* getiHexLine( FILE *file_handler)
{
  char *hex_line = (char*)malloc(1024);
  fgets(hex_line, 1024, file_handler);
  //if (fgets(hex_line, 44, file_handler) != '\n')
  //{
	  //int i=+1;
	 // printf("hex_line = %s",hex_line);
	 // puts(hex_line);
  //}
  //fclose(file_handler);
  
  return hex_line;
}
//*/

/*// fgets() only able to get 1st line*********prev
char* getiHexLine( FILE *file_handler)
{
  char hex_line[1028];
  return fgets(hex_line,1028, file_handler);
}
*/

//*// load selected element from file*************************************
char* iHexSelectLoad(char *file,int  *line_num)
{
  char* file_handler = handler(file);
 // char *hex_line = getiHexLine(file_handler);
  int buf_size = 100; 
  char *select_data;// =(char *)malloc(sizeof(char)*buf_size); 
	
    for (int i =0 ; i <= line_num ; i++) //chage line_num to *line_num
    {
      select_data = getiHexLine(file_handler);
    }
    
  return select_data;
}
//*/

//*// load all element from file*************************************
char* iHexLoadHexFileToMemory(char *file)
{
  int line_num1=0;
  int line_num2=1;
  int check_line,null_line;
  int r_type;
  char temp=NULL;
  //int num = 0;
 
  char* data_array2 = iHexSelectLoad(file, line_num2);	
  char* data_array1	= iHexSelectLoad(file, line_num1);
 // while(data_array1!=NULL || data_array2!=NULL)
//  {
		null_line= (&data_array1>=0);
		printf("null_line = %d \n",null_line);
		printf("xxxxxxxx = %d \n",temp );
		check_line = (iHexVerifyLine(data_array1))&&(iHexVerifyLine(data_array2));
		printf("check_line = %d \n",check_line);
	  
  //}
  r_type = recordType(data_array1);
  printf("r_type = %d\n",r_type);
  
  r_type = recordType(data_array2);
  printf("r_type = %d\n",r_type);
  
  printf("%d = %s",line_num1, data_array1);
  printf("data_array1 = %s",data_array1);	//see and look and prove:......
  printf("data_array2 = %s",data_array2); 	//data_array1 == data_array2
  
  //check_line = iHexVerifyLine(data_array1); // why check_line should be 1 if data_array1 is valid
  
  
  /* 
  while(check_line)  //will clash, careful
  {
    line_num1 = line_num1 + 1;
	check_line = iHexVerifyLine(data_array2);
	printf("line_num1 = %d ",line_num1);
    //data_array1 =  iHexSelectLoad(file, line_num1); 
    //printf("%d = %s",line_num1,data_array1);
	/*
    sscanf(&line_num1[length+1], "%2c", temp);
   
    
  }
   // uint8_t* data_array2 =  iHexSelectLoad(file, line_num2);
   
    //line_num2+=;
*/
 
  return data_array1;
  
}
//*/

//*//try fseek();
   
//*/

/*-------Shifting-(<<)-in Hexdecimal------------------
 * hexdecimal   ~     binary
 *   0x0F       =     00001111
 *______________________________start Shifting (0x0F<<4)
 *   0x0F0      =     000011110000 
 *---------------------------------------------------*/
///*// get address 16bit 
 int getAddress16bit(uint8_t *i_hex_array)
 {
  printf("Hex_array[1] = %x",i_hex_array[2]<<8); 
  int address = (i_hex_array[1]<<8) + i_hex_array[2];
  
  return address;  
 } 
//*/

///*// get address 32bit 
 int getAddress32bit(uint8_t *i_hex_array1,uint8_t *i_hex_array2)
 {
  int test_address = (i_hex_array1[5]<<16) + (i_hex_array2[2]<<0);
  int address = (i_hex_array1[4]<<24) + (i_hex_array1[5]<<16) + (i_hex_array2[1]<<8) + i_hex_array2[2];
  printf("test_address = %x\n",test_address); 
  return address;  
 } 
//*/
    
//*//Record type****************
int recordType(char* line)
{
  uint8_t* array_data=iHexGetArrayofData(line);
  int r_type = array_data[3];
  return r_type;
}  
//*/

///*//read as 0xXX (8byte) element from file
uint8_t* iHexGetArrayofData(char *line)
{
  int length = 0;
  char temp;
  uint8_t *result;
  
  while(1)
  {
    sscanf(&line[length+1], "%2c", &temp);
    
    if(line[length+1] != NULL) //change line[length+1] to...(char*)line[length+1]
    { 
      length = length + 2;
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
   *  record type         mean                
   *      00       Data
   *      01       End Of File
   *      02       Extended Segment Address ( ignored )
   *      03       Start Segment Address (For 80x86 processors,ignored)
   *      04       Extended Linear Address
   *      05       Start Linear Address ( ignored )
   *---------------------------------------------------------------*/
//*//try iHexGetAddress*****************function r_type()
uint8_t* iHexGetAddress(int* r_type,char *i_hex_array1,char *i_hex_array2)
{
  uint8_t* address;
  switch(*r_type)
  {
    case 0://record type = 0
      address = getAddress16bit(i_hex_array1);
      break;
    case 1://record type = 01
      address = NULL;
      break;
    case 4://record type = 04
      address = getAddress32bit(i_hex_array1,i_hex_array2);
     break; 
    default:            
      address = NULL;
     break;
  }
 
  return address;
}  
//*/

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
/* some problem look degerous----------
 * 1 - char *i_hex[i] , i has not declare a value 
 * 2 - function getiHexLine() able do job like read 
 *     all element in file by call it multiple time
 *      
 *------------------------------------*/
/*// fgets()2 read all element in the file ***has problem
char* iHexLineGet(FILE * file) //:04001000230E1200A9\n
{ 
  int i,j;
  int buf_size = 100; 
  char *str[10];
  char *i_hex[i];
  int sample[10000];
  int *i_hex_mem = (int *)malloc(sizeof(int)*buf_size); //Stored in heap segment
  FILE *fptr = fopen(file,"r");
  if (fptr)
  {
      i_hex[i] = malloc(buf_size);
      //i_hex_mem[j] = malloc(buf_size);
	  
      while (fgets(i_hex[i], buf_size , fptr))
      {
        i++;
        i_hex[i] = (char *)malloc(sizeof(char)*buf_size);
      }
      i_hex[i] = malloc(10*sizeof(char));
      
      //printf("the 3rd line - %s",i_hex[2]);
      printf("ihex - %s",*i_hex);
      printf("Number of elements in 1st line  :%d\n", strlen(i_hex[1]));
      printf("No-----------All elemennt in file--------------------\n");
      for( j=0 ; j<i ; j++)
      {
        printf("%d - %s",j,i_hex[j]);
        //sscanf(i_hex[j] , "%s" , *sample);  
        //*(i_hex_mem+j) = i_hex[j];
        //memcpy(i_hex[j],&sample ,sizeof sample);
      }
	  printf("-------------End of file elemennt--------------------\n");
	  sscanf(i_hex[4] , "%s" , *sample);
    printf("sample string return %s\n", *sample);
 
      for(int x=0 ; x<i ; x++)
      {
        //free(i_hex_mem[x]);  
        free(i_hex[x]);
        
        fclose(fptr);
        return i_hex[2]; // only return one array?
      }
	
  }
}
*/
