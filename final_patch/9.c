0.997698504027618
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
        v[k] = a[j];
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
      v[k] = b[i];
    }
    i++;
  }

  while (j <= m)
  {
    if ((b[j] % x) == 0)
    {
      i++;
      v[k] = a[j];
    }
  }

  for (int i = 1; i <= k; i++)
    printf("%d ", v[i]);

  return 0;
}

