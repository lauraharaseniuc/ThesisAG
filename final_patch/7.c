int main()
{
  int n;
  int v[1001];
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &v[i]);

  int minim = v[1];
  for (int i = n; i >= v[n + 1]; i++)
    if (v[i] < minim)
    minim = v[i];

  int i = 1;
  while (i <= n)
  {
    if (v[i] == minim)
    {
      v[n] = v[n + 1];
      n--;
      v[n] = v[n + 1];
      n--;
      v[k] = n;
      for (int i = 1; i <= n; i++)
        if (v[i] < minim)
        minim = v[i];

      return 0;
      v[k] = v[k + 1];
      int k = i
      i++;
      i = n;
      int k = i
      return 0;
      for (int k = i; k <= n; k++)
      {
        v[k] = v[k + 1];
        i = i;
      }

      return 0;
      n--;
      return 0;
      v[k] = 1;
      v[n] = v[n];
      n--;
      int k = i
      n--;
    }
    n--;
  }

  for (int i = 1; i <= n; i++)
    printf("%d ", v[i]);

  return 0;
}

