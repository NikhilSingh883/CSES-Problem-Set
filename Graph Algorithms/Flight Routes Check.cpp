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

v(ll) g[mxN];
v(ll) rg[mxN];
v(ll) ans(mxN);
v(ll) vis1(mxN,0);
v(ll) vis2(mxN,0);
v(ll) len(mxN,1);
stack<ll> s;
ll n,m,k,grp_no=0;
void dfs1(int v)
{
    vis1[v] = 1;
    for( auto &i : g[v] )
        if(!vis1[i])
            dfs1(i);
    return ;
}
 
void dfs2(int v)
{
    vis2[v] = 1;
    for( auto &i : rg[v] )
        if(!vis2[i])
            dfs2(i);
    return ;
}

int main(){
    FAST;
 
       cin >> n >> m;
    for(int i=1 ; i<=m ; i++ )
    {
        int u,v;
        cin >> u>> v;
        g[u].pb(v);
        rg[v].pb(u);
    }
    dfs1(1);
    dfs2(1);
    bool f = 0;
    for(int i=1 ; i<=n ; i++ ) if( !vis1[i] || !vis2[i] ) f=1;
    if( !f ) cout << "YES\n";
    else
    {
        cout << "NO\n";
        for(int i=1 ; i<=n ; i++ )
        {
            if( !vis1[i] )
            {
                cout << "1 "<<i<<"\n";
                return 0;
            }
        }
        
        for(int i=1 ; i<=n ; i++ )
        {
            if( !vis2[i] )
            {
                cout << i << " 1\n";
                return 0;
            }
        }
    }
}