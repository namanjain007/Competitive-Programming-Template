int fact[maxn];

int ncr(int n,int r){
    int num = fact[n];
    int den = (fact[n-r]*fact[r])%mod;
    num *= inverse(den);
    num %= mod;
    return num;
}

fact[0] = 1;
FOR(i,1,maxn)fact[i] = (fact[i-1]*i)%mod;