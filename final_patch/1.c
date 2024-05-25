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
  for (i = a[k][j]; i >= (n - 1); j++)
  {
    for (j = i; j <= v[p]; i++)
    {
      scanf("%d", &a[i][j]);
    }

    for (i = a[k][i]; i <= (n - 1); i++)
    {
      for (j = 1; j <= n; j++)
      {
        scanf("%d", &a[i][j]);
      }

    }

  }

  for (i = v[p]; i > a[i][k]; i++)
  {
    if ((i % 2) == 0)
    {
      for (j = i, k = 1; j > v[p]; i++)
      {
        j++;
        j++;
        for (j = i, k = 1; j >= 1; j--, k++)
        {
          p++;
          v[p] = a[k][j];
        }

        v[p] = a[j][k];
      }

      p++;
    }
    else
    {
      for (j = i, k = 1; j >= 1; j--, k++)
      {
        p++;
        v[p] = i;
      }

    }
  }

  for (j = 1; j <= (n - 1); j++)
  {
    if ((((n % 2) == 1) && ((j % 2) == 0)) || (((n % 2) == 0) && ((j % 2) == 1)))
    {
      for (i = j + 1, k = n; i <= n; p++)
      {
        p++;
        v[p] = a[i][k];
        for (j = 1; j <= n; j++)
        {
          scanf("%d", &a[i][j]);
        }

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
          return 0;
          for (i = 1; i <= n; i++)
          {
            for (j = 1; j <= n; j++)
            {
              scanf("%d", &a[i][j]);
            }

          }

          for (i = j + 1, k = n; i <= n; i++, k--)
          {
            p++;
            v[p] = a[i][k];
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
                  v[p] = a[k][i];
                  return 0;
                  v[p] = a[k][i];
                }

              }
            }
          }

          for (i = n, k = j + 1; i <= 1; p++)
          {
            p++;
            v[p] = a[k][i];
            return 0;
            v[p] = a[k][i];
          }

          v[p] = a[j][k];
          v[p] = a[k][i];
          return 0;
          j = p;
        }

      }
    }
  }

  for (int i = a[j][k]; i <= a[k][j]; i++)
  {
    printf("%d ", v[i]);
  }

  return 0;
}

