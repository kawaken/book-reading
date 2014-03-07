#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  char *feeds[] = {"http://www.cnn.com/rss/celebs.xml",
                   "http://www.rollingstone.com/rock.xml",
                   "http://eonline.com/gossip.xml"};

  int times = 3;
  char *phrase = argv[1];
  int i;

  for (i = 0; i < times; i++) {
    char var[255];
    sprintf(var, "RSS_FEED=%s", feeds[i]);
    char *vars[] = {var, NULL};

    pid_t pid = fork();
    if (pid == -1) {
      fprintf(stderr, "プロセスをフォークできません:%s\n", strerror(errno));
      return 1;
    }

    if (!pid) {
      if (execle("/usr/bin/python", "/usr/bin/python", "./dogriffiths-rssgossip/rssgossip.py", phrase, NULL, vars) == -1) {
        fprintf(stderr, "スクリプトを実行できません:%s\n", strerror(errno));
        return 1;
      }
    }
  }

  return 0;
}
