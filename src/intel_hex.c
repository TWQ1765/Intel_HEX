#include "intel_hex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

//#define SWAP(a, b) do { typeof(a) temp = a; a = b; b = temp; } while (0)//swap function



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

///* //function open file not needed ?
FILE* handler(char *file)//return as pointer type FILE 'FILE *'
{
  FILE *file_handler;              //pointer fileHandler
  
  file_handler = fopen(file , "r");
 
  return file_handler;             // pointer return
}
///*/

//*// fgets() 
char* getiHexLine(FILE * file_handler)
{
  char hex_line[1028];
  return fgets(hex_line,1028, file_handler);
}
//*/

//*// fgets()2 read all element
char* iHexLineGet(FILE * file_handler) //:04001000230E1200A9\n
{
  /*
  char str[100];
  int i = 0;
  int length_of_ihex;
  if(file_handler)
  {
    while (fscanf(file_handler, "%s", str[i+1]) != EOF)
    {
     // strcpy(str[i],getiHexLine(file_handler) );//getiHexLine(file_handler)
      length_of_ihex = strlen(str);
      printf("number %d length of the i_hex is %d\n",i,length_of_ihex);
    }i++;
  }
  return *str;
  */
  
  int len,i;
  int buf_size = 1000; 
  char *str[10];
  char *i_hex[i];
  FILE *fptr;
  fptr = fopen(file_handler,"r");
  if (fptr)
  {
    i_hex[i] = malloc(buf_size);
    while (fgets(i_hex[i], buf_size , fptr))
    {
      i++;
      i_hex[i] = malloc(buf_size);
    }
    printf("Output :\n");
    srand(time(NULL));
    int j = rand()%i;
    int k = (j+1)%i;
    fflush(stdout);
    printf("%d - %s%d - %s",j, i_hex[j],k,i_hex[k]);
    int x;
    for(x=0 ; x<i ; x++)
    {
      free(i_hex[x]);
      scanf("%d",x);
      fclose(fptr);
    return 0;
    }
    
    printf("Data (intel_Hex) from  the Hex file\n");
    printf("_______________________________________________\n");
    while((len = getc(fptr))!=EOF)
    //fscanf(fptr, "%[^\n]",str);//read until the newline
    //printf("Data from file:\n%s",str);
    
    putchar(len);
    fclose(fptr);
    printf("_______________________________________________\n");
    printf("length of the row of data is %d\n", len); // len=-1 ?
    return str;
  }
  
  //char hex_line[1028];
  //return fgets(hex_line,1028, file_handler);
}
//*/

//*/try fseek();
   
//*

/*/try read all element at file 
int readAll(char *file)
{
    
    for(int i = 0; s[i] != '\0'; ++i);
    for(int j = 0: )

    printf("Length of string: %d", i);
    
    return i;
}  
//*/
/* 
 FILE *file;
    char str[60];
    // opening file for reading 
    file = fopen("data/TestCode.hex" , "r");
    fgets (str, 60, file);
    // writing content to str
    puts(str);
    fclose(file);  
    */
    
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

/*//try iHexGetAddress*****************function r_type()
int iHexGetAddress(char * line)
{
  uint8_t* array_data[][]=iHexGetArrayofData(line);
  int r_type = recordType(line);
  
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
    case   
  }
 
  return address;
}  
*/