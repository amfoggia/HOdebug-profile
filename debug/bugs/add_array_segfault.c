#include <stdio.h>
#include <stdlib.h>
int add_array(int *a, int *b, int n){
  int sum = 0;
  int i = 0;
  for (i = 0; i < n; i++) {
    sum += abs(a[i]);
    sum += abs(b[i]);
  };
  return sum;
}

int main(int argc, char **argv) {
  int *a, *b;
  int n = 3;
  int i, sum;
  a = malloc(3*sizeof(int));
  b = malloc(3*sizeof(int)); // Esta es la forma de allocar un pointer
  for (i = 0; i < n; i++) {
    a[i] = i;
    b[i] = i;
  }
  sum = add_array(a, b, 3);
  printf("The addition is %d\n", sum);
  return 0;
}
