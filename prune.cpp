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
#define pdqueue     priority_queue< int,vector<int> ,greater< int >>
 
using namespace std;
 
 
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
 
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
vector<int>adj[maxn],cnt(maxn),par(maxn);
set<int>lvs;
//set<pii>lvs ;<depth,node>
//change to set<pii>lvs for outward to inward pruning without root.

void dfs(int x){

	for(auto &y:adj[x]){
		if(par[x] != y){
			par[y] = x;
			dfs(y);
		}
	}
}

void prune(int root){

	while(sz(lvs)){
		int x = (*lvs.begin());//acc. to need 
		lvs.erase(lvs.begin());
		//perform actions
		if(x == root)break;
		if(x != root)cnt[par[x]]++;
		if(par[x] != root && cnt[par[x]] == sz(adj[par[x]])-1 || par[x] == root && cnt[root] == sz(adj[root])){
			lvs.insert(par[x]);
		}
	}
}

signed main()	
{
    showoff;
    int n;
    cin >> n;
    FOR(i,1,n){
    	int u,v;
    	cin >> u >> v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    int root = 1;//default
    par[root] = root;
    dfs(root);
    FOR(i,1,n+1)if(sz(adj[i]) == 1 && i != root)lvs.insert(i);
    prune(root);
    return 0;
}
//*->for large size of matrix take int not long long if possible......
//*->always take maximum as inf for safer side ...