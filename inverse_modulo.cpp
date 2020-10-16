pair<int,pii> egcd(int a, int b){
    int x = 0,y = 1, u = 1,v = 0;
    while(a != 0){
        int q = b/a, r = b%a;
        int m = x-u*q, n = y-v*q;
        b = a,a = r, x = u,y = v, u = m,v = n;
    }
    int gcd = b;
    return {gcd,{x,y}};
}
int modinv(int a, int m){
    pair<int,pii>p = egcd(a, m);
    int gcd = p.f,x = p.se.f, y = p.se.se;
    if(gcd != 1)return -1;
    return (x%m);
}
