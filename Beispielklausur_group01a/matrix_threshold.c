/*
Compile: gcc -I../prog1lib/lib -Wall matrix_threshold.c ../prog1lib/lib/base.c
-o matrix_threshold Run: ./matrix_threshold
*/

#include "../prog1lib/lib/base.h"
#include <math.h>
#include <stdio.h>

typedef struct {
  double *data;
  int rows, cols;
} Matrix;

/**
 * AUFGABENSTELLUNG:
 * Implementiere die Funktion matrix_threshold.
 * * 1. Die Funktion soll die Matrix 'm' direkt (in-place) verändern.
 * 2. Jedes Element in m.data, das STRENG GRÖSSER als 'threshold' ist,
 * soll auf 1.0 gesetzt werden.
 * 3. Alle anderen Elemente (kleiner oder gleich threshold)
 * sollen auf 0.0 gesetzt werden.
 * 4. Nutze eine Schleife, um alle m.rows * m.cols Elemente zu verarbeiten.
 */
void matrix_threshold(Matrix m, double threshold) {
  // Sicherheitscheck: Falls kein Speicher da ist, brich ab.
  if (m.data == NULL)
    return;

  // TODO: Implementiere hier die Logik
  // Tipp: Da du nicht auf Nachbarelemente zugreifen musst,
  // reicht eine einfache for-Schleife von 0 bis (m.rows * m.cols).
  for (int i = 0; i < (m.cols * m.rows); i++) {
    if (m.data[i] > threshold) {
      m.data[i] = 1.0;
    } else {
      m.data[i] = 0.0;
    }
  }
}

// Hilfsfunktion zum Erstellen einer Matrix
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
  double v[] = {0.5, 1.2, 2.0, 0.8};
  Matrix m = create_matrix(2, 2, v);

  printf("Vor Threshold (Limit 1.0):\n");
  // Matrix sieht so aus:
  // 0.5  1.2
  // 2.0  0.8

  matrix_threshold(m, 1.0);

  printf("Nach Threshold:\n");
  for (int i = 0; i < 4; i++) {
    printf("%g ", m.data[i]);
    if (i == 1)
      printf("\n");
  }
  printf("\n");

  // Überprüfung der Ergebnisse
  if (fabs(m.data[0] - 0.0) < 1e-9 && fabs(m.data[1] - 1.0) < 1e-9) {
    printf("Test bestanden, soerj!\n");
  } else {
    printf("Test fehlgeschlagen.\n");
  }

  free(m.data);
}

int main(void) {
  test();
  return 0;
}
