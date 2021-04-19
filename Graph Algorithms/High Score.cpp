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
#define v(x) vector<x>
#define mp make_pair
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
v(ll) vis(mxN,0);
v(ll) g[mxN];
v(ll) dist(mxN,oo);
v(ll) prev(mxN,-1);
edge ee[mxN];

void dfs( int v )
{
    vis[ v ] = 1;
    for( auto &i : g[v] )
        if( !vis[i] )
            dfs( i );
    return ;
}

bool bellman_ford(ll n,ll m){

    ll u,v,w,i,j;

    dist[1] = 0;

    rep(i,0,n)
        rep(j,0,m){
            u = ee[j].from;
            v = ee[j].to;
            w = ee[j].cost;

            if(dist[u] != oo && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
    }
    
    bool poss = true;
    rep(j,0,m){
        u = ee[j].from;
        v = ee[j].to;
        w = ee[j].cost;

        if(dist[u] != oo && dist[u] + w < dist[v])
            dfs(u);
    }

    return poss;

}

int main(){
    FAST;
 
    ll n,m;
    cin >> n >>m;
    
    rep(i,0,m){
        cin >> ee[i].from >> ee[i].to >> ee[i].cost;
        ee[i].cost *=-1;
        g[ee[i].from].pb(ee[i].to);
    }

    bellman_ford(n,m);

    if(!vis[n])
        cout << -1*dist[n] <<endl;
    else cout << -1 <<endl;
    return 0;
}