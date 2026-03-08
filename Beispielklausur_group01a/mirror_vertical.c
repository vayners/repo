#include "../prog1lib/lib/base.h"
#include <math.h>
#include <stdio.h>

typedef struct {
  double *data;
  int rows, cols;
} Matrix;

void free_matrix(Matrix m) {
  if (m.data != NULL) {
    free(m.data);
  }
}

// Erzeugt eine neue Matrix, die vertikal gespiegelt ist (oben nach unten).
Matrix mirror_vertical(Matrix m) {
  Matrix t;
  t.rows = m.rows;
  t.cols = m.cols;

  // Speicher reservieren
  t.data = malloc(t.rows * t.cols * sizeof(double));
  if (t.data == NULL) {
    return t;
  }
  int new_y;
  for (int y = 0; y < m.rows; y++) {
    new_y = m.rows - 1 - y;
    for (int x = 0; x < m.cols; x++) {
      t.data[new_y * t.cols + x] = m.data[y * m.cols + x];
    }
  }
  return t;
}

void print_matrix(Matrix m) {
  int i = 0;
  for (int y = 0; y < m.rows; y++) {
    for (int x = 0; x < m.cols; x++) {
      printf("%g ", m.data[i++]);
    }
    printf("\n");
  }
  printf("\n");
}

void f_test_equal_matrix(int line, Matrix a, Matrix b) {
  if (a.rows != b.rows || a.cols != b.cols) {
    fprintf(stderr, "Line %d: Test failed. Dimensions not equal.\n", line);
    return;
  }
  for (int i = 0; i < a.rows * a.cols; i++) {
    if (fabs(a.data[i] - b.data[i]) > 1e-10) {
      fprintf(stderr, "Line %d: Test failed at index %d.\n", line, i);
      return;
    }
  }
  printf("Test in line %d passed!\n", line);
}

#define test_equal_matrix(actual, expected)                                    \
  f_test_equal_matrix(__LINE__, actual, expected)

void test(void) {
  // Erstelle m so, wie es die Library erwartet (auf dem Heap)
  Matrix m;
  m.rows = 2;
  m.cols = 3;
  m.data = malloc(m.rows * m.cols * sizeof(double));

  // Daten manuell füllen
  double values[] = {1, 2, 3, 4, 5, 6};
  for (int i = 0; i < 6; i++)
    m.data[i] = values[i];

  // Erwartete Matrix ebenso auf dem Heap
  Matrix expected;
  expected.rows = 2;
  expected.cols = 3;
  expected.data = malloc(expected.rows * expected.cols * sizeof(double));
  double e_values[] = {4, 5, 6, 1, 2, 3};
  for (int i = 0; i < 6; i++)
    expected.data[i] = e_values[i];

  printf("Original Matrix:\n");
  print_matrix(m);

  Matrix result = mirror_vertical(m);

  printf("Vertikal gespiegelte Matrix:\n");
  print_matrix(result);

  test_equal_matrix(result, expected);

  // Jetzt kannst du ALLES sauber freigeben
  free_matrix(m);
  free_matrix(result);
  free_matrix(expected);
}

int main(void) {
  test();
  return 0;
}
