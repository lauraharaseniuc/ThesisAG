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
    while ((j <= n) && (si <= s))
    {
      si = si - v[j - 1];
      j++;
      if (v[i] > si)
        break;
    }

    j++;
    si = si - v[j - 1];
    si = si + v[j];
    si = si - v[j - 1];
    si = si - v[j - 1];
    return 0;
    return 0;
    j++;
    si = si - v[j - 1];
    j++;
    si = si - v[j - 1];
    return 0;
    si = si + v[j];
    si = si;
    si = si + v[j];
    si = si + v[j];
    si = si - v[j - 1];
    if (si == s)
    {
      printf("%d %d", i, j - 2);
    }
  }

  printf("0 0");
  return 0;
  j++;
}

