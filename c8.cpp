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


void solve(){
    int n;
    cin >> n;
    vector<int>v(n+5);
    FOR(i,1,n+1)cin >> v[i];
    sort(v.begin()+1,v.begin()+n+1,greater<int>());
    int xorr = 0;
    FOR(i,1,n+1)xorr ^= v[i];
    if(!xorr){
        cout << "DRAW\n";
        return ;
    }
    if(n == 1){
        cout << "WIN\n";
        return ;
    }
    int cnt[30];
    memset(cnt,0,sizeof cnt);
    FOR(i,1,n+1){
        FOR(j,0,31)if((1LL<<i)&v[i])cnt[j]++;
    }
    RFOR(i,30,-1){
        if(cnt[i] == 1){
            cout << "WIN\n";
            return ;
        }
        if(n%2){
            cout << "WIN\n";
            return;
        }
        n -= cnt[i];
    }
    cout << "LOSE\n";
}

signed main()   
{
    showoff;
    int T = 1;
    cin >> T;
    FOR(t,1,T+1){
       solve();
    }
    return 0;
}
//*->for large size of matrix take int not long long if possible......
//*->always take maximum as inf for safer side ..