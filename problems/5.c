int main() {
    int n, v[101], ordonat = 1, prev;

    scanf( "%d", &n);
    for (int i=1; i<=n; i++) scanf("%d", &v[i]);

    int ok_par=0;
    for (int i=1; i<=n; i++) {
        if (v[i]%2 == 0) {
            if (ok_par==0) { ok_par = 1;}
            if (ok_par==1 && v[i] > prev) { ordonat = 0; ok_par=0;}
            prev = v[i];

        }
    }

    if (ordonat==1) printf("DA");
    else printf("NU");
    return 0;
}