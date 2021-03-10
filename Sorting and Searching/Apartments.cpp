#include <bits/stdc++.h> 
using namespace std;
#define ll long long int
#define pb push_back
#define endl '\n'
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define pii  pair<int,int>
#define f first
#define s second
#define pll pair<ll, ll>
#define vpl vector<pll>
#define v(x) vector<x>
#define s(x) set<x>
#define mp make_pair
const ll mod = 1e9 + 7;
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))


int main(){

    ll n,m,k;
    cin >> n >> m >> k;

    v(ll) a(n);
    v(ll) b(m);

    rep(i,0,n) cin >> a[i];
    rep(i,0,m) cin >> b[i];

    sort(all(b));sort(all(a));

    ll ans =0;
    ll j=0,i=0;

    while(i<n && j<m){
        if(abs(a[i]-b[j]) > k ){
            if(b[j] < a[i]) j++;
            else i++;
        }
        else {
            i++,j++;
            ans++;
        }
    }

    cout << ans << endl;
}