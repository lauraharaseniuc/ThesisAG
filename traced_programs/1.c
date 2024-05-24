#include <stdio.h>
FILE* file_pointer;
int main()
{
  file_pointer = fopen("./traced_tests/1.out", "a");
  int n;
  fprintf(file_pointer, "%d ", 13);
  int m;
  fprintf(file_pointer, "%d ", 14);
  int i;
  fprintf(file_pointer, "%d ", 15);
  int j;
  fprintf(file_pointer, "%d ", 16);
  int a[101][101];
  fprintf(file_pointer, "%d ", 17);
  int k;
  fprintf(file_pointer, "%d ", 18);
  int v[10001];
  fprintf(file_pointer, "%d ", 19);
  int p = 0;
  fprintf(file_pointer, "%d ", 20);
  scanf("%d", &n);
  fprintf(file_pointer, "%d ", 21);
  for (i = 1; i <= n; i++)
  {
    fprintf(file_pointer, "%d ", 22);
    for (j = 1; j <= n; j++)
    {
      fprintf(file_pointer, "%d ", 23);
      scanf("%d", &a[i][j]);
      fprintf(file_pointer, "%d ", 24);
    }

  }

  for (i = 1; i <= n; i++)
  {
    fprintf(file_pointer, "%d ", 25);
    if ((i % 2) == 0)
    {
      fprintf(file_pointer, "%d ", 26);
      for (j = i, k = 1; j >= 1; j--, k++)
      {
        fprintf(file_pointer, "%d ", 27);
        p++;
        fprintf(file_pointer, "%d ", 28);
        v[p] = a[j][k];
        fprintf(file_pointer, "%d ", 29);
      }

    }
    else
    {
      fprintf(file_pointer, "%d ", 30);
      for (j = i, k = 1; j >= 1; j--, k++)
      {
        fprintf(file_pointer, "%d ", 31);
        p++;
        fprintf(file_pointer, "%d ", 32);
        v[p] = a[k][j];
        fprintf(file_pointer, "%d ", 33);
      }

    }
  }

  for (j = 1; j <= (n - 1); j++)
  {
    fprintf(file_pointer, "%d ", 34);
    if ((((n % 2) == 1) && ((j % 2) == 0)) || (((n % 2) == 0) && ((j % 2) == 1)))
    {
      fprintf(file_pointer, "%d ", 35);
      for (i = j + 1, k = n; i <= n; i++, k--)
      {
        fprintf(file_pointer, "%d ", 36);
        p++;
        fprintf(file_pointer, "%d ", 37);
        v[p] = a[i][k];
        fprintf(file_pointer, "%d ", 38);
      }

    }
    else
    {
      fprintf(file_pointer, "%d ", 39);
      if ((((n % 2) == 0) && ((j % 2) == 0)) || (((n % 2) == 1) && ((j % 2) == 1)))
      {
        fprintf(file_pointer, "%d ", 40);
        for (i = n, k = j + 1; i >= (j + 1); i--, k++)
        {
          fprintf(file_pointer, "%d ", 41);
          p++;
          fprintf(file_pointer, "%d ", 42);
          v[p] = a[k][i];
          fprintf(file_pointer, "%d ", 43);
        }

      }
    }
  }

  for (int i = 1; i <= p; i++)
  {
    fprintf(file_pointer, "%d ", 44);
    printf("%d ", v[i]);
    fprintf(file_pointer, "%d ", 45);
  }

  return 0;
  fprintf(file_pointer, "%d ", 46);
}

