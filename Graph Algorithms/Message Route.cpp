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
ll prevNode[mxN];
ll vis[mxN];
v(ll) color(mxN,-1);

bool bfs(ll root){

    queue<ll> Q;
    Q.push(root);
    bool poss = true;
    color[root] = 1;


    while(!Q.empty()){
        ll top = Q.front();
        Q.pop();

        for(auto v:g[top]){

            if(color[v] == -1){
                color[v] = 1 - color[top];
                Q.push(v);
            }
            else if(color[v] == color[top]){
                return false;
            }
        }
    }

    return true;
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
    bool poss = true;

    rep(i,1,n+1)
        if(color[i] == -1)
            poss = poss && bfs(i);

    if(poss)
        rep(i,1,n+1) cout << 1 + color[i] <<" ";

    else cout << "IMPOSSIBLE";
}