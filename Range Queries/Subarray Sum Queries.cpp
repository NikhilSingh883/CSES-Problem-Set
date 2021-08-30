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
#define tll tuple<ll,ll,ll>
#define v(x) vector<x>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const ll mxN = 2e5+5;
const ll mod = 1e9 + 7;
const ll N = 2e5+5;
const ll oo = 1e15;
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define repf(x,start,end,k) for(auto x = start;x<=end;x+=k)
#define repb(x,start,end,k) for(auto x = start;x>=end;x-=k)

ll arr[N],seg[4*N];
void build(ll node,ll st,ll en){
    if(st == en){
        seg[node] = arr[st];
        return;
    }

    ll mid = (st+en)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,en);

    seg[node] = seg[2*node]+seg[2*node+1];
}

void update(ll node,ll st,ll en,ll val,ll idx){
    if(st == en){
        seg[node] = val;
        arr[idx] = val;
        return;
    }

    ll mid = (st + en)/2;

    if(idx<=mid) update(2*node,st,mid,val,idx);
    else update(2*node+1,mid+1,en,val,idx);

    seg[node] = seg[2*node]+seg[2*node+1];

}

ll query(ll node,ll st,ll en,ll l,ll r){
    if(l > en || r < st) return 0;

    if(l<=st && r >=en) return seg[node];

    ll mid = (st+en)/2;
    return query(2*node,st,mid,l,r)+query(2*node+1,mid+1,en,l,r);
}

int main(){
    FAST;

    ll n,q,l,r,type;
    cin >> n >> q;

    rep(i,1,n+1)
        cin >> arr[i];

    build(1,1,n);

    while(q--){
        cin >> type >> l >> r;

        if(type == 1)
            update(1,1,n,r,l);
        else cout << query(1,1,n,l,r) << endl;
    }

}