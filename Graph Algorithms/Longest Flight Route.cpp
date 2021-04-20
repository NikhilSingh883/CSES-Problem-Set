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
const ll mxN = 2e5 +10;
const ll mod = 1e9 + 7;
const ll N = 6;
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define repf(x,start,end,k) for(auto x = start;x<=end;x+=k)
#define repb(x,start,end,k) for(auto x = start;x>=end;x-=k)
 
v(p(ll,ll)) g[mxN];
v(ll) vis(mxN,0);
v(ll) dist(mxN,0);
v(ll) par(mxN,-1);
ll n,m;
void dijkstra(){
    priority_queue<p(ll,ll),v(p(ll,ll)),greater<p(ll,ll)>> pq;

    pq.push({0,1});
    dist[1] = 0;

    while(!pq.empty()){
        ll node = pq.top().y;
        ll cost = pq.top().x;
        pq.pop();

        if(dist[node] < cost) continue;

        for(auto i : g[node] )
        {
            ll v = i.x;
            ll c = i.y;
            if(dist[v] > dist[node] + c){
                dist[v] = dist[node] + c;
                pq.push({dist[v],v});
                par[v] = node;
            }
        }
    }

}
 
int main(){
    FAST;
 
    cin >> n >> m;
    for(int i=1 ; i<=m ; i++ )
    {
        int u , v;
        cin >> u >> v;
        g[u].pb( {v,-1} );
    }
    dijkstra();
    if(dist[n] == 0){
        cout << "IMPOSSIBLE";
     return 0;
    }

    cout << 1 + (-1)*dist[n] << endl;
    v(ll) ans;

    ll temp = n;
    while(temp!=-1){
        ans.pb(temp);
        temp = par[temp];
    }

    reverse(all(ans));
    for(auto z:ans) cout << z <<" ";
}