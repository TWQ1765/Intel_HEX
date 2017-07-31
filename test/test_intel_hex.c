#include "unity.h"
#include "intel_hex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void setUp(void)
{
}

void tearDown(void)
{
}


//*//test file Blinky.X.production occur or not? 
void test_intelfile_fopen_expect_and_return_true(void)
{
    FILE *filehandler; //pointer
    filehandler = handler("doc/Blinky.X.production.hex"); //pointer=pointer
    
    TEST_ASSERT_NOT_NULL(filehandler);
}
//*/

//*//test function getiHexline()
void test_getiHexLine_get_1st_Ihex_expect_and_return_true(void)
{
    FILE *filehandler; //pointer
    filehandler = handler("doc/Blinky.X.production.hex"); //pointer=pointer
    char* iHex = getiHexLine(filehandler);
    
    TEST_ASSERT_EQUAL_STRING(":020000040000FA\n", iHex);
}
//*/

/*//trying scanf ()
void test_scanf(void)
{
  int x;
  scanf("%d" , &x);
  printf("This is a test value must be int : %d\n" , x);
}
*/

/*//trying sscanf()
void test_sscanf(void)
{
  char iHexLine[] = "060023002c45ab38949c45";
  int value;
  
  sscanf(&iHexLine[0] , "%2x" , &value);
  TEST_ASSERT_EQUAL_HEX32(0x00000006, value);
}
*/

/*trying sprintf
void test_sprintf_()
{
  char *buffer;
  buffer = malloc(1028);
  sprintf(buffer, "Hello Word 0x%d,%f",1234,5678);
  TEST_ASSERT_EQUAL_STRING("Hello Word 0x1234,0.000000", buffer);
  free(buffer);
}
*/

/*//trying fgets() test Byte count HAS PROBLEM LEN
void test_iHexGetLength_given_020000040000FA_expect_2(void)
{
  char line[] = ":020000040000FA";
 
  char len = iHexGetLength(line);
 
//  sscanf(&iHexLine[1] , "%2x" , &line);
  printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
  printf("Byte count of the String: 0x0%d\n", len); 
  TEST_ASSERT_EQUAL_HEX32(1, len);
}
*/

///*//try test startcode ':' == ASSCI:3a
  void test_intel_hex_startcode(void)
  {
    char iHexLine[] = ":020000040000FA";
    char *line = iHexLine; 
    int iHexGetstartcode(char**line);
    sscanf(&iHexLine[0] , "%*" , *line);
    printf("start of the String:'%c'\n \
    Hex_value = 0x%x\n",*line,*line); 
    TEST_ASSERT_EQUAL_HEX32(0x00000001, *line);
  } 
//*/

///*/try test  Address 0x0000
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

///*/try test Record type 
  void test_intel_hex_Record_type(void)
  {
    char iHexLine[] = ":020000040000FA";
    int Record_type;
    sscanf(&iHexLine[7] , "%2x" , &Record_type);
    printf("Record type of the String: 0x0%x\n", Record_type); 
    TEST_ASSERT_EQUAL_HEX32(0x00000000, Record_type);
  } 
//*/

/*//try test Data 
  void test_intel_hex_data(void)
  { 
    int data;
    char iHexLine[] = ":020000040000FA";
 
    sscanf(&iHexLine[9] , "%2x" , &data);
    printf("Record type of the String: 0x0%x\n", data); 
    TEST_ASSERT_EQUAL_HEX32(0x00000000, data);
  } 
*/

//*//Try test valid intel_Hex right
  void test_iHexVerifyLine_given_right_expect_return_1(void)
  { 
    int sumHex;
    char *iHex = ":10000000560E08EC00F0020E020E020E06EF00F093";
    sumHex = iHexVerifyLine(iHex);
    printf("the sum of intel_Hex is %d\n", sumHex);
    TEST_ASSERT_EQUAL(0, sumHex);
  } 
//*/

//*//Try test valid intel_Hex error code
  void test_iHexVerifyLine_given_error_code_expect_return_0(void)
  { 
    int sumHex;
    char *iHex = ":10000000560E08EC00F0020E020E020E06EF00F094";
    sumHex = iHexVerifyLine(iHex);
    printf("the sum of intel_Hex is %d\n", sumHex);
    TEST_ASSERT_EQUAL(1, sumHex);
  } 
//*/

//*//Try test valid intel_not_have_startSimbol ':'
  void test_iHexVerifyLine_given_not_have_startSimbol_expect_return_0(void)
  { 
    int sumHex;
    char *iHex = "10000000560E08EC00F0020E020E020E06EF00F094";
    sumHex = iHexVerifyLine(iHex);
    printf("the sum of intel_Hex is %d\n", sumHex);
    TEST_ASSERT_EQUAL(1, sumHex);
  } 
//*/
//*//Try test convert intel_Hex to array in 16-bits. 
  void test_iHexGetArrayofData_expect_array_data_return_true(void)
  { 
    uint8_t arrayData[]= {0x10,0x00,0x00,0x00,0x56,0x0E,0x08,0xEC,0x00,0xF0,0x02,0x0E,0x02,0x0E,0x02,0x0E,0x06,0xEF,0x00,0xF0,0x93};
    char *iHex = ":10000000560E08EC00F0020E020E020E06EF00F093";
    uint8_t* iHexArray = iHexGetArrayofData(iHex);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(arrayData, iHexArray, 21);
    free (iHexArray); //deallocate allocated memory
  } 
//*/
//*//Try test convert intel_Hex to array in 16-bits. 
  void test_iHexGetArrayofData_expect_array_data_return_error(void)
  { 
    uint8_t arrayData[]= {0x10,0x00,0x00,0x00,0x56,0x0E,0x08,0xEC,0x00,0xF0,0x02,0x0E,0x02,0x0E,0x02,0x0E,0x06,0xEF,0x00,0xF0,0x93};
    char *iHex = ":10000000560E08EC00F0020E020E020E06EF00F094";
    uint8_t* iHexArray = iHexGetArrayofData(iHex);
    TEST_ASSERT_EQUAL_INT8(arrayData[4], 0x56);//test only one set data
    TEST_ASSERT_EQUAL_UINT8_ARRAY(arrayData, iHexArray, 21);
    free (iHexArray); //deallocate allocated memory
  } 
//*/

/*//Try swap value not needed
  void test_swapvalue_given_0x20_and_0x98_expect_0x98_and_0x20(void)
  { 
    uint8_t* highbit = 0x20;
    uint8_t* lowbit  = 0x98;
    uint16_t* iHexArray = swapvalue(highbit,lowbit);
    //struct value* function(highbit,lowbit);
    
    TEST_ASSERT_EQUAL(0x20, iHexArray);
    TEST_ASSERT_EQUAL(0x98, iHexArray);
  } 
*/


