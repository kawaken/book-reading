#include <stdio.h>

int main() {
  char name[40];
  printf("名前を入力して下さい:");
  scanf("%39s", name);
  printf("%s\n", name);

  int age;
  printf("年齢を入力して下さい:");
  scanf("%i", &age);
  printf("%i\n", age);

  char first_name[20];
  char last_name[20];
  printf("名と姓を入力して下さい:");
  scanf("%19s %19s", first_name, last_name);
  printf("名: %s 姓: %s\n", first_name, last_name);
}
