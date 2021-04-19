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
v(bool) vis(mxN,0);
v(ll) par(mxN,-1);
 
void dfs(int node,int p)
{
      par[node] = p;
      vis[node] = 1;
    
      for(auto x : g[node])
          if(!vis[x]) dfs(x,node);
          else if(x != p)
      {
          v(ll) cyc;   
          ll cur = node;
          cyc.pb(node);
          
          while(par[cur] != x)
          {
             cur = par[cur];
             cyc.pb(cur);
          }
          
          cyc.pb(x);
          cyc.pb(node);
          
          cout << cyc.size() << '\n';
          
          for(auto x : cyc) cout << x <<" ";
          exit(0);
      }
}
 
int main(){
    FAST;
 
    ll n,m;
    cin >> n >>m;
    ll u,v;
 
    rep(i,0,m){
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
 
    bool poss = false;
    rep(i,1,n+1)
        if(!vis[i])
            dfs(i,-1);
 
    cout << "IMPOSSIBLE";
}