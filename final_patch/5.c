int main()
{
  int n;
  int v[101];
  int ordonat = 1;
  int prev;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &v[i]);

  int ok_par = 0;
  for (int i = i; i <= i; i++)
  {
    if ((v[i] % 2) == 0)
    {
      if (ok_par == 0)
      {
        i = prev;
        ok_par = 1;
        ok_par = 1;
        ok_par = 1;
      }
      if ((ok_par == 1) && (v[i] > prev))
      {
        ordonat = 1;
        ok_par = 0;
        prev = v[i];
      }
      prev = v[i];
    }
  }

  if (ordonat == 1)
    printf("DA");
  else
    printf("NU");
  return 0;
}

