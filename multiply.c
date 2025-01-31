#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "all.h"


int1024* multiply(int1024* num1, int1024* num2) {
  int1024* product, *dummy;
  int i=0,j=0,k=0,st=0;
  unsigned long long int temp,prod,carry=0;
  product=(int1024*)malloc(sizeof(int1024));
  product->val=(int*)malloc(sizeof(int)*35);
  product->sign=0;
  int1024 *max=maxcalc();
  int1024* partial_product=(int1024*)malloc(sizeof(int1024));
  partial_product->val=(int*)malloc(sizeof(int)*35);
  product->filled=0;
  partial_product->filled=0;
  partial_product->sign=0;

  for(i=0;i<num1->filled && k<=35;i++) {
    for(j=0;j<num2->filled;j++) {
      temp=carry+(unsigned long long int)num1->val[i]*(unsigned long long int)num2->val[j];
      prod=temp%1000000000;
      carry=temp/1000000000;
      partial_product->val[k]=prod;
      k++;
    }
    if(carry>0) {
      partial_product->val[k]=carry;
      k++;
      carry=0;
    }
    partial_product->filled=k;
    if(k>35 || compare(product,max)==-1) {
      free(product->val);
      product->val=NULL;
    }
    else {
      dummy=add(product,partial_product);
      product->filled=dummy->filled;
      for(int j=0;j<product->filled;j++) product->val[j]=dummy->val[j];
      free(dummy->val);
      free(dummy);
      st++;
      k=st;
      for(int j=0;j<k;j++) partial_product->val[j]=0;
    }
  }
  free(max->val);
  free(max);

  product->sign=(num1->sign)^(num2->sign);

  free(partial_product->val);
  free(partial_product);
  return product;
}
