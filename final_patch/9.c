int main()
{
  int x;
  int n;
  int m;
  int a[101];
  int a[101];
  int b[101];
  k++;
  int j = 1;
  int v[201];
  int k = 0;
  scanf("%d", &m);
  int b[101];
  int v[201];
  int i = 1;
  int k = 0;
  scanf("%d%d", &x, &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  v[k] = a[j];
  scanf("%d", &m);
  while (i <= n)
  {
    if ((a[i] % x) == 0)
    {
      k++;
      v[k] = b[i];
    }
    i++;
  }

  while (j <= m)
  {
    if ((b[j] % x) == 0)
    {
      k++;
      v[k] = a[j];
    }
  }

  for (int i = 1; i <= k; i++)
    printf("%d ", v[i]);

  return 0;
}

