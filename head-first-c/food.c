#include <stdio.h>

int main() {
  char food[5];
  printf("好きな食べ物を入力して下さい:");
  fgets(food, sizeof(food), stdin);
  printf("好きな食べ物:%s\n", food);
}
