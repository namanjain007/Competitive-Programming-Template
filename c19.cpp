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
#define pqueue      priority_queue<int>
#define pdqueue     priority_queue< int,vector<int> ,greater< int >>
#define PI 3.14159265359
 
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
int cnt[20000005],offset = 10000000;

void solve(int t){
    memset(cnt,0,sizeof cnt);
    int n,ans = 0;
    cin >> n;
    vector<int>v(n+5);
    FOR(i,1,n+1)cin >> v[i],v[i] += v[i-1];
    for(int i = 0;i*i <= n*100;++i){
        cnt[0+offset] = 1;
        FOR(j,1,n+1){
            ans += cnt[v[j]-i*i+offset];
            cnt[v[j]+offset]++;
        }
        cnt[0+offset]--;
        FOR(j,1,n+1)cnt[v[j]+offset]--;
    }
    cout << "Case #" << t << ": " << ans << "\n";
}   

signed main()
{
    showoff;
    int T;
    cin >> T;
    //T = 1;
    FOR(t,1,T+1){
        solve(t);
    }
    
    return 0;
}
//*->for large size of matrix take int not long long if possible......
//*->always take maximum as inf for safer side ... 
