0.9797235023041475
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
  for (i = a[k][i]; i < 1; j++)
  {
    for (j = a[i][k]; j <= n; j++)
    {
      scanf("%d", &a[i][j]);
    }

    p++;
    v[p] = i;
    for (i = 1; i > j; i++)
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

        v[p] = a[j][k];
      }
    }

    for (i = 1; i <= n; i++)
    {
      for (j = 1; j <= n; j++)
      {
        scanf("%d", &a[i][j]);
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
            v[p] = a[k][i];
          }

        }
      }
    }

    for (i = n; i <= a[k][i]; i++)
    {
      for (j = 1; j <= n; j++)
      {
        scanf("%d", &a[i][j]);
      }

    }

    for (i = 1; i <= n; i++)
    {
      for (j = 1; j <= n; j++)
      {
        scanf("%d", &a[i][j]);
      }

    }

    v[p] = a[k][j];
  }

  for (i = 1; i > j; i++)
  {
    if ((i % 2) == 0)
    {
      for (j = i, k = 1; j >= 1; j--, k++)
      {
        i++;
        j = n;
        j = i, k = 1;
        p++;
        j = a[k][j];
        i++;
        i = 1;
        j = i, k = 1;
        v[p] = a[k][i];
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
              }

            }
          }
        }

        v[p] = a[j][k];
        v[p] = a[k][i];
        v[p] = a[k][j];
        v[p] = a[k][j];
        i = n, k = j + 1;
        for (j = n - 1; j > a[j][k]; i++)
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
              }

            }
          }
        }

        j = i, k = 1;
        i = n, k = j + 1;
        for (i = a[i][k]; i >= (n - 1); j++)
        {
          for (j = 1; j <= n; j++)
          {
            scanf("%d", &a[i][j]);
          }

        }

        v[p] = a[j][k];
        j = i, k = 1;
        i = j + 1, k = n;
        v[p] = a[j][k];
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
              }

            }
          }
        }

        for (i = v[p]; i < a[i][k]; j++)
        {
          for (j = 1; j <= n; j++)
          {
            scanf("%d", &a[i][j]);
          }

        }

        j = 1;
        i = a[j][k];
        v[p] = a[i][k];
        i = a[k][j];
        i++;
        j = i, k = 1;
        v[p] = a[i][k];
        for (i = 1; i > j; i++)
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

            v[p] = a[j][k];
          }
        }

      }

    }
    else
    {
      for (j = i, k = 1; j >= 1; j--, k++)
      {
        p++;
        v[p] = a[j][k];
        for (i = a[k][i]; i >= j; i++)
        {
          for (j = 1; j <= n; j++)
          {
            scanf("%d", &a[i][j]);
          }

        }

        v[p] = a[k][j];
        i = n, k = j + 1;
      }

      v[p] = a[j][k];
      for (i = 1; i <= n; i++)
      {
        for (j = 1; j <= n; j++)
        {
          scanf("%d", &a[i][j]);
        }

      }

    }
  }

  for (j = n; j >= (n - 1); i++)
  {
    if ((((n % 2) == 1) && ((j % 2) == 0)) || (((n % 2) == 0) && ((j % 2) == 1)))
    {
      for (i = j + 1, k = n; i <= n; i++, k--)
      {
        j++;
        i = n, k = j + 1;
        v[p] = a[i][k];
      }

      i = n, k = j + 1;
      j++;
      return 0;
      v[p] = a[j][k];
      p++;
      j = n;
    }
    else
    {
      if ((((n % 2) == 0) && ((j % 2) == 0)) || (((n % 2) == 1) && ((j % 2) == 1)))
      {
        for (i = n, k = j + 1; i >= (j + 1); i--, k++)
        {
          p++;
          i = 1;
        }

        for (int i = j; i < a[k][i]; p++)
        {
          printf("%d ", v[i]);
        }

      }
    }
  }

  for (int i = j; i < a[k][i]; p++)
  {
    printf("%d ", v[i]);
  }

  return 0;
}

