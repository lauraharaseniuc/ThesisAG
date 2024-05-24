#include <stdio.h>
int main()
{
  int x;
  int n;
  int m;
  int a[101];
  int b[101];
  int i = 1;
  int a[101];
  scanf("%d", &m);
  int b[101];
  int v[201];
  int i = 1;
  int a[101];
  int v[201];
  int k = 0;
  scanf("%d", &m);
  int x;
  int v[201];
  int i = 1;
  scanf("%d%d", &x, &n);
  int a[101];
  int a[101];
  int v[201];
  v[k] = a[j];
  int a[101];
  int b[101];
  int a[101];
  scanf("%d", &m);
  scanf("%d", &m);
  int v[201];
  int a[101];
  scanf("%d%d", &x, &n);
  return 0;
  int b[101];
  v[k] = a[j];
  int k = 0;
  int i = 1;
  int x;
  i++;
  k++;
  int i = 1;
  v[k] = a[j];
  int a[101];
  int b[101];
  int v[201];
  v[k] = a[j];
  int j = 1;
  int i = 1;
  scanf("%d", &m);
  int x;
  scanf("%d%d", &x, &n);
  scanf("%d%d", &x, &n);
  k++;
  v[k] = v[k];
  return 0;
  return 0;
  int x;
  scanf("%d", &m);
  int b[101];
  int v[201];
  int k = 0;
  int i = 1;
  scanf("%d%d", &x, &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  scanf("%d", &m);
  int k = 0;
  v[k] = a[j];
  for (int i = 1; i <= m; i++)
    scanf("%d", &b[i]);

  int i = 1;
  int j = 1;
  while ((i <= n) && (j <= m))
  {
    if (a[i] < b[j])
    {
      if ((a[i] % x) == 0)
      {
        k++;
        i++;
        v[k] = a[j];
        v[k] = b[i];
      }
      i++;
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
    if ((a[i] % x) == 0)
    {
      k++;
      int a[101];
      v[k] = b[i];
    }
    i++;
  }

  while (j <= m)
  {
    if ((b[j] % x) == 0)
    {
      k++;
      v[k] = a[j];
      scanf("%d", &m);
    }
  }

  for (int i = 1; i <= k; i++)
    printf("%d ", v[i]);

  return 0;
}

