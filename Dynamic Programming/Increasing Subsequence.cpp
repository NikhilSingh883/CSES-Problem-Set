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
const ll mxN = 2e5;
const ll mod = 1e9 + 7;
const ll N = 6;
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define repf(x,start,end,k) for(auto x = start;x<=end;x+=k)
#define repb(x,start,end,k) for(auto x = start;x>=end;x-=k)


ll lcs(){
    ll n;
    cin >> n;

    v(ll) a(n);
    rep(i,0,n) cin >> a[i];

    v(ll) tail(n,0);
    tail[0] = a[0];
    ll length = 1;

    rep(i,1,n){

        auto it = lower_bound(tail.begin(),tail.begin()+length,a[i]);

        if(it == tail.begin()+length) tail[length++] = a[i];
        else *it = a[i]; 
    }

    return length;
}

int main(){
    FAST;

    cout << lcs();
}