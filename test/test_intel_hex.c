#include "unity.h"
#include "intel_hex.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_intel_hex_fopen(void)
{
    FILE *file;
    file = fopen("data/TestCode.hex","r");
    TEST_ASSERT_NOT_NULL(file);
}

void test_intel_hex2_fopen(void)
{
    FILE *file;
    file = fopen("doc/Blinky.X.production.hex","r");
    TEST_ASSERT_NOT_NULL(file);
}
void test_scanf(void)
{
  int x;
  scanf("%d" , &x);
  printf("This is a test value must be int : %d\n" , x);
}
