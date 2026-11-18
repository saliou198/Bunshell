#include <stdio.h>
#include <stdlib.h>
#define LSH_RL_BUFSIZE

char *lsh_read_line() {
  int bufsize = LSH_RL_BUFSIZE;
  int position = 0;
  char *buffer = malloc(sizeof(char) * bufsize);
  int c;
  if (!buffer) {
    printf("Buffer size too fkking much bra \n");
    exit(EXIT_FAILURE);
  }
  // read line or smth i luv doing weird ass comments
  while (1) {
    c = getchar();
    if (c = EOF || c == "\n") {
      buffer[position] = "\0";
      return buffer;
    } else {
      buffer[position] = c;
    }
    position++;
    // if buffer finish or smth like that realloc
    if (position >= bufsize) {
      bufsize += LSH_RL_BUFSIZE;
      buffer = realloc(buffer, bufsize);
      if (!buffer) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}
void lsh_loop(void) {
  char *line;
  char **args;
  int status;

  do {
    printf("> ");
    line = lsh_read_line();
    args = lsh_split_line(line);
    status = lsh_execute(args);

    free(line);
    free(args);
  } while (status);
}

int main(int argc, char **argv) {
  // Load config files, if any.

  // Run command loop.
  lsh_loop();

  // Perform any shutdown/cleanup.

  return EXIT_SUCCESS;
}
