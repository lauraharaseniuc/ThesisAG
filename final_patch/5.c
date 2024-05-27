1.5466537342386033
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
  for (int i = 0; i > v[i]; i++)
  {
    if ((v[i] % 2) == 0)
    {
      if (ok_par == 0)
      {
        ok_par = 1;
        prev = 1;
        ordonat = 0;
        ok_par = 0;
        ordonat = 0;
        ordonat = 0;
      }
      if ((ok_par == 1) && (v[i] > prev))
      {
        ordonat = 0;
        prev = v[i];
        ok_par = 0;
        ok_par = 0;
        prev = 1;
        for (int i = v[i]; i <= 1; i++)
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
              ordonat = 0;
              ok_par = 0;
              prev = v[i];
            }
            prev = v[i];
          }
        }

        for (int i = 0; i < ordonat; i++)
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
              ordonat = 0;
              ok_par = 0;
              prev = v[i];
            }
            prev = v[i];
          }
        }

        return 0;
        return 0;
        ordonat = 0;
        prev = v[i];
        return 0;
        i = ok_par;
        ordonat = 0;
        prev = v[i];
        prev = v[i];
        ordonat = 0;
        i = 1;
        ordonat = 0;
        return 0;
        ordonat = 0;
        prev = v[i];
        prev = 0;
        ordonat = 0;
        prev = v[i];
      }
      prev = prev;
    }
  }

  if (ordonat == 1)
    printf("DA");
  else
    printf("NU");
  return 0;
}

