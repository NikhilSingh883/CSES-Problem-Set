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
ll n,m;
map<ll,ll> mp;

void topsort(){
        
        
        queue<ll> q;
        vector<ll> cou;
        
        for(auto x:mp)
            if(x.second == 0) q.push(x.first);
    
        
        while(!q.empty()){
            ll top = q.front();
            q.pop();
            cou.push_back(top);
            
            for(auto x:g[top]){
                mp[x]--;
                if(mp[x] ==0)
                    q.push(x);
            }
            
        }

        if(cou.size() == n) {
            for(auto x:cou) cout << x <<" ";
            exit(0);
        }
}
 
int main(){
    FAST;
 
    cin >> n >> m;
    for(int i=1;i<=n;i++) mp[i] = 0;

    for(int i=1 ; i<=m ; i++ )
    {
        int u , v;
        cin >> u >> v;
        g[u].pb( v );
        mp[v]++;
    }

    topsort();
    cout << "IMPOSSIBLE";
}