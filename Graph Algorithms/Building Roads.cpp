#include <bits/stdc++.h> 
using namespace std;
#define ll long long int
#define pb push_back
#define rsz resize
#define endl '\n'
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define pi  pair<int,int>
#define f first
#define s second
#define pll pair<ll, ll>
#define v(x) vector<x>
#define mp make_pair
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const ll mxN = 1e5 +5;
const ll mod = 1e9 + 7;
const ll N = 6;
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define repf(x,start,end,k) for(auto x = start;x<=end;x+=k)
#define repb(x,start,end,k) for(auto x = start;x>=end;x-=k)

v(ll) g[mxN];
v(bool) vis(mxN,0);

void dfs(ll root){
    vis[root] =1;

    for(auto i:g[root]){
        if(!vis[i])
            dfs(i);
    }
}

int main(){
    FAST;

    ll n,m;
    cin >> n >>m;

    rep(i,0,m){
        ll u,v;
        cin >> u >> v;

        g[u].pb(v);
        g[v].pb(u);
    }

    v(ll) req;

    repf(i,1,n,1){
        if(!vis[i]){
            req.pb(i);
            dfs(i);
        }
    }

    cout << req.size() - 1<<endl;

    rep(i,1,req.size())
        cout << req[i-1] <<" "<<req[i] << endl;
}