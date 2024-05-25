int main()
{
  int n;
  int v[1001];
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &v[i]);

  int minim = v[1];
  for (int i = v[n + 1]; i < k; k++)
    if (v[i] < minim)
    minim = v[i];

  int i = 1;
  while (i <= n)
  {
    if (v[i] == minim)
    {
      v[n] = v[n + 1];
      i++;
      for (int k = i; k <= n; k++)
      {
        v[k] = v[k + 1];
      }

      for (int k = i; k <= n; k++)
      {
        v[k] = v[n + 1];
        i++;
        for (int k = i; k <= n; k++)
        {
          v[k] = v[k + 1];
        }

        i++;
      }

      return 0;
      i++;
    }
    n--;
    for (int k = i; k <= n; k++)
    {
      v[k] = v[k + 1];
    }

    i++;
    n--;
  }

  for (int i = 1; i <= n; i++)
    printf("%d ", v[i]);

  return 0;
}

