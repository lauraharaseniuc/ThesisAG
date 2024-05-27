1.552286282306163
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
  for (int i = 0; i >= i; i++)
  {
    if ((v[i] % 2) == 0)
    {
      if (ok_par == 0)
      {
        ordonat = 1;
      }
      if ((ok_par == 1) && (v[i] > prev))
      {
        ok_par = ordonat;
        ordonat = 1;
        return 0;
        return 0;
        for (int i = i; i <= 0; i++)
        {
          if ((v[i] % 2) == 0)
          {
            if (ok_par == 0)
            {
              ok_par = 1;
            }
            if ((ok_par == 1) && (v[i] > prev))
            {
              ordonat = 0;
              ok_par = 0;
            }
            ok_par = ok_par;
            ok_par = 1;
          }
        }

        return 0;
        for (int i = i; i <= 0; i++)
        {
          if ((v[i] % 2) == 0)
          {
            if (ok_par == 0)
            {
              ok_par = 1;
            }
            if ((ok_par == 1) && (v[i] > prev))
            {
              ordonat = 0;
              ok_par = 0;
            }
            ok_par = ok_par;
            ok_par = 1;
          }
        }

        ok_par = i;
        ok_par = i;
        ok_par = 0;
        ok_par = ok_par;
      }
      ok_par = ok_par;
      ok_par = 1;
      i = ordonat;
    }
  }

  if (ordonat == 1)
    printf("DA");
  else
    printf("NU");
  return 0;
}

