#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char *my_env[] = {"FOOD=coffee", NULL};
  if (execle("./coffee", "./coffee", "donuts", NULL, my_env) == -1) {
    fprintf(stderr, "注文できません:%s\n", strerror(errno));
    return 1;
  }
  return 0;
}
