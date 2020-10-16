#include <bits/stdc++.h>
 
//#define int         long long
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

set<int>adj[maxn];
vector<int>spf(maxn+100);

void sieve(){
    for(int i = 2;i*i <= maxn;++i){
        if(spf[i])continue;
        spf[i] = i;
        for(int j = i*i;j <= maxn;j += i){
            if(!spf[j])spf[j] = i;
        }
    }
    for(int i = 2;i <= maxn;++i)if(!spf[i])spf[i] = i;
    adj[1].insert(1);
    for(int i = 2;i <= maxn;++i){
        for(auto &x:adj[i/spf[i]]){
            adj[i].insert(x);
            adj[i].insert(x*spf[i]);
        }
    }
}

void solve(){
     sieve();
     FOR(i,1,30){
        cout << i << " ";
        for(auto &x:adj[i])cout << x << " ";
        cout << "\n";
     }
   
}

signed main()   
{
    showoff;
    int T = 1;
    //cin >> T;
    FOR(t,1,T+1){
       solve();
    }
    return 0;
}
//*->for large size of matrix take int not long long if possible......
//*->always take maximum as inf for safer side ...