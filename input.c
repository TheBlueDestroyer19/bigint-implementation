#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "all.h"
void reverse_str(char* str, int start, int end) {
  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
  }
}

void read(int1024* num) {
  char str[315];
  scanf("%s",str);
  int len=strlen(str);
  if(str[0]=='-') num->sign=1;
  else num->sign=0;
  num->val=(int*)malloc(sizeof(int)*35);
  if (num->sign == 1)
    reverse_str(str, 1, len - 1); 
  else
    reverse_str(str, 0, len - 1);

  int num1=0,p=0,j=0;
  int factor=1;
  for(int i=0;i<len;i++) {
    if(num->sign==1 && i==0) continue;
    num1=num1+(str[i]-'0')*factor;
    factor=factor*10;
    p++;
    if(p==9) {
        num->val[j]=num1;
        j++;
        p=0;
        factor=1;
        num1=0;
    }
  }
  if(num1>0) {
    num->val[j]=num1;
    j++;
    p=0;
    factor=1;
    num1=0;
  }
  num->filled=j;
}
