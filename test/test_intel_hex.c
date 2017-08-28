#include "unity.h"
#include "intel_hex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "CException.h"
#include "Exception.h"
#include "Error.h"
void setUp(void)
{
}

void tearDown(void)
{
}
/*----------------------Intel_hex_Information_--------------------------
 *- 1 - the .hex file is locate at the following directory. 
 *-     (‪C:\Student\TWQ\projects\C\Intel_HEX\doc\Blinky.X.production.hex)
 *- 2 - camelCasing Ex.) getiHexLine refering to function.
 *- 3 - snake_casing EX.) i_hex refering to constant decelation .
 *----------------------------------------------------------------------*/
 
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

//*// load**********************************************************************
  void test_iHexLoadHexFileToMemory_return_struct_given_data_address_expect_true(void)
  { 
    char* data_str[] ={\
	":020000040000FA\n",":10000000560E08EC00F0020E020E020E06EF00F093\n",\
	":04001000230E1200A9\n",":020014000000EA\n",":020000040030CA\n",\
	":01000100C836\n",":010003001EDE\n",":010005008377\n",":0100060001F8\n",\
	":010000051EDC\n",":00000001FF\n"};
    uint8_t i_hex_data1[] ={0x56,0x0E,0x08,0xEC,0x00,0xF0,\
    0x02,0x0E,0x02,0x0E,0x02,0x0E,0x06,0xEF,0x00,0xF0};
	uint8_t i_hex_data2[] ={0x23,0x0E,0x12,0x00};
	
	//uint8_t* data;
	ADDRESSDATA addressData;
	
	addressData = iHexLoadHexFileToMemory(data_str[4],data_str[5]);
	
	//TEST_ASSERT_EQUAL_INT32(0x00300001, addressData.address); 
    //TEST_ASSERT_EQUAL_UINT8_ARRAY(data_str[0], data1, 14);
	TEST_ASSERT_EQUAL_UINT8_ARRAY(i_hex_data1, &addressData.data, 14);
  } 
//*/




/*//Try read only all line from file **************WE ARE HERE
  void test_iHexLoadHexFileToMemory_read_all_line_from_file_expect_true(void)
  { 
    char* data_str[] ={\
	":020000040000FA\n",":10000000560E08EC00F0020E020E020E06EF00F093\n",\
	":04001000230E1200A9\n",":020014000000EA\n",":020000040030CA\n",\
	":01000100C836\n",":010003001EDE\n",":010005008377\n",":0100060001F8\n",":00000001FF\n"};
    uint8_t array_data[]= {\
    0x10,0x00,0x00,0x00,0x56,0x0E,0x08,0xEC,0x00,0xF0,\
    0x02,0x0E,0x02,0x0E,0x02,0x0E,0x06,0xEF,0x00,0xF0,0x93};
	
	
    
    
	
    TEST_ASSERT_EQUAL_UINT8_ARRAY(array_data, i_hex_array, 21);
  } 
*/
/*// Array put at specific address location of memory*************WE ARE HERE
  void test_specificAddressOfArray_expect_true(void)
  { 
    char* data_str[] ={\
	":020000040000FA\n",":10000000560E08EC00F0020E020E020E06EF00F093\n",\
	":04001000230E1200A9\n",":020014000000EA\n",":020000040030CA\n",\
	":01000100C836\n",":010003001EDE\n",":010005008377\n",":0100060001F8\n",":00000001FF\n"};
    
	uint8_t* address;
	uint8_t* i_hex_array1 = iHexToArray(data_str[0]);
	uint8_t* i_hex_array2 = iHexToArray(data_str[1]);
	address = iHexGetAddress(4,i_hex_array1,i_hex_array2);
	
    uint8_t* data = getOnlyData(i_hex_array2);
    //printf("data = %x",data);
	
	memcpy((void*)address, data, sizeof data);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(i_hex_data, data, 14);
  } 
*/

//*// read only data from i_hex not include check_sum
  void test_getOnlyData_read_only_data_given_data_str_1_array_expect_true(void)
  { 
    char* data_str[] ={\
	":020000040000FA\n",":10000000560E08EC00F0020E020E020E06EF00F093\n",\
	":04001000230E1200A9\n",":020014000000EA\n",":020000040030CA\n",\
	":01000100C836\n",":010003001EDE\n",":010005008377\n",":0100060001F8\n",":00000001FF\n"};
    uint8_t i_hex_data1[] ={0x56,0x0E,0x08,0xEC,0x00,0xF0,\
    0x02,0x0E,0x02,0x0E,0x02,0x0E,0x06,0xEF,0x00,0xF0};
	uint8_t i_hex_data2[] ={0x23,0x0E,0x12,0x00};
	
	uint8_t* data1;
	uint8_t* data2;
	uint8_t* i_hex_array1 = iHexToArray(data_str[1]);
    data1 = getOnlyData(i_hex_array1);
	uint8_t* i_hex_array2 = iHexToArray(data_str[2]);
    data2 = getOnlyData(i_hex_array2);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(i_hex_data1, data1, 14);
	TEST_ASSERT_EQUAL_UINT8_ARRAY(i_hex_data2, data2, 4);
  } 
//*/

//*//read all record type for each line from file 
  void test_recordType_read_all_record_type_from_file_expect_true(void)
  { 
    char* data_str[] ={\
	":020000040000FA\n",":10000000560E08EC00F0020E020E020E06EF00F093\n",\
	":04001000230E1200A9\n",":020014000000EA\n",":020000040030CA\n",\
	":01000100C836\n",":010003001EDE\n",":010005008377\n",":0100060001F8\n",":00000001FF\n"};
    char* record_type_all[] ={4,0,0,0,4,0,0,0,0,1};
   
    char * all_r_type[1024]; 
    int check_line;
	
	check_line =9;
	printf(" line no:	-	Record Type:\n");
	for (int i =0 ; i <= check_line ; i++)
	{
		all_r_type[i] = recordType(data_str[i]);
		printf(" 	%d	=	 %d\n" , i , all_r_type[i]);
	}
	
    printf("sum of check_line = %d\n" ,check_line);
    printf("all_r_type = %d\n" ,all_r_type[0]);
	printf("record_type_all = %d\n" ,record_type_all[0]);
   
	TEST_ASSERT_EQUAL_STRING(":020000040000FA\n",data_str[0]);
	TEST_ASSERT_EQUAL_UINT_ARRAY(record_type_all, all_r_type, check_line);
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

//*//try test Data dont have fuction
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
  void test_iHexVerifyLine_given_right_intel_hex_expect_return_1(void)
  { 
    int check_hex;
    char *i_hex = ":04001000230E1200A9\n";
    check_hex = iHexVerifyLine(i_hex);
    printf("the sum of intel_Hex return %d\n", check_hex);
    TEST_ASSERT_EQUAL(1, check_hex);
  } 
//*/

//*//Try test valid intel_Hex error code with error checksum
  void test_iHexVerifyLine_given_error_checksum_code_expect_return_0(void)
  { 
    int check_hex;
    char *i_hex = ":10000000560E08EC00F0020E020E020E06EF00F094\n";
    check_hex = iHexVerifyLine(i_hex);
    printf("the sum of intel_Hex return %d\n", check_hex);
    TEST_ASSERT_EQUAL(0, check_hex);
  } 
//*/

//*//Try test valid intel_not_have_startSimbol ':'
  void test_iHexVerifyLine_given_not_have_startSimbol_expect_return_0(void)
  { 
    int check_hex;
    char *i_hex = "10000000560E08EC00F0020E020E020E06EF00F094\n";
    check_hex = iHexVerifyLine(i_hex);
    printf("the sum of intel_Hex return %d\n", check_hex);
    TEST_ASSERT_EQUAL(0, check_hex);
  } 
//*/

//*//Try test get intel hex data only by skipping 4-8bits in array.  
  void test_iHexToArray_expect_data_only_return(void)
  { 
    uint8_t array_data[]= {\
    0x10,0x00,0x00,0x00,0x56,0x0E,0x08,0xEC,0x00,0xF0,\
    0x02,0x0E,0x02,0x0E,0x02,0x0E,0x06,0xEF,0x00,0xF0,0x93};
    char *i_hex = ":10000000560E08EC00F0020E020E020E06EF00F093\n";
    uint8_t* i_hex_array = iHexToArray(i_hex);
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

//only for 05 record type to get start address
void test_startAddress_get_starAddress_as_32bit_expect_true(void)
{
  char *i_hex = ":04000005000000CD2A\n";
  uint8_t* i_hex_array = iHexToArray(i_hex);
  int startAddress = getAddressStart(i_hex_array);
  
  TEST_ASSERT_EQUAL(0x000000CD, startAddress);
}

void test_getAddress16bit_address_as_16bit_expect_true(void)
{
  char *i_hex = ":040A1000230E1200A9\n";
  uint8_t* i_hex_array = iHexToArray(i_hex);
  int address = getAddress16bit(i_hex_array);
  
  TEST_ASSERT_EQUAL(0x0A10, address);
}
  
void test_getAddress32bit_address_as_32bit_expect_true(void)
{
  char *i_hex1 = ":020000040030CA\n";
  char *i_hex2 = ":01000100C836\n";
  uint8_t* i_hex_array1 = iHexToArray(i_hex1);
  uint8_t* i_hex_array2 = iHexToArray(i_hex2);
  int address = getAddress32bit(i_hex_array1,i_hex_array2);//should= 0x00300001 | 3145729
  TEST_ASSERT_EQUAL_INT32(0x00300001, address);
}


///*case statement being use from fuction iHexToArray().
void test_iHexGetAddress_given_00300001_expect_true(void)
{
  char *i_hex1 = ":020001040030CA\n";//":020001040030CA\n"
  char *i_hex2 = ":01000100C836\n";
  int r_type = 4; //changing this valu to test
  uint8_t *address;
  uint8_t* i_hex_array1 = iHexToArray(i_hex1);
  uint8_t* i_hex_array2 = iHexToArray(i_hex2);
  
  address = iHexGetAddress(r_type,i_hex_array1,i_hex_array2);
  TEST_ASSERT_EQUAL_INT32(0x00300001, address); //3145729 decimal
  
}
//*/










