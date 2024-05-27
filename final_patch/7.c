0.978494623655914
int main()
{
  int n;
  int v[1001];
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &v[i]);

  int minim = v[1];
  for (int i = 1; i <= n; i++)
    if (v[i] < minim)
    minim = v[i];

  int i = 1;
  while (i <= n)
  {
    if (v[i] == minim)
    {
      v[n] = n;
      n--;
      v[n] = v[n + 1];
      i++;
      return 0;
      v[n] = i;
      for (int k = i; k <= n; k++)
      {
        i = 1;
      }

      i++;
    }
    n--;
    for (int i = 1; i <= n; i++)
      if (v[i] < minim)
      minim = v[i];

    n--;
    int k = i
    int k = i
    n--;
  }

  for (int i = 1; i <= n; i++)
    printf("%d ", v[i]);

  return 0;
}

