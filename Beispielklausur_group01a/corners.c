/*
Compile: gcc -I../prog1lib/lib -Wall corners.c ../prog1lib/lib/base.c -o corners
matrix_corners Run: ./corners
*/

#include "../prog1lib/lib/base.h"
#include <stdio.h>

typedef struct {
  double *data;
  int rows, cols;
} Matrix;

// Berechnet die Summe der vier Eck-Elemente.
double matrix_corners_sum(Matrix m) {
  if (m.data == NULL || m.rows <= 0 || m.cols <= 0)
    return 0.0;

  // TODO: Berechne die Summe aus:
  // oben-links, oben-rechts, unten-links, unten-rechts
  double a, b, c, d;
  a = m.data[0];
  b = m.data[m.cols - 1];
  c = m.data[(m.rows - 1) * m.cols];
  d = m.data[m.cols * m.rows - 1];

  return (a + b + c + d);
}

// Hilfsfunktion zum Erstellen einer Matrix (wie in deinem Test-Code)
Matrix create_matrix(int rows, int cols, double values[]) {
  Matrix m;
  m.rows = rows;
  m.cols = cols;
  m.data = malloc(rows * cols * sizeof(double));
  for (int i = 0; i < rows * cols; i++)
    m.data[i] = values[i];
  return m;
}

void test(void) {
  // Test 1: 3x3 Matrix
  double v1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  Matrix m1 = create_matrix(3, 3, v1);
  // Ecken: 1, 3, 7, 9 -> Summe: 20
  printf("Test 1 (3x3): Erhalten %g (erwartet 20)\n", matrix_corners_sum(m1));

  // Test 2: 2x2 Matrix
  double v2[] = {1.5, 2.5, 3.5, 4.5};
  Matrix m2 = create_matrix(2, 2, v2);
  // Ecken: 1.5, 2.5, 3.5, 4.5 -> Summe: 12
  printf("Test 2 (2x2): Erhalten %g (erwartet 12)\n", matrix_corners_sum(m2));

  // Aufräumen
  free(m1.data);
  free(m2.data);
}

int main(void) {
  test();
  return 0;
}
