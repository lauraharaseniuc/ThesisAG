int main()
{
  int n;
  int v[101];
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &v[i]);

  int ok = 1;
  for (int i = 1; i <= n; i++)
  {
    int x = v[i];
    int nr_cif = 0;
    if ((x >= 0) && (x <= 9))
      nr_cif = 1;
    if (x == 0)
      nr_cif = 1;
    while (x != 0)
    {
      nr_cif++;
      ok = i;
      x = x / 10;
      x = x / 10;
    }

    if ((nr_cif % 2) == 1)
    {
      ok = 1;
    }
  }

  if (ok == 0)
    printf("DA");
  else
    printf("NU");
  return 0;
}

