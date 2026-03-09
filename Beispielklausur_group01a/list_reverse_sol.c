/*
Compile: gcc -I../prog1lib/lib -Wall list_reverse.c ../prog1lib/lib/base.c -o
list_reverse Run: ./list_reverse
*/

#include "../prog1lib/lib/base.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  double value;
  struct Node *next;
} Node;

/**
 * AUFGABENSTELLUNG:
 * Implementiere die Funktion list_reverse.
 * 1. Die Funktion soll die Reihenfolge aller Knoten in der Liste umkehren.
 * 2. Die Änderung muss direkt in den bestehenden Knoten (in-place) erfolgen.
 * Es darf kein neuer Speicher mit malloc alloziert werden.
 * 3. Gib den neuen Startknoten (Kopf) der umgedrehten Liste zurück.
 */

Node *list_reverse(Node *list) {
  // TODO: Implementiere die Logik hier
  if (list == NULL || list->next == NULL)
    return list;

  Node *rest = list_reverse(list->next);

  list->next->next = list;
  list->next = NULL;

  return rest;
}

// --- Hilfsfunktionen für den Test ---
Node *create_node(double val, Node *next) {
  Node *n = malloc(sizeof(Node));
  n->value = val;
  n->next = next;
  return n;
}

void print_list(Node *list) {
  while (list != NULL) {
    printf("%g -> ", list->value);
    list = list->next;
  }
  printf("NULL\n");
}

void free_list(Node *list) {
  while (list != NULL) {
    Node *temp = list;
    list = list->next;
    free(temp);
  }
}

void test(void) {
  // Baut die Liste: 1.0 -> 2.0 -> 3.0 -> 4.0 -> NULL
  Node *l = create_node(
      1.0, create_node(2.0, create_node(3.0, create_node(4.0, NULL))));

  printf("Vorher:  ");
  print_list(l);

  // Liste umdrehen
  l = list_reverse(l);

  printf("Nachher: ");
  print_list(l);
  // Erwartete Ausgabe: 4.0 -> 3.0 -> 2.0 -> 1.0 -> NULL

  free_list(l);
}

int main(void) {
  test();
  return 0;
}
