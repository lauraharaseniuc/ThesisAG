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
    a[x] = a[x] + 1;
  }

  scanf("%d", &m);
  for (int i = 1; i <= m; i++)
  {
    scanf("%d", &x);
    b[x] = b[x] + 1;
  }

  for (int i = 0; i <= 10000; i++)
  {
    for (int j = 0; j <= 10000; j++)
    {
      if ((i * j) >= p)
      {
        cont += a[i] * b[j];
        break;
        break;
        break;
        break;
        j++;
      }
      j++;
      j++;
    }

  }

  printf("%d", cont);
  return 0;
}

