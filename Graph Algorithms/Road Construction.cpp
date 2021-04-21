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
#define ti tuple<ll,ll,ll>
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

v(p(ll,ll)) g;
v(ll) link(mxN,0);
v(ll) len(mxN,1);

ll n,m,k;
ll find(ll a){
    while(a!=link[a]) a=link[a];
    return a;
}


int main(){
    FAST;
 
    cin >> n >> m;

    sort(all(g));
    rep(i,1,n+1) link[i] = i;
    ll grp_cnt=n,mx_sz=1;

    rep(i,0,m){
        ll u , v;
        cin >> u >> v;
        ll pu = find(u);
        ll pv = find(v);
        if( pu != pv )
        {
            grp_cnt--;
            if( len[pu] > len[pv] ) swap(pu,pv);
            link[pu] = pv;
            len[pv] += len[pu];
            len[pu] = 0;
            mx_sz =  max( mx_sz, len[pv] );
        }

        cout << grp_cnt <<" "<< mx_sz << endl;
    }

    return 0;
}