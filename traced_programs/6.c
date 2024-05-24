#include <stdio.h>
FILE* file_pointer;
int main()
{
  file_pointer = fopen("./traced_tests/6.out", "a");
  int n;
  fprintf(file_pointer, "%d ", 1);
  int v[101];
  fprintf(file_pointer, "%d ", 2);
  scanf("%d", &n);
  fprintf(file_pointer, "%d ", 3);
  for (int i = 1; i <= n; i++)
    scanf("%d", &v[i]);

  int ok = 1;
  fprintf(file_pointer, "%d ", 4);
  for (int i = 1; i <= n; i++)
  {
    fprintf(file_pointer, "%d ", 5);
    int x = v[i];
    fprintf(file_pointer, "%d ", 6);
    int nr_cif = 0;
    fprintf(file_pointer, "%d ", 7);
    if ((x >= 0) && (x <= 9))
      nr_cif = 1;
    if (x == 0)
      nr_cif = 1;
    while (x != 0)
    {
      fprintf(file_pointer, "%d ", 8);
      nr_cif++;
      fprintf(file_pointer, "%d ", 9);
      x = x / 10;
      fprintf(file_pointer, "%d ", 10);
    }

    if ((nr_cif % 2) == 1)
    {
      fprintf(file_pointer, "%d ", 11);
      ok = 1;
      fprintf(file_pointer, "%d ", 12);
    }
  }

  if (ok == 0)
    printf("DA");
  else
    printf("NU");
  return 0;
  fprintf(file_pointer, "%d ", 13);
}

