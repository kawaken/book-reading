#include <stdio.h>

int main() {
  int contestants[] = {1, 2, 3};
  int *choice = contestants;
  contestants[0] = 2;
  contestants[1] = contestants[2];
  contestants[2] = *choice;
  printf("出場者番号%iを選ぶわ\n", contestants[2]);
}
