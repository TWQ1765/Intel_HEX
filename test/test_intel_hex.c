#include "unity.h"
#include "intel_hex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "CException.h"
#include "Exception.h"
//#include "token.h"
#include "Error.h"
void setUp(void)
{
}

void tearDown(void)
{
}
/*----------Intel_hex_Information_-------------------------
 *- 1 - the .hex file is locate at the following directory. 
 *-     Intel_HEX\doc , name is Blinky.X.production.hex.
 *- 2 - camelcasing Ex.) getiHexLine refering to function.
 *- 3 - snake_casing EX.) i_hex refering to constant decelation .
 *--------------------------------------------------------*/
 
//*//test file Blinky.X.production occur or not? 
void test_intelfile_fopen_expect_and_return_true(void)
{
	CEXCEPTION_T ex;
    FILE *file_handler; //pointer
	//printf("tyr exception");
	Try{
		file_handler = handler("doc/Blinky.X.production.hex"); //pointer=pointer
		TEST_ASSERT_NOT_NULL(file_handler);
	}
	Catch(ex){
		dumpException(ex);
	}
	
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

//*//Try read only 3rd line from file, able return 3rd line after run the function 3 time
  void test_iHexLineGet_read_only_3rd_line_from_file_expect_true(void)
  { 
	char* data_str[] ={\
	":020000040000FA\n",":10000000560E08EC00F0020E020E020E06EF00F093\n",\
	":04001000230E1200A9\n",":020014000000EA\n",":020000040030CA\n",\
	":01000100C836\n",":010003001EDE\n",":010005008377\n",":0100060001F8\n",":00000001FF\n"};
    char* i_hex;
    FILE *file_handler; //pointer
    file_handler = handler("doc/Blinky.X.production.hex"); //pointer=pointer
    
    for (int i =0 ; i <= 2 ; i++)
    {
      i_hex = getiHexLine(file_handler);
    }
    TEST_ASSERT_EQUAL_STRING(data_str[2], i_hex);//the 3rd line from file
  } 
//*/

//*//Try load the selected line from file test with data_str. 
  void test_iHexSelectLoad_load_selected_line_form_file_expect_true(void)
  { 
    char* data_str[] ={\
	":020000040000FA\n",":10000000560E08EC00F0020E020E020E06EF00F093\n",\
	":04001000230E1200A9\n",":020014000000EA\n",":020000040030CA\n",\
	":01000100C836\n",":010003001EDE\n",":010005008377\n",":0100060001F8\n",":00000001FF\n"};
    char* file ="doc/Blinky.X.production.hex";
    int line_num = 0; // changing this value to test if -VE number will clash
                      // number over will return NULL
    char* selecte_data = iHexSelectLoad(file, line_num);
    
    TEST_ASSERT_EQUAL_STRING(data_str[0], selecte_data);
  } 
//*/


//*//Try read only all line from file **************
  void test_iHexLoadHexFileToMemory_read_all_line_from_file_expect_true(void)
  { 
    char* data_str[] ={\
	":020000040000FA\n",":10000000560E08EC00F0020E020E020E06EF00F093\n",\
	":04001000230E1200A9\n",":020014000000EA\n",":020000040030CA\n",\
	":01000100C836\n",":010003001EDE\n",":010005008377\n",":0100060001F8\n",":00000001FF\n"};
    
    char* file ="doc/Blinky.X.production.hex";
    
    char* all_data = iHexLoadHexFileToMemory(file);
   
    TEST_ASSERT_EQUAL_STRING(data_str[1], all_data);
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
    TEST_ASSERT_EQUAL_HEX32(0x0000003a, *line);
  } 
//*/

///*/try test  Address 0x0000 //just try test dont have fuction
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
    TEST_ASSERT_EQUAL_HEX32(0x00000000, addresslow);  
  } 
//*/

///*/try test Record type //just try test dont have fuction
  void test_intel_hex_Record_type_given_and_return_0x00000004(void)
  {
    char iHexLine[] = ":020000040000FA";
    int Record_type;
    sscanf(&iHexLine[7] , "%2x" , &Record_type);
    printf("Record type of the String: 0x0%x\n", Record_type); 
    TEST_ASSERT_EQUAL_HEX32(0x00000004, Record_type);
  } 
//*/

//*//try test Data 
  void test_intel_hex_data(void)
  { 
    int data;
    char iHexLine[] = ":020000040000FA\n";
 
    sscanf(&iHexLine[9] , "%2x" , &data);
    printf("Record type of the String: 0x0%x\n", data); 
    TEST_ASSERT_EQUAL_HEX32(0x00000000, data);
  } 
//*/

//*//Try test valid intel_Hex right
  void test_iHexVerifyLine_given_right_expect_return_1(void)
  { 
    int sum_hex;
    char *i_hex = ":04001000230E1200A9\n";
    sum_hex = iHexVerifyLine(i_hex);
    printf("the sum of intel_Hex return %d\n", sum_hex);
    TEST_ASSERT_EQUAL(1, sum_hex);
  } 
//*/

//*//Try test valid intel_Hex error code with error checksum
  void test_iHexVerifyLine_given_error_checksum_code_expect_return_0(void)
  { 
    int sum_hex;
    char *i_hex = ":10000000560E08EC00F0020E020E020E06EF00F094\n";
    sum_hex = iHexVerifyLine(i_hex);
    printf("the sum of intel_Hex return %d\n", sum_hex);
    TEST_ASSERT_EQUAL(0, sum_hex);
  } 
//*/

//*//Try test valid intel_not_have_startSimbol ':'
  void test_iHexVerifyLine_given_not_have_startSimbol_expect_return_0(void)
  { 
    int sum_hex;
    char *i_hex = "10000000560E08EC00F0020E020E020E06EF00F094\n";
    sum_hex = iHexVerifyLine(i_hex);
    printf("the sum of intel_Hex return %d\n", sum_hex);
    TEST_ASSERT_EQUAL(0, sum_hex);
  } 
//*/
//*//Try test convert intel_Hex to array in 16-bits. 
  void test_iHexGetArrayofData_expect_array_data_return_true(void)
  { 
    uint8_t array_data[]= {\
	0x10,0x00,0x00,0x00,0x56,0x0E,0x08,0xEC,0x00,0xF0,\
	0x02,0x0E,0x02,0x0E,0x02,0x0E,0x06,0xEF,0x00,0xF0,0x93};
    char *i_hex = ":10000000560E08EC00F0020E020E020E06EF00F093";
    uint8_t* i_hex_array = iHexGetArrayofData(i_hex);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(array_data, i_hex_array, 21);
    free (i_hex_array); //deallocate allocated memory
  } 
//*/
//*//Try test convert intel_Hex to array in 16-bits. 
  void test_iHexGetArrayofData_expect_array_data_return_error(void)
  { 
    uint8_t array_data[]= {\
	0x10,0x00,0x00,0x00,0x56,0x0E,0x08,0xEC,0x00,0xF0,\
	0x02,0x0E,0x02,0x0E,0x02,0x0E,0x06,0xEF,0x00,0xF0,0x93};
    char *i_hex = ":10000000560E08EC00F0020E020E020E06EF00F093";
    uint8_t* i_hex_array = iHexGetArrayofData(i_hex);
    TEST_ASSERT_EQUAL_INT8(array_data[4], 0x56);//test only one 16bit data
    TEST_ASSERT_EQUAL_UINT8_ARRAY(array_data, i_hex_array, 21); //test all set 16bit data
    free (i_hex_array); //deallocate allocated memory
  } 
//*/
 
//*//Try test Record type
  void test_recordType_given_04_expect_and_return_error(void)
  { 
    char *i_hex = ":10000004560E08EC00F0020E020E020E06EF00F093";
    int r_type = recordType(i_hex);
    TEST_ASSERT_EQUAL(04, r_type);
  } 
//*/

void test_getAddress16bit_address_as_16bit(void)
{
  char *i_hex = ":040A1000230E1200A9\n";
  uint8_t* i_hex_array = iHexGetArrayofData(i_hex);
  int address = getAddress16bit(i_hex_array);
  
  TEST_ASSERT_EQUAL(0x0A10, address);
}
  
void test_getAddress32bit_address_as_16bit(void)
{
  char *i_hex1 = ":020000040030CA\n";
  char *i_hex2 = ":01000100C836\n";
  uint8_t* i_hex_array1 = iHexGetArrayofData(i_hex1);
  uint8_t* i_hex_array2 = iHexGetArrayofData(i_hex2);
  int address = getAddress32bit(i_hex_array1,i_hex_array2);//should= 0x00300001 | 3145729
  TEST_ASSERT_EQUAL_INT32(0x00300001, address);
  
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

/*//trying sscanf()
void test_sscanf(void)
{
  char iHexLine[] = "060023002c45ab38949c45";
  int value[100];
  
 // sscanf(&iHexLine[0] , "%2x" , &value);
 // TEST_ASSERT_EQUAL_HEX32(0x00000006, value);
 
	sscanf(&iHexLine , "%s" , &value);
	TEST_ASSERT_EQUAL_STRING("060023002c45ab38949c45\n", iHexLine);
}
*/

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

/*///Try something
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
    printf("try-zone------------------------------------\n"); 
    printf("%d\n",myArray[0][3]);
    printf("my array -%s\n",myArray[0]);
    TEST_ASSERT_EQUAL_STRING(":04001000230E1200A9\n", myArray);
  } 
*/

/*//Try sizeof able to select array string
  void test_sizeof_given(void)
  { 
    // Initialize arrays
  int mPlusN[] = {2, 8, 1, 1, 1, 13, 1, 15, 20}; //int
  char* N = "12345";				//char
  char* simplestr[] ={"12312312312","34534534534","67867869787686786"};
  int n = sizeof(int);
  int m = sizeof(mPlusN)/sizeof(mPlusN[0]); //9;
  
	printf("number of n :%d\n", n); //8 wrong
	printf("number of m :%d\n", m); //9 collect
	printf("simplestr  :%s\n", simplestr[2]); 
	TEST_ASSERT_EQUAL_STRING(":04001000230E1200A9\n", mPlusN);
  } 
*/

/*///Try function getiHexLine multiple time 
  void test_getiHexLine_multiple_given(void)
  { 
    char *i_hex1 = ":020000040030CA\n";
    char *i_hex2 = ":01000100C836";
    
    uint8_t* i_hex_array1 = getiHexLine();
    //TEST_ASSERT_EQUAL_STRING(":04001000230E1200A9\n", mPlusN);
  } 
*/
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









