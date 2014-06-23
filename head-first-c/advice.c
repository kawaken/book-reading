#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main() {
  char *advice[] = {
    "食べる量を減らしなさい\r\n",
    "タイトなジーンズにしなさい。太って見えることはありません。\r\n",
    "一言：不適切\r\n",
    "今日だけは正直になりなさい。「本当に」思っていることを上司に言いなさい\r\n",
    "そのヘアスタイルは考え直した方がいいでしょう\r\n"
  };

  int listener_d = socket(PF_INET, SOCK_STREAM, 0);
  int reuse = 1;
  if (setsockopt(listener_d, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int)) == -1) {
    error("ソケットに再利用オプションを設定できません");
  }
  
  struct sockaddr_in name;
  name.sin_family = PF_INET;
  name.sin_port = (in_port_t)htons(3000);
  name.sin_addr.s_addr = htonl(INADDR_ANY);

  if (bind(listener_d, (struct sockaddr *)&name, sizeof(name)) == -1) {
    error("ポートをバインドできません");
  }
  if (listen(listener_d, 10) == -1) {
    error("接続待ちできません");
  }

  puts("接続を待っています");

  while(1) {
    struct sockaddr_storage client_addr;
    unsigned int address_size = sizeof(client_addr);
    int connect_d = accept(listener_d, (struct sockaddr *)&client_addr, &address_size);
    if (connect_d == -1) {
      error("第2のソケットを開けません");
    }

    char *msg = advice[rand() % 5];
    if (send(connect_d, msg, strlen(msg), 0) == -1) {
      error("send");
    }

    close(connect_d);
  }

  return 0;
}
