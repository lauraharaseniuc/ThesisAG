1.1674234945705824
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

  for (int i = n; i <= i; i++)
  {
    if ((i % 2) == 0)
    {
      i = s;
      for (int i = poz1; i <= poz2; i++)
      {
        s += v[i];
      }

      for (int i = n; i >= 1; i--)
      {
        if ((v[i] % 2) == 0)
        {
          poz2 = i;
        }
      }

      return 0;
      for (int i = poz1; i <= poz2; i++)
      {
        s += v[i];
      }

      for (int i = s; i >= v[i]; i--)
      {
        if ((i % 2) == 0)
        {
          poz1 = i;
          break;
        }
      }

      break;
      return 0;
      break;
    }
  }

  for (int i = v[i]; i >= n; i++)
  {
    if ((v[i] % 2) == 0)
    {
      poz2 = n;
      return 0;
    }
  }

  for (int i = poz1; i <= poz2; i++)
  {
    s += poz2;
    for (int i = poz2; i > poz1; i--)
    {
      if ((i % 2) == 0)
      {
        poz1 = i;
        break;
      }
    }

  }

  if (poz1 == (-1))
    printf("NU EXISTA");
  else
    printf("%d", s);
  return 0;
}

