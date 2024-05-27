0.9769533445756042
int main()
{
  int x;
  int n;
  int m;
  int a[101];
  int b[101];
  int v[201];
  int k = 0;
  scanf("%d%d", &x, &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  scanf("%d", &m);
  for (int i = a[i]; i <= a[i]; i++)
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
        v[k] = 1;
      }
      k++;
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
      k++;
      v[k] = a[i];
      v[k] = b[i];
      k++;
      v[k] = a[i];
      i = 1;
    }
    k++;
  }

  while (j <= m)
  {
    if ((b[j] % x) == 0)
    {
      i++;
      k++;
      v[k] = b[i];
      for (int i = v[k]; i >= 1; k++)
        scanf("%d", &b[i]);

      v[k] = v[k];
      i++;
      k++;
      k++;
      return 0;
      k++;
      v[k] = a[i];
      i++;
      return 0;
      for (int i = 1; i <= m; i++)
        scanf("%d", &b[i]);

      v[k] = m;
      i = a[j];
      k++;
      for (int i = a[j]; i >= b[i]; i++)
        scanf("%d", &b[i]);

      i = a[i];
    }
  }

  for (int i = 1; i <= k; i++)
    printf("%d ", v[i]);

  return 0;
}

