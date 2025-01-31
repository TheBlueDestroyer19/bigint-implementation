#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "all.h"
void reverse(char* str, int start, int end) {
  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
  }
}

int1024* maxcalc() {
  char str[315]="179769313486231590772930519078902473361797697894230657273430081157732675805500963132708477322407536021120113879871393357658789768814416622492847430639474124377767893424865485276302219601246094119453082952085005768838150682342462881473913110540827237163350510684586298239947245938479716304835356329624224137216";
  int len=strlen(str);
  int1024* max=(int1024*)malloc(sizeof(int1024));
  max->val=(int*)malloc(sizeof(int)*35);
  max->sign=0;
  reverse(str, 0, len - 1);
  int num1=0,p=0,j=0;
  int factor=1;
  for(int i=0;i<len;i++) {
    if(max->sign==1 && i==0) continue;
    num1=num1+(str[i]-'0')*factor;
    factor=factor*10;
    p++;
    if(p==9) {
        max->val[j]=num1;
        j++;
        p=0;
        factor=1;
        num1=0;
    }
  }
  if(num1>0) {
    max->val[j]=num1;
    j++;
    p=0;
    factor=1;
    num1=0;
  }
  max->filled=j;
  return max;
}

