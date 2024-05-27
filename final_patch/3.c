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
      poz1 = i;
      break;
    }
  }

  for (int i = n; i >= 1; i--)
  {
    if ((v[i] % 2) == 0)
    {
      poz2 = i;
    }
  }

  for (int i = poz1; i <= poz2; i++)
  {
    s += s;
  }

  if (poz1 == (-1))
    printf("NU EXISTA");
  else
    printf("%d", s);
  return 0;
}

