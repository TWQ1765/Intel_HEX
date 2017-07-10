#include "intel_hex.h"
#include <stdio.h>
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
/*get length
int iHexGetLength(char * line)
{
   
   char line[60];
   fgets(line, 60 ,file);
   puts(line);
   
   return line;
}
*/ 
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
/*// fgets()
int iHexGetLength(char * line)
{
  FILE *file;
  char *line[50];
  //file = fopen("doc/Blinky.X.production.hex" , "r");
  fgets(line , 50 , file);
  fclose(file);
  return line;
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