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

void open_url(char *url) {
  char launch[255];

  sprintf(launch, "cmd /c start %s", url);
  system(launch);

  sprintf(launch, "curl '%s' &", url);
  system(launch);

  sprintf(launch, "open '%s'", url);
  system(launch);

}

int main(int argc, char *argv[]) {
  char *phrase = argv[1];
  char *vars[] = {"RSS_FEED=http://kawaken.github.io/feed.xml", NULL};
  int fd[2];

  if (pipe(fd) == -1) {
    error("パイプを作成できません");
  }

  pid_t pid = fork();
  if (pid == -1) {
    error("プロセスをフォークできません");
  }
  if (!pid) {
    dup2(fd[1], 1);
    close(fd[0]);

    if (execle("/usr/bin/python", "/usr/bin/python", "./dogriffiths-rssgossip/rssgossip.py", "-u", phrase, NULL, vars) == -1) {
      error("スクリプトを実行できません");
      return 1;
    }
  }
  dup2(fd[0], 0);
  close(fd[1]);

  char line[255];
  while (fgets(line, 255, stdin)) {
    if (line[0] == '\t') {
      open_url(line + 1);
    }
  }
  return 0;
}
