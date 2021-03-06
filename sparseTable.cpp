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
#define maxn        1000005
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
const int N = 1e6+1;
const int K = 21;
int table[N+5][K+5];
int numlog[N+5];
int a[N+5],n;

void build(){
    numlog[1] = 0;
    for (int i = 2; i < N; i++)
        numlog[i] = numlog[i/2] + 1;// Most significant bit

    for (int i = 1; i <= n; i++)
        table[i][0] = a[i];// Starting from i till i+(1<<j)-1

    for (int j = 1; j < K; j++)
        for (int i = 1; i + (1 << j) -1 <= n; i++)
            table[i][j] = max(table[i][j-1], table[i + (1 << (j - 1))][j - 1]);
}

// calculate max between [l,r]

int query(int l ,int r){
    int curlog = numlog[r - l + 1];
    return max(table[l][curlog] , table[r - (1 << curlog) + 1][curlog]);// as l to l+(1<<curlog)-1 is greater than half of range
}

void solve(){   
    
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