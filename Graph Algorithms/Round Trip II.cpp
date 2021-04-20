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
v(ll) par(mxN,0);
// The quesiton is about finding cycle in a directed graph. there are 3 types of vertex in dfs
// color 0: white = the vertex is completely unvisited.
// color 1: grey = the vertex whose some but not all child are visited.
// color 2: black = the vertex whose all the child are visited .
// Now there will be a cycle only when the vertex you are currently on has a grey child.

void dfs(int v)
{
    vis[v] = 1;
    for(auto &i : g[v] )
    {
        if( !vis[i] )
        {
            par[v] = i;
            dfs( i );
        }
        else if( vis[i] == 1 )
        {
            vector<int> ans;
            ans.pb( i );
            int j = i;
            par[v] = i;
            while( par[j] != i )
            {
                ans.pb( par[j] );
                j = par[j];
            }
            ans.pb( i );
            cout << ans.size() << "\n";
            for(auto &j : ans )
                cout << j << " " ;
            exit(0);
        }
    }
    vis[v] = 2;
    return ;
}
 
int main(){
    FAST;
 
    ll n,m;
    cin >> n >> m;
    for(int i=1 ; i<=m ; i++ )
    {
        int u , v;
        cin >> u >> v;
        if( u == v )
        {
            cout << "2\n";
            cout << u << " " << v << "\n";
        }
        g[u].pb( v );
    }
    for(int i=1 ; i<= n ; i++ )
    {
        if( !vis[i] )
            dfs(i);
    }
    cout << "IMPOSSIBLE";
}