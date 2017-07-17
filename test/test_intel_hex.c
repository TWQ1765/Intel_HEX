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
  
  sscanf(&iHexLine[0] , "%2x" , &value);
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
//*//trying fgets() test Byte count
void test_iHexGetLength_given_020000040000FA_expect_2(void)
{
  char line[] = ":020000040000FA";
 
  char len = iHexGetLength(line);
 
//  sscanf(&iHexLine[1] , "%2x" , &line);
  printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
  printf("Byte count of the String: 0x0%d\n", len); 
  TEST_ASSERT_EQUAL_HEX32(1, len);
 
}
//*/try test startcode ':'=0x7ff9
  void test_intel_hex_startcode(void)
  {
    char iHexLine[] = ":020000040000FA";
    char *line = iHexLine; 
    int iHexGetstartcode(char**line);
    sscanf(&iHexLine[0] , "%*" , *line);
    printf("start of the String:'%c'\n \
    Hex_value = 0x%x\n",*line,*line); 
    TEST_ASSERT_EQUAL_HEX32(0x0000003a, *line);
  } 
//*/

//*/try test  Address 0x0000
  void test_intel_hex_Address(void)
  {
    char iHexLine[] = ":020000040000FA";
    int value,addresslow,addresshigh;
      
    //test full address
    sscanf(&iHexLine[3] , "%4x" , &value);
    printf("Address of the String: 0x000%x\n", value); 
    TEST_ASSERT_EQUAL_HEX32(0x00000000, value);
    //test address high byte
    sscanf(&iHexLine[3] , "%2x" , &addresshigh);
    printf("addresshigh of the String: 0x0%x\n",addresshigh); 
    TEST_ASSERT_EQUAL_HEX32(0x00000000, addresshigh);
    //test address low byte
    sscanf(&iHexLine[5] , "%2x" , &addresslow);
    printf("addresslow of the String: 0x0%x\n", addresslow); 
    TEST_ASSERT_EQUAL_HEX32(0x00000001, addresslow);  
  } 
//*/

//*/try test Record type 
  void test_intel_hex_Record_type (void)
  {
    char iHexLine[] = ":020000040000FA";
    int Record_type;
    sscanf(&iHexLine[7] , "%2x" , &Record_type);
    printf("Record type of the String: 0x0%x\n", Record_type); 
    TEST_ASSERT_EQUAL_HEX32(0x00000000, Record_type);
  } 
//*/

//*/try test Data 
  void test_intel_hex_data (void)
  { 
    int data;
    char iHexLine[] = ":020000040000FA";
 
    sscanf(&iHexLine[9] , "%2x" , &data);
    printf("Record type of the String: 0x0%x\n", data); 
    TEST_ASSERT_EQUAL_HEX32(0x00000000, data);
  } 
//*/

/*/try test iHexGetArrayofData 
  void test_intel_hex_iHexGetArrayofData(void)
  { 
    char iHexLine[] = ":020000040000FA";
  if(iHexLine) { 
    iHexGetArrayofData(iHexLine, file);
    fprintf(stdout, "There are %u lines in the file %s.\n", iHexLine, file);
  }
  else
    {
      fprintf(stderr, "Failed to open file %s\n", file);
      return -1;
    }
  return 0;
    
    //TEST_ASSERT_EQUAL_HEX32(0x00000000, data);
  } 
*/
