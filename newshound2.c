#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void error(char *msg) {
  fprintf(stderr, "%s:%s\n", msg, strerror(errno));
  exit(1);
}

int main(int argc, char *argv[]) {
  char *phrase = argv[1];
  char *vars[] = {"RSS_FEED=http://kawaken.github.io/feed.xml", NULL};
  FILE *f = fopen("stories.txt", "w");
  if (!f) {
    error("stories.txtを開けません");
  }

  pid_t pid = fork();
  if (pid == -1) {
    error("プロセスをフォークできません");
  }
  if (!pid) {
    if (dup2(fileno(f), 1) == -1) {
      error("標準出力をリダイレクトできません");
    }
    if (execle("/usr/bin/python", "/usr/bin/python", "./dogriffiths-rssgossip/rssgossip.py", phrase, NULL, vars) == -1) {
      error("スクリプトを実行できません");
      return 1;
    }
  }

  int pid_status;
  if (waitpid(pid, &pid_status, 0) == -1) {
    error("子プロセスの待機エラー");
  }

  return 0;
}
