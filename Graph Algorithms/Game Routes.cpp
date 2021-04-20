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
v(ll) cnt(mxN,0);
v(ll) g[mxN];
v(ll) dist(mxN,0);
v(ll) par(mxN,-1);
edge ee[mxN];
v(ll) ans;
ll n,m,k;
map<ll,ll> mp;
// removed all other uncessary vertices
void prune_topsort(){
        
        
        queue<ll> q;
        vector<ll> cou;
        
        for(int i=2;i<=n;i++)
            if(mp[i] == 0) q.push(i);
    
        while(!q.empty()){
            ll top = q.front();
            q.pop();
            
            for(auto x:g[top]){
                mp[x]--;
                if(mp[x] ==0)
                    q.push(x);
            }
            
        }

        q.push(1);
        cnt[1] = 1;

        while(!q.empty()){
            ll top = q.front();
            q.pop();
            
            for(auto x:g[top]){
                mp[x]--;
                cnt[x] = cnt[x] + cnt[top];
                cnt[x]%=mod;
                if(mp[x] ==0)
                    q.push(x);
            }
            
        }

        cout << cnt[n];

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

    prune_topsort();
    return 0;
}