#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int LEN = 6;

int main(void) {
  char arr[LEN];
  strcpy(arr, "WORLD");

  printf("Forwards: %s\n", arr);
  printf("Backwards (for): ");
  for (int i = strlen(arr) - 1; i >= 0; i--) {
    printf("%c", arr[i]);
  }
  printf("\n");

  printf("Backwards (while): ");
  int index = strlen(arr) - 1;
  while (index >= 0) {
    printf("%c", arr[index]);
    index--;
  }
  printf("\n");

  printf("Backwards (do-while): ");
  int idx = strlen(arr) - 1;
  if (idx >= 0) {
    do {
      printf("%c", arr[idx]);
      idx--;
    } while (idx >= 0);
  }
  printf("\n");

  return 0;
}
