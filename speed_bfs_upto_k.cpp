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
#define maxn        2000005
#define all(v)      v.begin(),v.end()
#define sz(x)       (int)x.size()
#define mod         1000000007
#define pqueue      priority_queue<int>
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
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, 1, -1};

void solve(){
    int n,m,k,x1,x2,y1,y2;
    cin >> n >> m >> k >> x1 >> y1 >> x2 >> y2;
    string s[n+5];
    int ans[n+5][m+5],inq[n+5][m+5];
    memset(inq,0,sizeof inq);
    FOR(i,1,n+1){
        FOR(j,1,m+1)ans[i][j] = inf;
    }
    FOR(i,1,n+1)cin >> s[i],s[i] = '#'+s[i];
    queue<pair<int,pii> >q;
    q.push({0,{x1,y1}});
    ans[x1][y1] = 0;
    inq[x1][y1] = 1;
    while(!q.empty()){  
        int r = q.front().se.f, c = q.front().se.se, tmp_ans = q.front().f;
        q.pop();
        if(ans[r][c] < tmp_ans)continue;
        FOR(i,0,4){
            FOR(j,1,k+1){
                int cx = r+j*dx[i],  cy = c+j*dy[i];
                if(cx < 1 || cy < 1 || cx > n || cy > m || s[cx][cy] == '@')break;
                if(ans[cx][cy] >= ans[r][c]+1){
                    ans[cx][cy] = ans[r][c]+1;
                    if(!inq[cx][cy]){
                        q.push({ans[cx][cy],{cx,cy}});
                        inq[cx][cy] = 1;
                    }
                }
                else break;
            }
        }
    }
    if(ans[x2][y2] != inf)cout << ans[x2][y2] << "\n";
    else cout << "-1\n";
}

signed main()
{
    //showoff;
    int T = 1;
    //cin >> T;
    FOR(t,1,T+1){   
        solve();
        cout << "\n";
    }
    return 0;
}
//*->for large size of matrix take int not long long if possible......
//*->always take maximum as inf for safer side ...
 
