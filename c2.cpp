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
 
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int power(int a,int n){
    if(n == 1)return a;
    if(n == 0)return 1;
    if(n%2)return (a*(power((a*a),n/2)));
    return power((a*a),n/2);
}
 
const int inf = (int) 1e18;
 
int inverse(int x){
    return power(x,mod-2)%mod;//little fermat....
}

int mat[maxn][6];

void solve(){
   int n,d;
   cin >> n >> d;
   FOR(i,1,n+1){
    FOR(j,0,d)cin >> mat[i][j];
   }
   int ans = 0;
   FOR(i,1,n+1){
       FOR(j,0,1<<d){
        FOR(k,0,d){
            if((1<<k)&j)//pos
        }
       }
   }
}

signed main()
{
    showoff;
    int T = 1;
    cin >> T;
    while(T--){   
        solve();
        //cout << "\n";
    }
    return 0;
}
//*->for large size of matrix take int not long long if possible......
//*->always take maximum as inf for safer side ...
 

