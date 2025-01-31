#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "all.h"

int main() {
  int1024 num1,num2;
  printf("Enter a number: ");
  read(&num1);
  printf("Enter another number: ");
  read(&num2);

  printf("Their sum is ");
  int1024 *sum=add(&num1,&num2);
  print(sum);

  printf("\nTheir difference is ");
  int1024 *diff=subtract(&num1,&num2);
  print(diff);

  printf("\nTheir product is ");
  int1024* prod=multiply(&num1,&num2);
  print(prod);
  
  free(num1.val);
  free(num2.val);
  if(diff->val!=NULL) {
    free(diff->val);
  }
  if(sum->val!=NULL) {
    free(sum->val);
  }
  if(prod->val!=NULL) {
    free(prod->val);
  }
  free(diff);
  free(sum);
  free(prod);
}
