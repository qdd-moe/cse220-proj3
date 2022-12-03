// Yiyuan Luo on Nov 08, 2022

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "libsais.c"

int main(int argc, char **argv) {
  int n;
  int32_t *s;
  int32_t *sa;

  sscanf(argv[1], "%d", &n);

  s = (int32_t *)malloc(n * sizeof(int32_t));
  sa = (int32_t *)malloc(n * sizeof(int32_t));

  if (s && sa) {
    srand(time(0));
    
    while (1) {

      for (int i = 0; i < n; i++) {
        s[i] = rand() & 0x1ffffff;
      }

      libsais_int(s, sa, n, 1 << 25, 0);

      printf("%d\n", sa[0]);
    }

    free(s);
    free(sa);
  }
  return 0;
}
