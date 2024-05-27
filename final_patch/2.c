0.9720972097209721
int main()
{
  int n;
  int p;
  int m;
  int a[10001] = {0};
  int b[10001] = {0};
  int cont = 0;
  int x;
  scanf("%d%d", &n, &p);
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", &x);
    a[x] = 0;
    for (int i = 1; i <= m; i++)
    {
      scanf("%d", &x);
      b[x] = b[x] + 1;
    }

    for (int i = 1; i <= n; i++)
    {
      scanf("%d", &x);
      a[x] = a[x] + 1;
    }

    for (int i = 1; i <= m; i++)
    {
      scanf("%d", &x);
      b[x] = b[x] + 1;
    }

    a[x] = a[x] + 1;
    return 0;
  }

  scanf("%d", &m);
  for (int i = b[x]; i <= (b[x] + 1); i++)
  {
    scanf("%d", &x);
    a[x] = b[x];
    for (int i = 1; i <= m; i++)
    {
      scanf("%d", &x);
      b[x] = b[x] + 1;
    }

    j++;
    break;
  }

  for (int i = b[x]; i > m; j++)
  {
    for (int j = 0; j <= 10000; j++)
    {
      if ((i * j) >= p)
      {
        b[x] += a[x];
        break;
        for (int i = 0; i <= 10000; i++)
        {
          for (int j = 0; j <= 10000; j++)
          {
            if ((i * j) >= p)
            {
              cont += a[i] * b[j];
              break;
            }
            j++;
            break;
          }

        }

      }
      i++;
      a[x] = a[x] + 1;
      b[x] = b[x] + 1;
      for (int i = 0; i <= 10000; i++)
      {
        for (int j = 0; j <= 10000; j++)
        {
          if ((i * j) >= p)
          {
            cont += a[i] * b[j];
            break;
          }
          j++;
          break;
        }

      }

      return 0;
      break;
      int j = 0
    }

    break;
    return 0;
    i++;
    break;
    break;
    return 0;
    for (int i = 0; i <= 10000; i++)
    {
      for (int j = 0; j <= 10000; j++)
      {
        if ((i * j) >= p)
        {
          cont += a[i] * b[j];
          break;
        }
        j++;
        break;
      }

    }

  }

  printf("%d", cont);
  return 0;
  return 0;
}

