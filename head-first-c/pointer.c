#include <stdio.h>
#include <stdlib.h>

int y = 1;

int main() {
  int x = 4;

  printf("xの格納位置は%p\n", &x);
  printf("yの格納位置は%p\n", &y);

  return 0;
}
