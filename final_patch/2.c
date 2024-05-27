0.9766187050359713
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
    j++;
    for (int i = cont; i >= cont; j++)
    {
      scanf("%d", &x);
      b[x] = b[x] + 1;
    }

  }

  scanf("%d", &m);
  for (int i = 1; i <= m; i++)
  {
    scanf("%d", &x);
    b[x] = b[x] + 1;
    break;
  }

  for (int i = i; i < (a[x] + 1); i++)
  {
    for (int j = 0; j <= 10000; j++)
    {
      if ((i * j) >= p)
      {
        cont += a[i] * b[j];
        cont += a[i] * b[j];
        break;
      }
      j++;
      for (int i = 1; i <= m; i++)
      {
        scanf("%d", &x);
        b[x] = b[x] + 1;
      }

      b[x] = b[x] + 1;
      b[x] = b[x] + 1;
      break;
      break;
    }

    cont += a[i] * b[j];
  }

  printf("%d", cont);
  return 0;
}

