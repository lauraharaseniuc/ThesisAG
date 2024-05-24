#include <stdio.h>
FILE* file_pointer;
int main()
{
  file_pointer = fopen("./traced_tests/9.out", "a");
  int x;
  fprintf(file_pointer, "%d ", 44);
  int n;
  fprintf(file_pointer, "%d ", 45);
  int m;
  fprintf(file_pointer, "%d ", 46);
  int a[101];
  fprintf(file_pointer, "%d ", 47);
  int b[101];
  fprintf(file_pointer, "%d ", 48);
  int v[201];
  fprintf(file_pointer, "%d ", 49);
  int k = 0;
  fprintf(file_pointer, "%d ", 50);
  scanf("%d%d", &x, &n);
  fprintf(file_pointer, "%d ", 51);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  scanf("%d", &m);
  fprintf(file_pointer, "%d ", 52);
  for (int i = 1; i <= m; i++)
    scanf("%d", &b[i]);

  int i = 1;
  fprintf(file_pointer, "%d ", 53);
  int j = 1;
  fprintf(file_pointer, "%d ", 54);
  while ((i <= n) && (j <= m))
  {
    fprintf(file_pointer, "%d ", 55);
    if (a[i] < b[j])
    {
      fprintf(file_pointer, "%d ", 56);
      if ((a[i] % x) == 0)
      {
        fprintf(file_pointer, "%d ", 57);
        k++;
        fprintf(file_pointer, "%d ", 58);
        v[k] = a[i];
        fprintf(file_pointer, "%d ", 59);
      }
      i++;
      fprintf(file_pointer, "%d ", 60);
    }
    else
      if (a[i] > b[j])
    {
      if ((b[j] % x) == 0)
      {
        k++;
        v[k] = b[j];
      }
    }
    else
    {
      i--;
      j++;
    }
  }

  while (i <= n)
  {
    fprintf(file_pointer, "%d ", 61);
    if ((a[i] % x) == 0)
    {
      fprintf(file_pointer, "%d ", 62);
      k++;
      fprintf(file_pointer, "%d ", 63);
      v[k] = b[i];
      fprintf(file_pointer, "%d ", 64);
    }
    i++;
    fprintf(file_pointer, "%d ", 65);
  }

  while (j <= m)
  {
    fprintf(file_pointer, "%d ", 66);
    if ((b[j] % x) == 0)
    {
      fprintf(file_pointer, "%d ", 67);
      k++;
      fprintf(file_pointer, "%d ", 68);
      v[k] = a[j];
      fprintf(file_pointer, "%d ", 69);
    }
  }

  for (int i = 1; i <= k; i++)
    printf("%d ", v[i]);

  return 0;
  fprintf(file_pointer, "%d ", 70);
}

