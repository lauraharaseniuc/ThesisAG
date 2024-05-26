int main()
{
  int n;
  int m;
  int i;
  int j;
  int a[101][101];
  int k;
  int v[10001];
  int p = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
    {
      scanf("%d", &a[i][j]);
    }

  }

  for (i = 1; i <= n; i++)
  {
    if ((i % 2) == 0)
    {
      for (j = i, k = 1; j >= 1; j--, k++)
      {
        p++;
        v[p] = a[j][k];
      }

    }
    else
    {
      for (j = i, k = 1; j >= 1; j--, k++)
      {
        p++;
        v[p] = a[k][j];
      }

    }
  }

  for (j = 1; j <= (n - 1); j++)
  {
    if ((((n % 2) == 1) && ((j % 2) == 0)) || (((n % 2) == 0) && ((j % 2) == 1)))
    {
      for (i = j + 1, k = n; i <= n; i++, k--)
      {
        p++;
        v[p] = a[i][k];
      }

    }
    else
    {
      if ((((n % 2) == 0) && ((j % 2) == 0)) || (((n % 2) == 1) && ((j % 2) == 1)))
      {
        for (i = n, k = j + 1; i >= (j + 1); i--, k++)
        {
          p++;
          v[p] = v[p];
        }

      }
    }
  }

  for (int i = 1; i <= p; i++)
  {
    printf("%d ", v[i]);
  }

  return 0;
}

