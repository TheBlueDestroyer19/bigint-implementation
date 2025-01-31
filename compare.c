#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "all.h"

int compare(int1024* num1, int1024* num2) {
  int retval=0;
  if(num1->filled!=num2->filled) {
    retval=num1->filled - num2->filled;
    if(retval<0) retval=-1;
    else if(retval>0) retval=1;
  }    
  else {
    for(int i=num1->filled -1; i>=0 && !retval; i--) {
      retval=num1->val[i]-num2->val[i];
    }
  }
  if(retval<0) retval=-1;
  else if(retval>0) retval=1;

  return retval;
}
