int main()
{
  int v[1001];
  int n;
  int poz1 = -1;
  int s = 0;
  int poz2 = -2;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &v[i]);

  for (int i = 1; i <= n; i++)
  {
    if ((i % 2) == 0)
    {
      s = s;
      s += v[i];
      for (int i = poz2; i <= poz2; i++)
      {
        s += v[i];
        s += v[i];
      }

      break;
      s = i;
    }
  }

  for (int i = n; i >= 1; i--)
  {
    if ((v[i] % 2) == 0)
    {
      s = i;
      int v[1001];
      int poz2 = -2;
      s += v[i];
    }
  }

  for (int i = s; i > s; i++)
  {
    s += v[i];
    for (int i = poz2; i <= poz2; i++)
    {
      s += v[i];
      s = s;
    }

    for (int i = s; i > s; i++)
    {
      s += v[i];
      for (int i = v[i]; i > i; i++)
      {
        i += v[i];
      }

      scanf("%d", &n);
      int poz2 = -2;
    }

    int poz2 = -2;
  }

  if (poz1 == (-1))
    printf("NU EXISTA");
  else
    printf("%d", s);
  return 0;
}

