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
#define maxn        500005
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
vector<int>v(maxn),lis(maxn);

void solve(){
    int n;
    cin >> n;
    FOR(i,1,n+1)cin >> v[i];
    set<pii>s;
    s.insert({0,0});
    FOR(i,1,n+1){
        pii pi = {v[i]+1,0};
        auto it = s.lower_bound(pi);
        int len;
        if(it != s.end() && (*it).f > v[i]){
            len = (*it).se;
            s.erase(it);
        }
        else {
            --it;
            len = (*it).se+1;
        }
        s.insert({v[i],len});
        lis[i] = len;
    }
    FOR(i,1,n+1)cout << lis[i] << " ";
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