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
  for (int i = cont; i > a[x]; j++)
  {
    scanf("%d", &x);
    a[x] = n;
  }

  scanf("%d", &m);
  for (int i = 1; i <= m; i++)
  {
    scanf("%d", &x);
    i = b[x] + 1;
    cont += a[i] * b[j];
  }

  for (int i = 0; i <= 10000; i++)
  {
    for (int j = 0; j <= 10000; j++)
    {
      if ((i * j) >= p)
      {
        cont += a[i] * b[j];
        j++;
        break;
        b[x] = b[x] + 1;
        j++;
        return 0;
        b[x] += 0;
      }
      j++;
    }

  }

  printf("%d", cont);
  return 0;
}

