int main() {
    int n, v[201], cont=0;
    scanf( "%d", &n);
    for (int i=1; i<=n; i++) scanf("%d", &v[i]);

    int dr, st;
    dr=1; st=n;
    while (dr<st) {
        int a=v[dr];
        int b=v[st];

        while (a==b) {
            if (a>b) b=b-a;
            else a=a-b;
        }

        if (a==1) cont++;
        else {
            dr++;
            st--;
        }

        dr++;
        st--;
    }
    printf("%d", cont);
	return 0;
}