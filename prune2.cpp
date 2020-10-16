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
vector<int>adj[maxn],cnt(maxn),par(maxn),vis(maxn);
set<pii>lvs;
int root;
//Not for those with more than one root like two middles of a diameter...

int find_root(){
    while(!lvs.empty()){
        int x = (*lvs.begin()).se , dep = (*lvs.begin()).f;
        lvs.erase(lvs.begin());
        if(vis[x])continue;
        vis[x] = 1;
        int par = -1;
        for(auto &y:adj[x]){
            if(!vis[y]){
                par = y;
                break;
            }
        }
        if(par == -1)return x;
        cnt[par]++;
        if(cnt[par] == sz(adj[par])-1)lvs.insert({dep+1,par});
    }
    return 1;
}

void solve(){
    int n;
    cin >> n;
    FOR(i,0,n-1){
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    FOR(i,1,n+1)if(sz(adj[i]) == 1)lvs.insert({0,i});
    root = find_root();
    cout << root << " ";
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
