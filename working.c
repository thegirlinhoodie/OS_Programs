#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count = 0;
void insertionsort(int *a, int n) {
    int i, j, value;
    for (i = 1; i < n; i++) {
        value = a[i];
        j = i - 1;
        printf("Inserting %d:\n", value);

        // Shift elements of a[0..i-1], that are greater than value,
        // to one position ahead of their current position
        while (j >= 0 && a[j] > value) {
            a[j + 1] = a[j];
            j--;
        }

        // Place value at its correct position
        a[j + 1] = value;

        // Print the array after each insertion
        printf("Array after inserting %d: ", value);
        for (int k = 0; k < n; k++) {
            printf("%d ", a[k]);
        }
        printf("\n");
    }
}

void plotter() {
  srand(time(NULL));
  int *a, n;
  FILE *f1, *f2, *f3;
  f1 = fopen("bb.txt", "a");
  f2 = fopen("bw.txt", "a");
  f3 = fopen("ba.txt", "a");
  n = 10;
  while (n <= 30000) {
    a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
      *(a + i) = n - i;
    count = 0;
    insertionsort(a, n);
    fprintf(f2, "%d\t%d\n", n, count);
    for (int i = 0; i < n; i++)
      *(a + i) = rand() % n;
    count = 0;
    insertionsort(a, n);
    fprintf(f3, "%d\t%d\n", n, count);
    for (int i = 0; i < n; i++)
      *(a + i) = i + 1;
    count = 0;
    insertionsort(a, n);
    fprintf(f1, "%d\t%d\n", n, count);
    if (n < 10000)
      n = n * 10;
    else
      n += 10000;
    free(a);
  }
  fclose(f1);
  fclose(f2);
  fclose(f3);
}
void tester() {
  int *a, n;
  printf("Enter no. of elements\n");
  scanf("%d", &n);
  a = (int *)malloc(sizeof(int) * n);
  printf("Enter elements of array\n");
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  printf("Before sorting:\n");
  for (int i = 0; i < n; i++)
    printf("%d\t", a[i]);
  printf("\n");
  insertionsort(a, n);
  printf("After sorting\n");
  for (int i = 0; i < n; i++)
    printf("%d\t", a[i]);
  printf("\n");
}
int main() {
  int ch;
  for (;;) {
    printf("Enter choice\n1.Tester\n2.Plotter\n0.Exit\n");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      tester();
      break;
    case 2:
      plotter();
      break;
    default:
      exit(0);
    }
  }
  return 0;
}