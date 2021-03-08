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
#define vpl vector<pll>
#define vl vector<ll>
#define vll vector<ll, ll>
#define mp make_pair
const ll mxN = 2e5;
const ll mod = 1e9 + 7;
const ll N = 1005;
#define rep(x,start,end) for(ll x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vl a(n);
    rep(i,0,n) cin >> a[i];

    ll tot = 0;

    rep(i,0,n) tot += a[i];

    ll ans = INT_MAX;

    for(ll i=0;i< 1<<n;i++){
        ll sum =0;
        for(ll j=0;j<n;j++)
            if(i & 1<<j ) sum += a[j];

        ll t = abs(tot-2*sum);
        ans = min(ans,t);
    }

	cout << ans ;
    return 0;
}