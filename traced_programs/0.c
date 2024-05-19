#include <stdio.h>
FILE* file_pointer;
int main()
{
  file_pointer = fopen("./traced_tests/0.out", "a");
  int n;
  fprintf(file_pointer, "%d ", 1);
  int v[1001];
  fprintf(file_pointer, "%d ", 2);
  int k;
  fprintf(file_pointer, "%d ", 3);
  scanf("%d%d", &n, &k);
  fprintf(file_pointer, "%d ", 4);
  for (int i = 1; i <= n; i++)
  {
    fprintf(file_pointer, "%d ", 5);
    scanf("%d", &v[i]);
    fprintf(file_pointer, "%d ", 6);
  }

  for (int i = n - 1; i >= k; i--)
  {
    fprintf(file_pointer, "%d ", 7);
    v[i] = v[i + 1];
    fprintf(file_pointer, "%d ", 8);
  }

  n--;
  fprintf(file_pointer, "%d ", 9);
  for (int i = 1; i <= n; i++)
  {
    fprintf(file_pointer, "%d ", 10);
    printf("%d ", v[i]);
    fprintf(file_pointer, "%d ", 11);
  }

  return 0;
  fprintf(file_pointer, "%d ", 12);
}

