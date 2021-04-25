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
void update(ll idx,ll val,ll n){
    while(idx<=n){
        seg[idx] ^= val;
        idx += idx &(-idx);
    }
}

ll prefixXor(ll idx){
    ll _xor =0;
    while(idx>0){
        _xor ^= seg[idx];
        idx -= idx &(-idx);
    }
    return _xor;
}

ll query(ll l,ll r){
    return prefixXor(r) ^ prefixXor(l-1);
}

int main(){
    FAST;

    ll n,q,x,l,r;
    cin >> n >> q;

    rep(i,1,n+1) {
        cin >> x;
        update(i,x,n);
    }

    while(q--){
        cin >> l >> r;
        cout << query(l,r) << endl;
    }

}