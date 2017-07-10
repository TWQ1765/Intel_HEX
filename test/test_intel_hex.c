#include "unity.h"
#include "intel_hex.h"
#include <stdio.h>
#include <stdlib.h>
//#include "mock_iHexGetLength.h"
void setUp(void)
{
}

void tearDown(void)
{
}
/*//test1: file TestCode occur or not?
void test_intel_hex_fopen(void)
{

    FILE *file;
    file = fopen("data/TestCode.hex","r");
    TEST_ASSERT_NOT_NULL(file);
}
*/
//test2: file Blinky.X.production occur or not?

void test_intel_hex2_fopen(void)
{
    FILE *file;
    file = fopen("doc/Blinky.X.production.hex","r");
    TEST_ASSERT_NOT_NULL(file);
}

/*//trying scanf ()
void test_scanf(void)
{
  int x;
  scanf("%d" , &x);
  printf("This is a test value must be int : %d\n" , x);
}
*/
//*//trying sscanf()
void test_sscanf(void)
{
  char iHexLine[] = "060023002c45ab38949c45";
  int value;
  
  sscanf(&iHexLine[2] , "%2x" , &value);
  TEST_ASSERT_EQUAL_HEX32(0x00000006, value);
}
//*/
///*trying sprintf
void test_sprintf_()
{
  char *buffer;
  buffer = malloc(1028);
  sprintf(buffer, "Hello Word 0x%d,%f",1234,5678);
  TEST_ASSERT_EQUAL_STRING("Hello Word 0x1234,0.000000", buffer);
  free(buffer);
}
//*/
//*//trying fgets()
void test_intel_hex_getLength(void)
{
  
  char iHexLine[] = "020000040000FA";
  int value;
  //iHexGetLength(":020000040000FA");
  //char *line = ":020000040000FA";
  //TEST_ASSERT_EQUAL_STRING(":020000040000FA", \
              iHexGetLength(":020000040000FA"));            
  //int iHexGetLength(":020000040000FA");
  sscanf(&iHexLine[0] , "%2x" , &value);
  printf(">>>>>>>>>>>>>>>>>>>>>>>>>");
  printf("start of the String: %s\n",&value); 
  TEST_ASSERT_EQUAL_HEX32(0x00000008, value);
}
//*/

//*/