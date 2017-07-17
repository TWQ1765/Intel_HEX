#include "intel_hex.h"
#include <stdio.h>
#include <stdlib.h>
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
///*get length
int iHexGetLength(char * line)
{
  char *linePtr = line;
 // for (int i=0; i<10; i++)
 // {
  int iHexLine = line[1]; 
 // }
   
  //char iHexLine[] = line;//":020000040000FA";
  
  //sscanf(&iHexLine[1] , "%2x" , &line);
  return iHexLine;
}
//*/ 
/* //open file not needed 
char handler()
{
  FILE *file;
  //char file[];
  file = fopen("doc/Blinky.X.production.hex" , "r");
  if (file == NULL)
  {
    return -1;
  }
  else
  return file;
}
*/
/*// fgets() only read the starting cade.
int iHexGetLength(char * line)
{
  
  return ;
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
    
/*//Record type
int Record_type()
{
  case(record_type)
  return 
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

/*//read all element from file
int iHexGetArrayofData(char *line, char*buffer)
{
  FILE*file = fopen("doc/Blinky.X.production.hex","r");
  
  if(file)
  {
    char buffer[4096] = {0};
    unsigned int line = 0;
    
    while(fgets(buffer, sizeof(buffer),file))
    {
      for(const char*ptr = buffer; *ptr!= '/0'; ptr++)
      {
        if(*ptr == '/n' || *ptr == '/r');
      }
    line = line + 1;
    }
  
  fprintf(stdout, "There are %u lines in the file %s.\n", line, file);
  }
  else
    {
      fprintf(stderr, "Failed to open file %s\n", file);
      return -1;
    }
  return 0;
}
*/

///*//try iHexGetAddress
int iHexGetAddress(char * line)
{
  char iHexLine[] = ":020000040000FA";
  sscanf(&iHexLine[3] , "%4x" , &line);
  return line;
}  

//*/