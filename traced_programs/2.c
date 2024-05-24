#include <stdio.h>
FILE* file_pointer;
int main()
{
  file_pointer = fopen("./traced_tests/2.out", "a");
  int n;
  fprintf(file_pointer, "%d ", 47);
  int p;
  fprintf(file_pointer, "%d ", 48);
  int m;
  fprintf(file_pointer, "%d ", 49);
  int a[10001] = {0};
  fprintf(file_pointer, "%d ", 50);
  int b[10001] = {0};
  fprintf(file_pointer, "%d ", 51);
  int cont = 0;
  fprintf(file_pointer, "%d ", 52);
  int x;
  fprintf(file_pointer, "%d ", 53);
  scanf("%d%d", &n, &p);
  fprintf(file_pointer, "%d ", 54);
  for (int i = 1; i <= n; i++)
  {
    fprintf(file_pointer, "%d ", 55);
    scanf("%d", &x);
    fprintf(file_pointer, "%d ", 56);
    a[x] = a[x] + 1;
    fprintf(file_pointer, "%d ", 57);
  }

  scanf("%d", &m);
  fprintf(file_pointer, "%d ", 58);
  for (int i = 1; i <= m; i++)
  {
    fprintf(file_pointer, "%d ", 59);
    scanf("%d", &x);
    fprintf(file_pointer, "%d ", 60);
    b[x] = b[x] + 1;
    fprintf(file_pointer, "%d ", 61);
  }

  for (int i = 0; i <= 10000; i++)
  {
    fprintf(file_pointer, "%d ", 62);
    for (int j = 0; j <= 10000; j++)
    {
      fprintf(file_pointer, "%d ", 63);
      if ((i * j) >= p)
      {
        fprintf(file_pointer, "%d ", 64);
        cont += a[i] * b[j];
        fprintf(file_pointer, "%d ", 65);
        break;
        fprintf(file_pointer, "%d ", 66);
      }
      j++;
      fprintf(file_pointer, "%d ", 67);
    }

  }

  printf("%d", cont);
  fprintf(file_pointer, "%d ", 68);
  return 0;
  fprintf(file_pointer, "%d ", 69);
}

