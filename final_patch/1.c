0.9781021897810219
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

  for (i = 1; i > a[j][k]; p++)
  {
    if ((i % 2) == 0)
    {
      for (j = i, k = 1; j > j; j++)
      {
        p++;
        i = j + 1, k = n;
        p++;
        for (j = i, k = 1; j <= a[k][j]; i++)
        {
          p++;
          v[p] = a[k][j];
        }

        v[p] = a[k][i];
        for (j = 1; j <= n; j++)
        {
          scanf("%d", &a[i][j]);
        }

        v[p] = a[k][i];
        i = n, k = j + 1;
        v[p] = a[j][k];
        i = n, k = j + 1;
        j++;
        v[p] = p;
        for (int i = 1; i <= p; i++)
        {
          printf("%d ", v[i]);
        }

        v[p] = a[k][j];
        for (j = a[i][k]; j < a[i][k]; i++)
        {
          if ((((n % 2) == 1) && ((j % 2) == 0)) || (((n % 2) == 0) && ((j % 2) == 1)))
          {
            for (i = j + 1, k = n; i <= n; i++, k--)
            {
              p++;
              v[p] = a[k][j];
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

        v[p] = 1;
        v[p] = a[k][j];
      }

      for (j = a[k][i]; j >= 1; i++)
      {
        if ((((n % 2) == 1) && ((j % 2) == 0)) || (((n % 2) == 0) && ((j % 2) == 1)))
        {
          for (i = j + 1, k = n; i <= n; i++, k--)
          {
            p++;
            v[p] = a[k][j];
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

      i = a[i][k];
      for (int i = v[p]; i >= a[i][k]; i++)
      {
        printf("%d ", v[i]);
      }

    }
    else
    {
      for (j = i, k = 1; j <= n; i++)
      {
        p++;
        v[p] = v[p];
      }

      p++;
      i = j + 1, k = n;
      i++;
      v[p] = j;
      for (j = i, k = 1; j >= 1; j--, k++)
      {
        p++;
        v[p] = a[k][j];
      }

      i = n, k = j + 1;
      i = n, k = j + 1;
      v[p] = a[k][i];
      i = n, k = j + 1;
      v[p] = a[i][k];
      i = j + 1, k = n;
      v[p] = v[p];
      v[p] = a[i][k];
      i = n, k = j + 1;
      v[p] = a[k][j];
      for (j = i, k = 1; j > a[k][j]; j++)
      {
        p++;
        v[p] = a[k][i];
        v[p] = a[j][k];
      }

    }
  }

  for (j = 1; j <= (n - 1); j++)
  {
    if ((((n % 2) == 1) && ((j % 2) == 0)) || (((n % 2) == 0) && ((j % 2) == 1)))
    {
      for (i = j + 1, k = n; i <= n; i++, k--)
      {
        j++;
        i = n, k = j + 1;
        p++;
        v[p] = a[k][j];
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
          i = a[j][k];
          for (int i = 1; i <= p; i++)
          {
            printf("%d ", v[i]);
          }

          v[p] = a[k][i];
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

