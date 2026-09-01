#include <ctype.h>
#include <stdio.h>

int traduz(char c) {
    if (c >= '0' && c <= '9') 
        return c - '0';
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 10;
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 10;
    return -1;
}

int string2num (char *s, int b) {
  int a = 0;
  for (; *s; s++)
    a = a*b + traduz(*s);
  return a;
}

int main (void) {
  printf("%d\n", string2num("1a", 16));
  printf("%d\n", string2num("a09b", 16));
  printf("%d\n", string2num("z09b", 36));
  return 0;
}

