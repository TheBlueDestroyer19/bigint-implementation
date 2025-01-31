#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "all.h"

int1024* subtract(int1024* num1, int1024* num2) {
  int1024* diff,*num3;
  int1024 numx,numy;
  int i=0,j=0,partial_diff=0, borrow=0,k=0;
  if(num1->sign==1 && num2->sign==0) {
    numx=*num1;
    numy=*num2;
    numy.sign=1;
    diff=add(&numx,&numy);
  }
  else if(num1->sign==0 && num2->sign==1) {
    numx=*num1;
    numy=*num2;
    numy.sign=0;
    diff=add(&numx,&numy);
  }
  else {
    diff=(int1024*)malloc(sizeof(int1024));
    diff->val=(int*)malloc(sizeof(int)*35);
    if(compare(num1,num2)==-1) {
      num3=num2;
      if(num2->sign==0) diff->sign=1;
      else diff->sign=0;
    }
    else {
      num3=num1;
      num1=num2;
      if(num1->sign==0) diff->sign=0;
      else diff->sign=1;
    }
    while(j<num1->filled) {
      partial_diff=num3->val[i]-num1->val[j]-borrow;
      if(partial_diff<0) {
        partial_diff=partial_diff+1000000000;
        borrow=1;
      }
      else borrow=0;
      diff->val[k]=partial_diff;
      i++;j++;k++;
    }
    while(i<num3->filled) {
      partial_diff=num3->val[i]-borrow;
      if(partial_diff<0) {
        partial_diff=partial_diff+1000000000;
        borrow=1;
      }
      else borrow=0;
      diff->val[k]=partial_diff;
      i++; k++;
    }
    diff->filled=k;
    for(int i=k-1;i>=0;i--) {
      if(diff->val[i]==0) (diff->filled)--;
      else break;
    }
    k=diff->filled;
    if(diff->val[k-1]==0 && diff->filled==1) diff->sign=0;
  }
  return diff;
}
