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
v(p(ll,ll)) g[mxN];
v(ll) dist(mxN,oo);
v(ll) prev(mxN,-1);

void dijkstra(){
    priority_queue<p(ll,ll),v(p(ll,ll)),greater<p(ll,ll)>> pq;

    pq.push({0,1});
    dist[1] = 0;

    while(!pq.empty()){
        ll node = pq.top().y;
        ll cost = pq.top().x;
        pq.pop();

        if(vis[node]) continue;

        vis[node] = 1;
        for(auto &i : g[node] )
        {
            if( !vis[i.x] )
                if( dist[i.x] > cost + i.y ){
                    dist[i.x] = cost + i.y;
                    pq.push( { dist[i.x] , i.x } );
                }
        }
    }

}

int main(){
    FAST;
 
    ll n,m;
    cin >> n >>m;
    
    rep(i,0,m){
        ll u,v,c;

        cin >> u >> v >> c; 
        g[u].pb({v,c});
    }
    dijkstra();
    rep(i,1,n+1) cout << dist[i] <<" ";
    return 0;
}