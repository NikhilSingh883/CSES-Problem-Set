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
 
ll arr[N],seg[4*N],lazy[4*N];
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

void update(ll node,ll st,ll en,ll l,ll r,ll val){

    if(lazy[node]!=0){
        ll num = en-st+1;
        ll dx = lazy[node];
        lazy[node]=0;
        seg[node] += dx*num;

        if(st!=en)
            lazy[2*node] += dx,lazy[2*node+1] += dx;
    }

    if(l > en || r < st) return;

    if(l<=st && r >=en){
        ll dx =0;
        ll num = en-st+1;
        dx=val*num;

        seg[node]+=dx;

        if(st!=en)
            lazy[2*node] += val,lazy[2*node+1] += val;
        return;
    }

    ll mid = (st + en)/2;

    update(2*node,st,mid,l,r,val);
    update(2*node+1,mid+1,en,l,r,val);

    seg[node] = seg[2*node]+seg[2*node+1];


}
 
ll query(ll node,ll st,ll en,ll l,ll r){

    if(lazy[node]!=0){
        ll num = en-st+1;
        ll dx = lazy[node];
        lazy[node]=0;
        seg[node] += dx*num;

        if(st!=en)
            lazy[2*node] += dx,lazy[2*node+1] += dx;
    }

    if(l > en || r < st) return 0;
 
    if(l<=st && r >=en) return seg[node];
 
    ll mid = (st+en)/2;
    return query(2*node,st,mid,l,r)+query(2*node+1,mid+1,en,l,r);
}
 
int main(){
    FAST;
 
    ll n,q,x,l,r,type,val;
    cin >> n >> q;
 
    rep(i,1,n+1)
        cin >> arr[i];
 
    build(1,1,n);
 
    while(q--){
        cin >> type;

        if(type == 2){
            cin >> l;
            cout << query(1,1,n,l,l) << endl;
        }
        else{
            cin >> l >> r >> val;
            update(1,1,n,l,r,val);
        }
    }
 
}