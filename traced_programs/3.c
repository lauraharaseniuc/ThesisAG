#include <stdio.h>
FILE* file_pointer;
int main()
{
  file_pointer = fopen("./traced_tests/3.out", "a");
  int v[1001];
  fprintf(file_pointer, "%d ", 70);
  int n;
  fprintf(file_pointer, "%d ", 71);
  int poz1 = -1;
  fprintf(file_pointer, "%d ", 72);
  int s = 0;
  fprintf(file_pointer, "%d ", 73);
  int poz2 = -2;
  fprintf(file_pointer, "%d ", 74);
  scanf("%d", &n);
  fprintf(file_pointer, "%d ", 75);
  for (int i = 1; i <= n; i++)
    scanf("%d", &v[i]);

  for (int i = 1; i <= n; i++)
  {
    fprintf(file_pointer, "%d ", 76);
    if ((i % 2) == 0)
    {
      fprintf(file_pointer, "%d ", 77);
      poz1 = i;
      fprintf(file_pointer, "%d ", 78);
      break;
      fprintf(file_pointer, "%d ", 79);
    }
  }

  for (int i = n; i >= 1; i--)
  {
    fprintf(file_pointer, "%d ", 80);
    if ((v[i] % 2) == 0)
    {
      fprintf(file_pointer, "%d ", 81);
      poz2 = i;
      fprintf(file_pointer, "%d ", 82);
    }
  }

  for (int i = poz1; i <= poz2; i++)
  {
    fprintf(file_pointer, "%d ", 83);
    s += v[i];
    fprintf(file_pointer, "%d ", 84);
  }

  if (poz1 == (-1))
    printf("NU EXISTA");
  else
    printf("%d", s);
  return 0;
  fprintf(file_pointer, "%d ", 85);
}

