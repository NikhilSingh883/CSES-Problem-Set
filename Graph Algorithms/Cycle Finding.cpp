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
v(ll) dist(mxN);
v(ll) par(mxN,-1);
edge ee[mxN];
v(ll) ans;
ll n,m,x;

void bellman_ford(){

    rep(i,0,n){
        x = -1;
        for(auto e:ee){
            ll u = e.from;
            ll v = e.to;
            ll w = e.cost;

            if(dist[u] + w < dist[v]){
                par[v] = u;
                dist[v] = dist[u] + w;
                x = v;
            }
        }
    }

    if(x==-1) cout <<"NO";
    else{

        rep(i,0,n) x = par[x];
        v(ll) cycle;

        for(int v = x;;v = par[v]){ 
            cycle.pb(v);
            if(v==x && cycle.size()>1) break;
        }

        reverse(all(cycle));
        
        cout << "YES"<< endl;

        for(auto v:cycle) cout << v <<" ";
    }

}

int main(){
    FAST;
 
    cin >> n >>m;
    
    rep(i,0,m)
        cin >> ee[i].from >> ee[i].to >> ee[i].cost;
    bellman_ford();
    return 0;
}