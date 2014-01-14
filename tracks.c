#include <stdio.h>

int main() {
  char tracks[][80] = {
    "I left my heart in Harvard Med School",
    "Newark, Newark - a wonderful town",
    "Dancing with a Dork",
    "From here to maternity",
    "The girl from Iwo Jima",
  };

  printf("%s\n", tracks[4]);
  printf("%c\n", tracks[4][6]);

  return 0;
}
