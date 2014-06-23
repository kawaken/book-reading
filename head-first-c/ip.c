#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main() {
  if (execl("/sbin/ifconfig", "/sbin/ifconfig", NULL) == -1) {
    if (execlp("ipconfig", "ipconfig", NULL) == -1) {
      fprintf(stderr, "ipconfigを実行できません:%s", strerror(errno));
    }
  }
  return 0;
}
