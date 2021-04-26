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

ll expo(ll base, ll pow) {
	ll ans = 1;
	while (pow) {
		if (pow & 1) ans = ans * base % mod;
		base = base * base % mod;
		pow >>= 1;
	}
	return ans;
}

ll p[100001], k[100001];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i] >> k[i];
	ll div_cnt = 1, div_sum = 1, div_prod = 1, div_cnt2 = 1;
	for (int i = 0; i < n; i++) {
		div_cnt = div_cnt * (k[i] + 1) % mod;
		div_sum = div_sum * (expo(p[i], k[i] + 1) - 1) % mod * expo(p[i] - 1, mod - 2) % mod;
		div_prod = expo(div_prod, k[i] + 1) * expo(expo(p[i], (k[i] * (k[i] + 1) / 2)), div_cnt2) % mod;
		div_cnt2 = div_cnt2 * (k[i] + 1) % (mod - 1);
	}
	cout << div_cnt << ' ' << div_sum << ' ' << div_prod;
	return 0;
}