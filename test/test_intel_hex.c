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
    FILE *file_handler; //pointer
    file_handler = handler("doc/Blinky.X.production.hex"); //pointer=pointer
    
    TEST_ASSERT_NOT_NULL(file_handler);
}
//*/

//*//test function getiHexline() only get 1st line of file
void test_getiHexLine_get_1st_Ihex_expect_and_return_true(void)
{
    FILE *file_handler; //pointer
    file_handler = handler("doc/Blinky.X.production.hex"); //pointer=pointer
    char* i_hex = getiHexLine(file_handler);
    
    TEST_ASSERT_EQUAL_STRING(":020000040000FA\n", i_hex);
}
//*/

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
  void test_intel_hex_Record_type_return_0x00000004(void)
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
    int sum_hex;
    char *i_hex = ":10000000560E08EC00F0020E020E020E06EF00F093";
    sum_hex = iHexVerifyLine(i_hex);
    printf("the sum of intel_Hex is %d\n", sum_hex);
    TEST_ASSERT_EQUAL(0, sum_hex);
  } 
//*/

//*//Try test valid intel_Hex error code
  void test_iHexVerifyLine_given_error_code_expect_return_0(void)
  { 
    int sum_hex;
    char *i_hex = ":10000000560E08EC00F0020E020E020E06EF00F094";
    sum_hex = iHexVerifyLine(i_hex);
    printf("the sum of intel_Hex is %d\n", sum_hex);
    TEST_ASSERT_EQUAL(1, sum_hex);
  } 
//*/

//*//Try test valid intel_not_have_startSimbol ':'
  void test_iHexVerifyLine_given_not_have_startSimbol_expect_return_0(void)
  { 
    int sum_hex;
    char *i_hex = "10000000560E08EC00F0020E020E020E06EF00F094";
    sum_hex = iHexVerifyLine(i_hex);
    printf("the sum of intel_Hex is %d\n", sum_hex);
    TEST_ASSERT_EQUAL(1, sum_hex);
  } 
//*/
//*//Try test convert intel_Hex to array in 16-bits. 
  void test_iHexGetArrayofData_expect_array_data_return_true(void)
  { 
    uint8_t array_data[]= {0x10,0x00,0x00,0x00,0x56,0x0E,0x08,0xEC,0x00,0xF0,0x02,0x0E,0x02,0x0E,0x02,0x0E,0x06,0xEF,0x00,0xF0,0x93};
    char *i_hex = ":10000000560E08EC00F0020E020E020E06EF00F093";
    uint8_t* i_hex_array = iHexGetArrayofData(i_hex);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(array_data, i_hex_array, 21);
    free (i_hex_array); //deallocate allocated memory
  } 
//*/
//*//Try test convert intel_Hex to array in 16-bits. 
  void test_iHexGetArrayofData_expect_array_data_return_error(void)
  { 
    uint8_t array_data[]= {0x10,0x00,0x00,0x00,0x56,0x0E,0x08,0xEC,0x00,0xF0,0x02,0x0E,0x02,0x0E,0x02,0x0E,0x06,0xEF,0x00,0xF0,0x93};
    char *i_hex = ":10000000560E08EC00F0020E020E020E06EF00F094";
    uint8_t* i_hex_array = iHexGetArrayofData(i_hex);
    TEST_ASSERT_EQUAL_INT8(array_data[4], 0x56);//test only one set data
    TEST_ASSERT_EQUAL_UINT8_ARRAY(array_data, i_hex_array, 21);
    free (i_hex_array); //deallocate allocated memory
  } 
//*/
 
//*//Try Record type
  void test_recordType_given_04_expect_00_return_error(void)
  { 
    
    char *i_hex = ":10000004560E08EC00F0020E020E020E06EF00F093";
    int r_type = recordType(i_hex);
    TEST_ASSERT_EQUAL(00, r_type);
    //TEST_ASSERT_EQUAL(0x98, iHexArray);
  } 
//*/

//*//Try read all from file************
  void test_iHexLineGet_given(void)
  { 
    FILE *file_handler; //pointer
    //file_handler = handler("doc/Blinky.X.production.hex");//pointer=pointer
    char* i_hex = iHexLineGet("doc/Blinky.X.production.hex");
    
    TEST_ASSERT_EQUAL_STRING(":04001000230E1200A9\n", i_hex);//the 3rd line from file
  } 
//*/

void test_getAddress16bit_address_as_16bit(void)
{
  char *i_hex = ":04001000230E1200A9\n";
  uint8_t* i_hex_array = iHexGetArrayofData(i_hex);
  int address = getAddress16bit(i_hex_array);
  
  TEST_ASSERT_EQUAL(0x0011, address);
}
  
void test_getAddress32bit_address_as_16bit(void)
{
  char *i_hex1 = ":020000040030CA\n";
  char *i_hex2 = ":01000100C836";
  uint8_t* i_hex_array1 = iHexGetArrayofData(i_hex1);
  uint8_t* i_hex_array2 = iHexGetArrayofData(i_hex2);
  int address = getAddress32bit(i_hex_array1,i_hex_array2);
  
  TEST_ASSERT_EQUAL(0x0011, address);
}

/**__TRY_ZONE_(can be ignore)_______________________________________________________________________*/
//TEST_ASSERT_EQUAL_INT8_ARRAY last test

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
  int value[100];
  
 // sscanf(&iHexLine[0] , "%2x" , &value);
 // TEST_ASSERT_EQUAL_HEX32(0x00000006, value);
 
	sscanf(&iHexLine , "%s" , &value);
	TEST_ASSERT_EQUAL_STRING("060023002c45ab38949c45\n", iHexLine);
}
//*/

/*trying sprintf()***************important remember
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

/*/try fseek()******************check output (false)
void test_fseek_trying(void)
{
  char *data[61];  //try put value *data[60]; other value show 0
  FILE *file_handler; 
  
  file_handler = handler("doc/Blinky.X.production.hex");
  
  fseek(file_handler, 10 ,SEEK_SET);
  fflush(*data);   //try (*data);
  fgets(data , 61 , file_handler);
  printf("data int = %d\ndata hex = %x\n", data, data);
  TEST_ASSERT_EQUAL(1, data);
}

*/

/*//Try swap value (not needed)
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

//*///Try something
  void test_something_given(void)
  { 
    int i;
    int n;
    int **myArray;

    n = 10;
    myArray = (int**)malloc(n*sizeof(int*));

    //Usage example
    int myIntArray[] = {1,2,3,4,5};

    myArray[0] = myIntArray;

    //This call should print "4"
    printf("%d\n",myArray[0][3]);
	printf("my array -%s\n",myArray[0]);
	TEST_ASSERT_EQUAL_STRING(":04001000230E1200A9\n", myArray);
  } 
//*/

//*///Try sizeof
  void test_sizeof_given(void)
  { 
    /* Initialize arrays */
  int mPlusN[] = {2, 8, 1, 1, 1, 13, 1, 15, 20}; //int
  char* N = "12345";				//char
  char* simplestr[] ={"12312312312","34534534534","67867869787686786"};
  int n = sizeof(N)/sizeof(N[0]);
  int m = sizeof(mPlusN)/sizeof(mPlusN[0]); //9;
 
	printf("number of n :%d\n", n); //8 wrong
	printf("number of m :%d\n", m); //9 collect
	printf("simplestr  :%s\n", simplestr[2]); 
	TEST_ASSERT_EQUAL_STRING(":04001000230E1200A9\n", mPlusN);
  } 
//*/

/*///Try read and skip 7 in the line
  void test_lineskip_given(void)
  { 
	char fileBuf[MAXFILE];
	FILE *f;
	int c,x;
	int MAXFILE=1000;
	size_t i;

	while (f = fopen("doc/Blinky.X.production.hex", "r")) 
	{
		for (i = 0; i < (MAXFILE - 1) && (c = getc(f)) != EOF; ++i)
			fileBuf[i] = c;
			fclose(f);
	} 	
	
	
	char line[MAXLINE];
		for (x = 0; x < 7; ++x)
		fgets(line, MAXLINE, f);
	TEST_ASSERT_EQUAL_STRING(":04001000230E1200A9\n", f);
  } 
*/









