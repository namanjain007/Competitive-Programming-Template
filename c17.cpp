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

int n,m,l,timer;
vector<int>sub(maxn),par(maxn),col(maxn),dist(maxn),tin,tout,h(maxn);
set<int>tree[maxn],adj[maxn];
vector<vector<int> >up;

int cal_siz(int u, int p) {
    sub[u] = 1;
    for(auto &v : tree[u]){
        if(v != p) sub[u] += cal_siz(v, u);
    }
    return sub[u];
}

int find_centroid(int u, int p, int siz) {
    for(auto v : tree[u]){
        if (v != p and sub[v] > siz/2) return find_centroid(v, u, siz);
    }
    return u;
}

void build(int u, int p) {
    int n = cal_siz(u, p); // find the size of each subtree
    int centroid = find_centroid(u, p, n); // find the centroid
    if (p == -1) p = centroid; // par of root is the root itself
    par[centroid] = p;
    // auto tmp = tree[centroid];
    for (auto &v : tree[centroid]){
        //tree[centroid].erase(v); // remove the edge to disconnect
        tree[v].erase(centroid); // the component from the tree
        build(v, centroid);
    }
}

// End of Centroid Decomposition....

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (int u : adj[v]) {
        if (u != p)
            h[u] = h[v]+1,dfs(u, v);
    }
    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {

    tin.resize(n+5);
    tout.resize(n+5);
    timer = 0;
    l = ceil(log2(n));
    up.assign(maxn, vector<int>(l + 1));
    h[root] = 1;
    dfs(root, root);
}

int no_of_edges(int u,int v){
    int l = lca(u,v);
    if(l == u || l == v)return abs(h[u]-h[v]);
    return h[u]+h[v]-2*h[l];
}

void update(int x){
    dist[x] = 0;
    int cur = x;
    while(par[cur] != cur){
        cur = par[cur];
        dist[cur] = min(dist[cur],no_of_edges(cur,x));
    }
}

int query(int x){
    int ans = dist[x] , cur = x;
    while(par[cur] != cur){
        cur = par[cur];
        ans = min(ans,no_of_edges(x,cur)+dist[cur]);
    }
    return ans;
}

void solve(){
    cin >> n >> m;
    FOR(i,1,n){
        int u,v;
        cin >> u >> v;
        tree[u].insert(v);
        tree[v].insert(u);
    }
    FOR(i,1,n+1)adj[i] = tree[i];
    build(1,-1);
    FOR(i,1,n+1)dist[i] = inf;
    preprocess(1);
    update(1);
    while(m--){
        int t,u;
        cin >> t >> u;
        if(t == 1){
            update(u);
        }
        else {
            cout << query(u) << "\n";
        }
    }
}
 
signed main()
{
    //showoff;
    int t;
    //cin >> t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}
//*->for large size of matrix take int not long long if possible......
//*->always take maximum as inf for safer side ...#include <bits/stdc++.h>
 
