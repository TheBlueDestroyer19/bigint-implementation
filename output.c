#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "all.h"

int countDigits(int num) {
  int digits=0;
  while(num!=0) {
    digits++;
    num/=10;
  }
  return digits;
}

void print(int1024* num) {
  int digits;
  if(num->val==NULL && num->sign==0) printf("There is a case of integer overflow. Operation performed is causing the overflow.\n");
  else if(num->val==NULL && num->sign==1) printf("There is a case of integer underflow. Operation performed is causing the underflow.\n");
  else if(num->filled==0) printf("0");
  else {
    if(num->sign==1) printf("-");
    for(int i=num->filled-1;i>=0;i--) {
      digits=countDigits(num->val[i]);
      if(i!=num->filled-1 && digits<9) {
        for(int j=1;j<=9-digits;j++) printf("0");
      }
      if(digits!=0) printf("%d",num->val[i]);
    }
  }
}
