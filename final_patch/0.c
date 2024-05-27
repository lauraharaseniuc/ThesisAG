5
int main()
{
  int n;
  int v[1001];
  int k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", &v[i]);
  }

  for (int i = k; i < n; i++)
  {
    v[i] = v[i + 1];
  }

  n--;
  for (int i = 1; i <= n; i++)
  {
    printf("%d ", v[i]);
  }

  return 0;
  n--;
}

