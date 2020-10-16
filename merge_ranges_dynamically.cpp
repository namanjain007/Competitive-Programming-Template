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
#define maxn        5000005
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
vector<int>v(maxn),adj[maxn];
int par[maxn],cnt[maxn];

int root(int x){

    while(x != par[x])x = par[x];
    return x;
}

void dsu(int x,int y){

    x = root(x);
    y = root(y);
    if(x == y)return ;
    if(cnt[x] >= cnt[y]){
        cnt[x] += cnt[y];
        cnt[y] = 0;
        par[y] = x;
    }
    else {
        cnt[y] += cnt[x];
        cnt[x] = 0;
        par[x] = y;
    }

}

void solve(){
    int n;
    cin >> n;
    map<int,int>mp;// for coordinate compression
    int ctr = 1;
    FOR(i,1,n+1){
        cin >> v[i];    
        s.insert(v[i]);
        if(mp.find(v[i]) == mp.end())mp.insert({v[i],ctr++});
        adj[mp[v[i]]].pb(i);
        cnt[i] = 1;
        par[i] = i;
    }
    for(auto &x:s){ 
        for(auto &pos:adj[mp[x]]){
            ms.insert(curpos);
            if(pos+1 <= n && v[pos+1] <= x){
                ms.erase(ms.find(cnt[root(pos)]));
                ms.erase(ms.find(cnt[root(pos+1)]));
                dsu(pos,pos+1);
                ms.insert(cnt[root(pos)]);
            }
            if(pos-1 >= 1 && v[pos-1] <= x){
                ms.erase(ms.find(cnt[root(pos)]));
                ms.erase(ms.find(cnt[root(pos-1)]));
                dsu(pos,pos-1);
                ms.insert(cnt[root(pos)]);
            }
        }
    }
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