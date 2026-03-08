#include "prog1lib/lib/base.h"
#include <assert.h>
#include <stdbool.h>
#include <string.h>

bool is_digit(char c) { return (c >= '0' && c <= '9'); }

bool is_letter(char c) {
  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool has_digit_sandwich(const char *s) {
  char current;
  char last;
  char penultimate;
  if (strlen(s) < 3) {
    return false;
  }
  for (int i = 2; i < strlen(s); i++) {
    current = s[i];
    last = s[i - 1];
    penultimate = s[i - 2];
    if (is_letter(last)) {
      if ((is_digit(current) && is_digit(penultimate) &&
           current == penultimate)) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  printf("Teste has_digit_sandwich...\n");

  assert(has_digit_sandwich("x1a1y") == true);
  assert(has_digit_sandwich("9Z9") == true);
  assert(has_digit_sandwich("1a2") == false); // Unterschiedliche Ziffern
  assert(has_digit_sandwich("111") == false); // Mitte ist kein Buchstabe
  assert(has_digit_sandwich("a1a") == false); // Außen sind keine Ziffern
  assert(has_digit_sandwich("") == false);
  assert(has_digit_sandwich("5n5") == true);

  printf("Alle Tests bestanden, soerj!\n");
  return 0;
}
