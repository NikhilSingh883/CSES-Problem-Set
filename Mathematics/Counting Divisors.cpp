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
const ll mxN = 2e5;
const ll mod = 1e9 + 7;
const ll N = 1e6+5;
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define repf(x,start,end,k) for(auto x = start;x<=end;x+=k)
v(ll) spf(N);

void seive(){

    rep(i,0,N) spf[i] = i;

    repf(i,2,sqrt(N),1)
        if(spf[i] == i)
            repf(j,i*i,N,i)
                if(spf[j] == j) 
                    spf[j] = i;
}

void solve(){
    ll n;
    cin >> n;
    ll ans = 1;
    while(n!=1){
        ll d= spf[n];
        ll c= 1;
        while(n%d ==0){
            c++;
            n/=d;
        }
        ans *= c;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;

    seive();

    while(t--){
        solve();
    }
}