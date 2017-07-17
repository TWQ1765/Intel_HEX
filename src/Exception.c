#include <stdio.h>
#include <stdlib.h>
#include "Exception.h"


Exception *createException(char *msg, int errorCode){
  Exception *e = malloc(sizeof(Exception));   //<stdlib.h>
  e->msg = msg;
  e->errorCode = errorCode;
  return e;
}

void freeException(Exception *e){
  free(e);      //<stdlib.h>
}

void dumpException(Exception *e){
  printf("%s (err=%d)\n", e->msg, e->errorCode);
}
