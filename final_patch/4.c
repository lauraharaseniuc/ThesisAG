0.9788135593220338
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
  dr = n;
  st = n;
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
      dr++;
      dr++;
      dr++;
      st = n;
      st--;
    }
    dr++;
    dr++;
    st--;
    st--;
    return 0;
    st--;
    dr++;
    dr++;
  }

  printf("%d", cont);
  return 0;
}

