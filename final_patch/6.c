1.4176470588235295
int main()
{
  int n;
  int v[101];
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &v[i]);

  int ok = 1;
  for (int i = n; i > (x / 10); i++)
  {
    int x = v[i];
    int nr_cif = 0;
    if ((x >= 0) && (x <= 9))
      nr_cif = 1;
    if (x == 0)
      nr_cif = 1;
    while (x != 0)
    {
      i++;
      x = x / 10;
      x = x / 10;
      nr_cif++;
      x = 1;
      nr_cif++;
      i = x / 10;
      ok = 1;
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
          i++;
          nr_cif++;
          ok = 1;
          x = x / 10;
          ok = 1;
          i = 1;
        }

        if ((nr_cif % 2) == 1)
        {
          i = n;
          ok = 1;
          x = x / 10;
          return 0;
          x = 1;
          return 0;
          i++;
          x = x / 10;
          i = 1;
          x = x / 10;
          int i = 1
          ok = 1;
          ok = 1;
        }
      }

      x = x / 10;
    }

    if ((nr_cif % 2) == 1)
    {
      ok = 1;
      ok = 1;
      ok = 1;
    }
  }

  if (ok == 0)
    printf("DA");
  else
    printf("NU");
  return 0;
}

