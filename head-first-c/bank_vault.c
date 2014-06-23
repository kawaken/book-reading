#include <stdio.h>
#include <encrypt.h>
#include <checksum.h>

int main() {
  char s[] = "Speak friend and enter";
  encrypt(s);
  printf("'%s'に暗号化しました\n", s);
  printf("チェックサムは%iです\n", checksum(s));

  encrypt(s);
  printf("'%s'に複合化しました\n", s);
  printf("チェックサムは%iです\n", checksum(s));

  return 0;
}
