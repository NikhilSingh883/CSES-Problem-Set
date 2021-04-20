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
v(ll) dist(mxN);
v(ll) par(mxN,-1);
edge ee[mxN];
v(ll) ans;
ll n,m,k;

void dijkstra(){
    priority_queue<p(ll,ll),v(p(ll,ll)),greater<p(ll,ll)>> pq;

    pq.push({0,1});
    dist[1] = 0;
    v(ll) count(n+1,0);
    ll cnt = k;
    while(!pq.empty() && count[n]<k){
        ll node = pq.top().y;
        ll cost = pq.top().x;
        pq.pop();

        count[node]++;
        if(node == n) ans.pb(cost);
    // Important observaion here is k is very small (k<10) and
    // if you want to find k routes each vertex is visited atmax k times in k routes.
    // so it is someting like dijkstra you keep CNT array were you keep count of each node
    // and take a min heap(set or priority queue in cpp) and insert 1st node with cost 0
    // in it. Now let say p is smallest node in heap. increase count of p in CNT array
    // if it is more than k then continue to next iteration.if p is last node add cost
    // to ANS array.now iterate through all edges of p and add child with cost p.cost + edge weight
    // in the heap.
        if(count[node]<=k){ 
            for(auto aa:g[node]){
                pq.push({cost + aa.y,aa.x});
            }
        }
    }

}

int main(){
    FAST;
 
    cin >> n >>m >> k;
    
    rep(i,0,m){
        ll u,v,w;
        cin >> u >> v >> w;
        g[u].pb({v,w});
    }
    dijkstra();
    sort(all(ans));

    // cout << ans.size();
    for(int i=0;i<min(k,(ll)ans.size());i++) cout << ans[i] <<" ";
    return 0;
}