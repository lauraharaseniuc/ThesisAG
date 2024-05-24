#include <stdio.h>
FILE* file_pointer;
int main()
{
  file_pointer = fopen("./traced_tests/7.out", "a");
  int n;
  fprintf(file_pointer, "%d ", 14);
  int v[1001];
  fprintf(file_pointer, "%d ", 15);
  scanf("%d", &n);
  fprintf(file_pointer, "%d ", 16);
  for (int i = 1; i <= n; i++)
    scanf("%d", &v[i]);

  int minim = v[1];
  fprintf(file_pointer, "%d ", 17);
  for (int i = 1; i <= n; i++)
    if (v[i] < minim)
    minim = v[i];

  int i = 1;
  fprintf(file_pointer, "%d ", 18);
  while (i <= n)
  {
    fprintf(file_pointer, "%d ", 19);
    if (v[i] == minim)
    {
      fprintf(file_pointer, "%d ", 20);
      v[n] = v[n + 1];
      fprintf(file_pointer, "%d ", 21);
      for (int k = i; k <= n; k++)
      {
        fprintf(file_pointer, "%d ", 22);
        v[k] = v[k + 1];
        fprintf(file_pointer, "%d ", 23);
      }

      n--;
      fprintf(file_pointer, "%d ", 24);
    }
    i++;
    fprintf(file_pointer, "%d ", 25);
  }

  for (int i = 1; i <= n; i++)
    printf("%d ", v[i]);

  return 0;
  fprintf(file_pointer, "%d ", 26);
}

