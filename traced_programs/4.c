#include <stdio.h>
FILE* file_pointer;
int main()
{
  file_pointer = fopen("./traced_tests/4.out", "a");
  int n;
  fprintf(file_pointer, "%d ", 86);
  int v[201];
  fprintf(file_pointer, "%d ", 87);
  int cont = 0;
  fprintf(file_pointer, "%d ", 88);
  scanf("%d", &n);
  fprintf(file_pointer, "%d ", 89);
  for (int i = 1; i <= n; i++)
    scanf("%d", &v[i]);

  int dr;
  fprintf(file_pointer, "%d ", 90);
  int st;
  fprintf(file_pointer, "%d ", 91);
  dr = 1;
  fprintf(file_pointer, "%d ", 92);
  st = n;
  fprintf(file_pointer, "%d ", 93);
  while (dr < st)
  {
    fprintf(file_pointer, "%d ", 94);
    int a = v[dr];
    fprintf(file_pointer, "%d ", 95);
    int b = v[st];
    fprintf(file_pointer, "%d ", 96);
    while (a == b)
    {
      fprintf(file_pointer, "%d ", 97);
      if (a > b)
        b = b - a;
      else
        a = a - b;
    }

    if (a == 1)
      cont++;
    else
    {
      fprintf(file_pointer, "%d ", 98);
      dr++;
      fprintf(file_pointer, "%d ", 99);
      st--;
      fprintf(file_pointer, "%d ", 100);
    }
    dr++;
    fprintf(file_pointer, "%d ", 101);
    st--;
    fprintf(file_pointer, "%d ", 102);
  }

  printf("%d", cont);
  fprintf(file_pointer, "%d ", 103);
  return 0;
  fprintf(file_pointer, "%d ", 104);
}

