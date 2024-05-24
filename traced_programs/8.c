#include <stdio.h>
FILE* file_pointer;
int main()
{
  file_pointer = fopen("./traced_tests/8.out", "a");
  int n;
  fprintf(file_pointer, "%d ", 27);
  int s;
  fprintf(file_pointer, "%d ", 28);
  int v[101];
  fprintf(file_pointer, "%d ", 29);
  scanf("%d%d", &n, &s);
  fprintf(file_pointer, "%d ", 30);
  for (int i = 1; i <= n; i++)
    scanf("%d", &v[i]);

  for (int i = 1; i <= n; i++)
  {
    fprintf(file_pointer, "%d ", 31);
    int si = 0;
    fprintf(file_pointer, "%d ", 32);
    int j;
    fprintf(file_pointer, "%d ", 33);
    j = 1;
    fprintf(file_pointer, "%d ", 34);
    while ((j <= n) && (si <= s))
    {
      fprintf(file_pointer, "%d ", 35);
      si = si + v[j];
      fprintf(file_pointer, "%d ", 36);
      j++;
      fprintf(file_pointer, "%d ", 37);
      if (v[i] > si)
        break;
    }

    j++;
    fprintf(file_pointer, "%d ", 38);
    si = si - v[j - 1];
    fprintf(file_pointer, "%d ", 39);
    if (si == s)
    {
      fprintf(file_pointer, "%d ", 40);
      printf("%d %d", i, j - 2);
      fprintf(file_pointer, "%d ", 41);
    }
  }

  printf("0 0");
  fprintf(file_pointer, "%d ", 42);
  return 0;
  fprintf(file_pointer, "%d ", 43);
}

