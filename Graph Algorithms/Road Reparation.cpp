#include <bits/stdc++.h> 
using namespace std;
#define ll long long int
#define pb push_back
#define rsz resize
#define endl '\n'
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define pi  pair<int,int>
#define x first
#define y second
#define p(x,y) pair<x, y>
#define ti tuple<ll,ll,ll>
#define v(x) vector<x>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const ll mxN = 2e5+5;
const ll mod = 1e9 + 7;
const ll N = 6;
const ll oo = 1e15;
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define repf(x,start,end,k) for(auto x = start;x<=end;x+=k)
#define repb(x,start,end,k) for(auto x = start;x>=end;x-=k)
struct edge{
    ll from,to,cost;
};

int dx[4] ={1,-1,0,0};
int dy[4] ={0,0,1,-1};

v(ti) g;
v(ll) link(mxN,0);
v(ll) len(mxN,1);

ll n,m,k;
ll find(ll a){
    while(a!=link[a]) a=link[a];
    return a;
}
void join(ll a, ll b){
    if (find(a)==find(b)) return;
    ll x = find(a), y = find(b);
    if (len[x]>len[y]) swap(x,y);
    len[y]+=len[x];
    link[x] = y;
}


int main(){
    FAST;
 
    cin >> n >> m;

    rep(i,0,m){
        int u , v, w;
        cin >> u >> v >> w;
        g.pb( {w,u,v} );
    }

    sort(all(g));
    rep(i,1,n+1) link[i] = i;
    ll s=0;

    for(auto [w,a,b]: g){
        if(find(a) == find(b)) continue;
        s += w;
        join(a,b);
    }
    ll c=0;

    rep(i,1,n+1) if(link[i] == i) c++;
    if(c==1) cout <<s;
    else cout <<"IMPOSSIBLE";

    return 0;
}