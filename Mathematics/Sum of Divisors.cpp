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
const ll N = 1e6+5;
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define repf(x,start,end,k) for(auto x = start;x<=end;x+=k)
#define repb(x,start,end,k) for(auto x = start;x>=end;x-=k)

ll exp(ll x,ll y, ll p){
    ll res=1; x=x%p;
    while(y>0){
        if (y&1) res= (res*x)%p; y=y>>1; x=(x*x)%p;
    }
    return res;
}
void solve(){
    //calculte in two parts
    //1st - contribution of each number upto sqrt(n)
    //2nd - from sqrt(n) to n calculate how many numbers give 1, 2, 3...sqrt(n) contribution
    ll n; cin>>n;
    ll s = 0;
    ll sq = sqrt(n);
    ll inv = exp(2,mod-2,mod);
    for (ll i = 1; i <= sq; i++) {
        ll x = (n/i - n/(i+1))%mod;
        ll r = n/i, l = n/(i+1) + 1;
        s = ( s + x*((l+r)%mod)%mod*inv%mod*i%mod)%mod;
    }
    for (ll i = 1; i <= n/(sq+1); i++) {
        s = (s + n/i*i) % mod; 
    }
    cout<< s;
}
 
int main(){
    FAST;
    solve();
}