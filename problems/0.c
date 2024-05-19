int main() {
    int n, v[1001], k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
    }
    for (int i = n-1 ; i >= k; i--) {
        v[i] = v[i + 1];
    }

    n--;
    for (int i = 1; i <= n; i++) {
        printf("%d ", v[i]);
    }
    return 0;
}
