#include "unity.h"
#include "intel_hex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include <stdint.h>

//#include "Token.h"
#include "Error.h"
#include "Exception.h"
#include "CException.h"

void setUp(void) {}

void tearDown(void) {}

void test_throwException(void) {
  CEXCEPTION_T ex = NULL;
  char file = {
    "doc/Blinky.X.production.hex"
  };
  
  Try {
    throwException(ERR_INVALID_OPERAND,                                     \
                   "Invalid File, expecting a ',', but received '%s'\n", \
                    file);
  } Catch(ex) {
    dumpException(ex);
  }
  freeException(ex);
}
