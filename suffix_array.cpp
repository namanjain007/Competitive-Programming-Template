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
#define mod         1000000007
#define pqueue      priority_queue<int>
#define pdqueue     priority_queue<int,vector<int> ,greater<int>>
 
using namespace std;
 
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int power(int a,int n){
    if(n == 1)return a;
    if(n == 0)return 1;
    if(n%2)return (a*(power((a*a),n/2)));
    return power((a*a),n/2);
}
 
const int inf = (int) 1e18;
 
int inverse(int x){
    return power(x,mod-2)%mod;//little fermat....when p is prime
}

void radixsort(vector<pair<pii,int>>&v){
    vector<pair<pii,int>>ans;
    int n = sz(v);
    vector<int>adj[n+5];
    FOR(i,0,n)adj[v[i].f.se].pb(i);
    FOR(i,0,n){
        for(auto &x:adj[i])ans.pb(v[x]);
    }
    v = ans;
    FOR(i,0,n+5)adj[i].clear();
    FOR(i,0,n)adj[ans[i].f.f].pb(i);
    ans.clear();
    FOR(i,0,n+5){
        for(auto &x:adj[i])ans.pb(v[x]);
    }
    v = ans;
}

void solve(){
    string s;
    cin >> s;
    s += '$';
    int n = sz(s);
    vector<int>eq_class(n+5);
    vector<pair<char,int>>v;
    FOR(i,0,n)v.pb({s[i],i});
    sort(v.begin(),v.end());
    eq_class[v[0].se] = 0;
    FOR(i,1,n)if(v[i].f == v[i-1].f){
        eq_class[v[i].se] = eq_class[v[i-1].se];
    }
    else {
        eq_class[v[i].se] = eq_class[v[i-1].se]+1;
    }
    int k = 0;
    while((1<<k) < n){
        vector<pair<pii,int>>u;
        FOR(i,0,n)u.pb({{eq_class[i],eq_class[(i+(1<<k))%n]},i});
        radixsort(u);
        eq_class[u[0].se] = 0;
        FOR(i,1,n)if(u[i].f == u[i-1].f){
            eq_class[u[i].se] = eq_class[u[i-1].se];
        }
        else {
            eq_class[u[i].se] = eq_class[u[i-1].se]+1;
        }
        k++;
    }
    //FOR(i,0,n)cout << eq_class[i] << " ";
}

signed main()
{
    showoff;
    int t = 1;
    //cin >> t;
    FOR(T,1,t+1){
        solve();
    }
    return 0;
}

//*->for large size of matrix take int not long long if possible......
//*->always take maximum as inf for safer side ...  