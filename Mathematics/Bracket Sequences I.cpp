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
const ll mxN = 2000001;
const ll mod = 1e9 + 7;
const ll N = 2e5+5;
const ll oo = 1e15;
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define repf(x,start,end,k) for(auto x = start;x<=end;x+=k)
#define repb(x,start,end,k) for(auto x = start;x>=end;x-=k)

ll fac[mxN];
ll inv[mxN];

ll expo(ll base, ll pow,ll md) {
	ll ans = 1;
	while (pow) {
		if (pow & 1) ans = ans * base % md;
		base = base * base % md;
		pow >>= 1;
	}
	return ans;
}

int main() {
	FAST;

    fac[0] =1;
    inv[0] =1;
    rep(i,1,mxN){
        fac[i] = fac[i-1]*i%mod;
        inv[i] = expo(fac[i],mod-2,mod);
    }

    ll n;
    cin >>n;

    cout << fac[2*n]%mod *inv[n]%mod*inv[n]%mod*expo(2,mod-2,mod)%mod*expo(n+1,mod-2,mod)%mod;

	return 0;
}