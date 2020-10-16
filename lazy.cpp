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
int tree[4*maxn],lazy[4*maxn],A[maxn];

void build(int no, int st, int la)
{
    if(st == la){
        tree[no] = A[st];
        return ;
    }
    int mid = (st+la)/2;
    build(2*no,st,mid);
    build(2*no+1,mid+1,la);
    tree[no] = tree[2*no]+tree[2*no+1];
}

void update(int no,int st,int la,int l,int r,int upd){

    if(lazy[no] != 0){
        tree[no] += lazy[no];
        if(st != la){
            lazy[2*no] += lazy[no];
            lazy[2*no+1] += lazy[no];
        }
        lazy[no] = 0;
    }
    if(l > r || l > la || r < st)return;
    if(l <= st && r >= la){
        tree[no] += upd;
        if(st != la){
            lazy[2*no] += upd;
            lazy[2*no+1] += upd;
        }
        return ;
    }
    int mid = (st+la)/2;
    update(2*no,st,mid,l,r,upd);
    update(2*no+1,mid+1,la,l,r,upd);
    tree[no] = tree[2*no] + tree[2*no+1];
}

int query(int no,int st,int la,int l,int r){

	if(lazy[no] != 0){
        tree[no] += lazy[no];
        if(st != la){
            lazy[2*no] += lazy[no];
            lazy[2*no+1] += lazy[no];
        }
        lazy[no] = 0;
    }
    if(l > la || r < st)return 0;
    if(l <= st && r >= la)return tree[no];
    int mid = (st+la)/2;
    return query(2*no,st,mid,l,r)+query(2*no+1,mid+1,la,l,r);
}	


signed main()
{
    showoff;
    
    
    return 0;
}
//*->for large size of matrix take int not long long if possible......
//*->always take maximum as inf for safer side ....s