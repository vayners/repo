#include "prog1lib/lib/base.h"
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

/**
 * Prüft, ob der String eine Sequenz von 3 streng absteigenden Ziffern enthält.
 * Beispiel: "abc987x" -> true, "123" -> false.
 * * Regeln laut Klausurvorgabe:
 * - Nur strlen und selbst definierte Hilfsfunktionen erlaubt.
 * - Eingabestring darf nicht verändert werden.
 */

bool isDigit(char c) {
  if (c >= '0' && c <= '9') {
    return true;
  }
  return false;
}

bool has_3_descending_digits(const char *s) {
  if (strlen(s) < 3)
    return false;

  int counter = 1;
  for (int i = 1; i < strlen(s); i++) {
    char last = s[i - 1];
    char current = s[i];
    if (isDigit(last) && isDigit(current)) {
      if (last == current + 1) {
        counter++;
        if (counter == 3) {
          return true;
        }
      }
    }
  }
  return false;
}

int main() {
  printf("Teste has_3_descending_digits...\n");

  assert(has_3_descending_digits("abc987x") == true);
  assert(has_3_descending_digits("321") == true);
  assert(has_3_descending_digits("986") == false);
  assert(has_3_descending_digits("123") == false);
  assert(has_3_descending_digits("a210b") == true);
  assert(has_3_descending_digits("43") == false);
  assert(has_3_descending_digits("") == false);

  printf("Alle Tests bestanden, soerj!\n");
  return 0;
}
