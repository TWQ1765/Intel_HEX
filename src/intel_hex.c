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
  char tempHex;
  int i =0;
  int test=0;
  int sumHex=0;
  int getHex= 0x123;
  int startsimbol = 0;
  
  sscanf(&line[0] , "%c" , &startsimbol);//read simbol ':'
  if (startsimbol != 0x3a)//if 1st are not start with ':' return test=0
  { 
    return test = 0;
  }
  else 
  {    
    while(line[i+1] != NULL)//read the code until the end of line
    {
      sscanf(&line[i+1], "%2c" , &tempHex);
      sscanf(&line[i+1], "%2x" , &getHex);
      i=i+2;
      sumHex=sumHex+getHex;
      test = ((sumHex & 0xff)<=0);//check value of test should = 1
    }
  }
 return test;
}  
//*/ 

///* //function open file not needed ?
FILE* handler(char *file)//return as pointer type FILE 'FILE *'
{
  FILE *fileHandler;              //pointer fileHandler
  //char file[];
  fileHandler = fopen(file , "r");
 
  return fileHandler;             // pointer return
}
///*/

//*// fgets() 
char* getiHexLine(FILE * fileHandler)
{
  char hexline[1028];
  return fgets(hexline,1028, fileHandler);
}
//*/

/*// fgets()2 
char* getiHexLine(FILE * fileHandler)
{
  int length;
  char *hexline = malloc(length+1);
  length = fgets(hexline,0, fileHandler);
  printf("length requred:%d\n",length);
  return fgets(hexline,length, fileHandler);
}
*/

/*/try find length of string 
int find_length(char *file)
{
    char s[1000], i;
    char file = s;
    for(i = 0; s[i] != '\0'; ++i);

    printf("Length of string: %d", i);
    
    return i;
}  
*/
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
int Record_type(char* line)
{
  uint8_t* arraydata[]=iHexGetArrayofData(line);
  arraydata[2],[3]
  return line;
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

///*//read all element from file
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

/*//try iHexGetAddress*****************
int iHexGetAddress(char * line)
{
   uint8_t* arraydata[]=iHexGetArrayofData(line);
  arraydata[4] 
  return line;
}  

*/