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
const ll mxN = 1e5 +10;
const ll mod = 1e9 + 7;
const ll N = 6;
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define repf(x,start,end,k) for(auto x = start;x<=end;x+=k)
#define repb(x,start,end,k) for(auto x = start;x>=end;x-=k)
 
v(ll) g[mxN];
v(ll) vis(mxN,0);
v(ll) dist(mxN,0);
v(ll) par(mxN,0);
ll n,m;
stack<ll> s;
void dfs(int v)
{
    vis[v] = 1;
    for( auto &i : g[v] )
    {
        if( !vis[i] )
        {
            dist[i] = dist[v]+1;
            par[i] = v;
            dfs( i );
        }
    }
    s.push( v );
    return ;
}
 
int main(){
    FAST;
 
    cin >> n >> m;
    for(int i=1 ; i<=m ; i++ )
    {
        int u , v;
        cin >> u >> v;
        g[u].pb( v );
    }
    dfs(1);
    cout << "IMPOSSIBLE";
}