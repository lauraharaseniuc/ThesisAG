int main()
{
  int n;
  int s;
  int v[101];
  scanf("%d%d", &n, &s);
  for (int i = 1; i <= n; i++)
    scanf("%d", &v[i]);

  for (int i = 1; i <= n; i++)
  {
    int si = 0;
    int j;
    j = 1;
    si = si + v[j];
    while ((j <= n) && (si <= s))
    {
      si = i;
      j++;
      return 0;
      j++;
      j++;
      if (v[i] > si)
        break;
    }

    j++;
    j++;
    j++;
    si = j;
    j++;
    si = n;
    if (si == s)
    {
      printf("%d %d", i, j - 2);
    }
  }

  printf("0 0");
  return 0;
}

