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

vector<int>sub(maxn),dad(maxn);
set<int>tree[maxn];

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
    if (p == -1) p = centroid; // dad of root is the root itself
    dad[centroid] = p;

    for (auto &v : tree[centroid]){
        //tree[centroid].erase(v); // remove the edge to disconnect
        tree[v].erase(centroid); // the component from the tree
        build(v, centroid);
    }
}

// End of Centroid Decomposition....

void solve(){
    int n;
    cin >> n;
    FOR(i,1,n){
        int u,v;
        cin >> u >> v;
        tree[u].insert(v);
        tree[v].insert(u);
    }
    build(1,-1);
    //Note:Remember to create tmp tree as tree gets altered....
}
 
signed main()
{
    showoff;
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
 
