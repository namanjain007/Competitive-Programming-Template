#include <bits/stdc++.h>
 
#define int         long long
#define uint        unsigned int
#define ld          long double
#define showoff     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb          push_back
#define pii         pair<int,int>
#define FOR(i,a,b)  for(int i=a;i<b;++i)
#define RFOR(i,a,b) for(int i=a;i>b;--i)
#define f           first
#define se          second
#define maxn        200005
#define all(v)      v.begin(),v.end()
#define sz(x)       (int)x.size()
#define mod         998244353
#define pqueue      priority_queue<pii>
#define pdqueue     priority_queue< int,vector<int> ,greater< int >>
 
using namespace std;
 
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
 
int power(int a,int n)
{
    a %= mod;
    if(n == 1)return a;
    if(n == 0)return 1;
    if(n%2)return (a*(power((a*a)%mod,n/2)%mod))%mod;
    return power((a*a)%mod,n/2)%mod;
}

const int inf = (int) 1e18;
 
int inverse(int x){
    return power(x,mod-2)%mod;//little fermat....
}
bool check(string x){
    int tot = 0,fo = 1;
    FOR(i,0,sz(x)){
        if(x[i] == '(')tot++;
        else tot--;
        if(tot < 0)return 0;
    }
    if(tot != 0)return 0;
    return 1; 
}

bool solve2(string s1,string s2){
    string t1 = s1+s2;
    bool fo = 1;
    int tot = 0;
    FOR(i,0,sz(t1))if(t1[i] == '(')++tot;
    else if(tot == 0)fo = 0;
    else tot--;
    if(fo)return 1;
    return 0;
}

void solve(){
    int n;
    cin >> n;
    vector<string>s;
    FOR(i,0,n){string x;cin >> x;s.pb(x);}
    if(sz(s) == 1){
        if(check(s[0]))cout << "Yes\n";
        else cout << "No\n";
    }
    sort(s.begin(),s.end(),solve2);
    string ans = "";
    FOR(i,0,n)ans += s[i];
    if(check(ans))cout << "Yes\n";
    else cout << "No\n";
}

signed main()   
{
    showoff;
    int T = 1;
    //cin >> T;
    FOR(t,1,T+1){
       solve();
       //cout << "\n";
    }
    return 0;
}
//*->for large size of matrix take int not long long if possible......
//*->always take maximum as inf for safer side ...
