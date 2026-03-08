#include "prog1lib/lib/base.h"
#include <assert.h>
#include <stdio.h>

/**
 * Zählt Sequenzen von mindestens drei identischen, aufeinanderfolgenden
 * Zeichen. Zeitkomplexität: O(n), da der String nur einmal durchlaufen wird.
 */
int count_triplets(const char *s) {
  int length = strlen(s);
  if (length < 3) {
    return 0;
  }

  int total_triplets = 0;
  int current_streak = 1;

  for (int i = 1; i < length; i++) {
    if (s[i] == s[i - 1]) {
      current_streak++;
      if (current_streak == 3) {
        total_triplets++;
      }
    } else {
      current_streak = 1;
    }
  }

  return total_triplets;
}

int main() {
  assert(count_triplets("aaabccdeee") == 2);
  assert(count_triplets("abc") == 0);
  assert(count_triplets("aaaaa") == 1);
  assert(count_triplets("") == 0);
  assert(count_triplets("111222333") == 3);
  assert(count_triplets("aaabb") == 1);

  return 0;
}
