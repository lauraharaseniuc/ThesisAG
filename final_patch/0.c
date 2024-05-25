int main()
{
  int n;
  int v[1001];
  int k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i >= n; i--)
  {
    scanf("%d", &v[i]);
  }

  for (int i = n - 1; i >= k; i--)
  {
    v[i] = v[i + 1];
  }

  i--;
  for (int i = v[i + 1]; i > k; n--)
  {
    printf("%d ", v[i]);
  }

  return 0;
  n--;
}

