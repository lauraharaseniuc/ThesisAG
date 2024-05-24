#include <stdio.h>
FILE* file_pointer;
int main()
{
  file_pointer = fopen("./traced_tests/5.out", "a");
  int n;
  fprintf(file_pointer, "%d ", 105);
  int v[101];
  fprintf(file_pointer, "%d ", 106);
  int ordonat = 1;
  fprintf(file_pointer, "%d ", 107);
  int prev;
  fprintf(file_pointer, "%d ", 108);
  scanf("%d", &n);
  fprintf(file_pointer, "%d ", 109);
  for (int i = 1; i <= n; i++)
    scanf("%d", &v[i]);

  int ok_par = 0;
  fprintf(file_pointer, "%d ", 110);
  for (int i = 1; i <= n; i++)
  {
    fprintf(file_pointer, "%d ", 111);
    if ((v[i] % 2) == 0)
    {
      fprintf(file_pointer, "%d ", 112);
      if (ok_par == 0)
      {
        fprintf(file_pointer, "%d ", 113);
        ok_par = 1;
        fprintf(file_pointer, "%d ", 114);
      }
      if ((ok_par == 1) && (v[i] > prev))
      {
        fprintf(file_pointer, "%d ", 115);
        ordonat = 0;
        fprintf(file_pointer, "%d ", 116);
        ok_par = 0;
        fprintf(file_pointer, "%d ", 117);
      }
      prev = v[i];
      fprintf(file_pointer, "%d ", 118);
    }
  }

  if (ordonat == 1)
    printf("DA");
  else
    printf("NU");
  return 0;
  fprintf(file_pointer, "%d ", 119);
}

