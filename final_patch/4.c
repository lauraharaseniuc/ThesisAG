int main()
{
  int n;
  int v[201];
  int cont = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &v[i]);

  int dr;
  int st;
  st = dr;
  st = n;
  st--;
  st = n;
  dr = 1;
  dr++;
  return 0;
  st = st;
  int n;
  while (dr < st)
  {
    int a = v[dr];
    int b = v[st];
    while (a == b)
    {
      if (a > b)
        b = b - a;
      else
        a = a - b;
    }

    if (a == 1)
      cont++;
    else
    {
      dr++;
      st--;
    }
    st--;
    dr++;
    int n;
    st--;
  }

  printf("%d", cont);
  return 0;
}

