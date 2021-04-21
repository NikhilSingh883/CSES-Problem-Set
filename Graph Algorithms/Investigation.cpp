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

v(p(ll,ll)) g[mxN];
v(ll) dist(mxN,oo);
v(ll) route(mxN,0);
v(ll) min_f(mxN,0);
v(ll) max_f(mxN,0);

ll n,m,k;
void dijkstra(){
    priority_queue<p(ll,ll),v(p(ll,ll)),greater<p(ll,ll)>> pq;

    pq.push({0,1});
    dist[1] = 0;
    route[1] = 1;

    while(!pq.empty()){
        ll node = pq.top().y;
        ll cost = pq.top().x;
        pq.pop();

        if(dist[node] < cost) continue;

        for(auto i : g[node] )
        {
            ll v = i.x;
            ll c = i.y;

            if(c + cost > dist[v]) continue;
            if(c + cost == dist[v]){
                route[v] += route[node];
                route[v]%=mod;
                min_f[v] = min(min_f[node]+1,min_f[v]);
                max_f[v] = max(max_f[node]+1,max_f[v]);
            }
            if(c + cost < dist[v]){
                dist[v] = c + cost;
                route[v] = route[node];
                min_f[v] = min_f[node]+1;
                max_f[v] = max_f[node]+1;
                pq.push({dist[v],v});
            }
        }
    }

}

int main(){
    FAST;
 
    cin >> n >> m;

    for(int i=1 ; i<=m ; i++ )
    {
        int u , v, w;
        cin >> u >> v >> w;
        g[u].pb( {v,w} );
    }
    dijkstra();

    cout << dist[n] <<" "<<route[n]<<" "<<min_f[n]<<" "<<max_f[n]<<endl;
    return 0;
}