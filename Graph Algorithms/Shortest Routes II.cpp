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
const ll mxN = 5e2+5;
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
ll dp[mxN][mxN];

void Flyod_Warshall(ll n){

    rep(i,1,n+1) dp[i][i] = 0;

    rep(i,1,n+1)
        rep(j,1,n+1)
            rep(k,1,n+1)
                dp[j][k] = min(dp[j][k],dp[j][i]+dp[i][k]);
}

int main(){
    FAST;
 
    ll n,m,q;
    cin >> n >>m >> q;
    
    rep(i,1,n+1)
        rep(j,1,n+1)
            dp[i][j] = oo;

    rep(i,0,m){
        ll u,v,w;
        cin >> u >> v >> w;

        dp[u][v] = min(dp[u][v],w);
        dp[v][u] = min(dp[v][u],w);
    }

    Flyod_Warshall(n);
    while(q--){
        ll u,v;
        cin >> u >> v;

        if(dp[u][v] == oo) cout << -1 << endl;
        else cout << dp[u][v] << endl;
    }
    return 0;
}