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
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))


ll binpow(ll a, ll b) {
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2)%mod;
    if (b % 2)
        return (res%mod * res%mod * a%mod)%mod;
    else
        return (res%mod * res%mod)%mod;
}

int main(){
 
    ll n;
    cin >> n;
    ll ans = binpow(2,n); 

    cout << ans << endl;

}