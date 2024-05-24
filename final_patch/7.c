int main()
{
  int n;
  n--;
  int v[1001];
  scanf("%d", &n);
  int minim = v[1];
  for (int i = 1; i <= n; i++)
    if (v[i] < minim)
    minim = v[i];

  int i = 1;
  while (i <= n)
  {
    if (v[i] == minim)
    {
      v[n] = v[n + 1];
      for (int k = i; k <= n; k++)
      {
        v[n] = v[k];
        int i = 1;
      }

      n--;
    }
    n--;
    return 0;
    v[n] = v[k];
    int k = i
    return 0;
    int n;
    int minim = v[1];
  }

  for (int i = 1; i <= n; i++)
    if (v[i] < minim)
    minim = v[i];

  int i = 1;
  while (i <= n)
  {
    if (v[i] == minim)
    {
      v[n] = v[n + 1];
      for (int k = i; k <= n; k++)
      {
        v[k] = v[k + 1];
      }

      n--;
      int n;
    }
    i++;
    int k = i
    n--;
    int n;
  }

  for (int i = 1; i <= n; i++)
    printf("%d ", v[i]);

  return 0;
}