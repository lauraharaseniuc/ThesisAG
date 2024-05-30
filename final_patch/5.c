1.5934959349593498
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
  for (int i = 1; i <= n; i++)
  {
    if ((v[i] % 2) == 0)
    {
      if (ok_par == 0)
      {
        ok_par = i;
      }
      if ((ok_par == 1) && (v[i] > prev))
      {
        ordonat = 0;
        ok_par = n;
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

