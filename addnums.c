#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "all.h"

int1024* add(int1024* num1, int1024* num2) {
  int1024* sum;
  int1024 numx, numy;
  int partial_sum=0,carry=0;
  int1024 *max=maxcalc();
  if((num1->sign==0 && num2->sign==0 )||( num1->sign==1 && num2->sign==1)) {
    sum=(int1024*)malloc(sizeof(int1024));
    sum->val=(int*)malloc(sizeof(int)*35);
    int i=0,j=0,k=0;
    while(i<num1->filled && j<num2->filled && k<35) {
      partial_sum=num1->val[i]+num2->val[j]+carry;
      carry=partial_sum/1000000000;
      sum->val[k]=partial_sum%1000000000;
      k++; i++; j++;
    }
    while(i<num1->filled && k<35) {
      partial_sum=num1->val[i]+carry;
      carry=partial_sum/1000000000;
      sum->val[k]=partial_sum%1000000000;
      k++; i++;
    }
    while(j<num2->filled && k<35) {
      partial_sum=num2->val[j]+carry;
      carry=partial_sum/1000000000;
      sum->val[k]=partial_sum%1000000000;
      k++; j++;
    }
    if(carry!=0 && k<35) {sum->val[k]=1; k++;}

    if(k<=35) sum->filled=k;
    else sum->filled=35;

    if(k>35 && compare(sum, max)==-1) {
      free(sum->val);
      sum->val=NULL;
    }
    free(max->val);
    free(max);
    if(num1->sign==1 && num2->sign==1 && k<=35) sum->sign=1;
  }
  else if(num1->sign==0 && num2->sign==1) {
    numx=*num1;
    numy=*num2;
    numy.sign=0;
    sum=subtract(&numx,&numy);
  }
  else {
    numx=*num1;
    numy=*num2;
    numx.sign=0;
    sum=subtract(&numy,&numx);
  }
  return sum;
}
