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

int remGame(bool turn,v(ll) )

int main(){
    FAST;

    ll n;
    cin >> n;

    v(ll) coins(n);
    rep(i,0,n) cin >> coins[i];

    ll sum =0;
    rep(i,0,n) sum += coins[i];
    bool dp[n+1][sum+1];

    rep(i,0,n+1) dp[i][0] = true;
    rep(i,1,sum+1) dp[0][i] = false;

    rep(i,1,n+1)
        rep(j,1,sum+1){
            if(j < coins[i-1]) dp[i][j] = dp[i-1][j];
            if(j >= coins[i-1]) dp[i][j] = dp[i-1][j] || dp[i-1][j-coins[i-1]];
        }
    v(ll) ans;
    rep(i,1,sum+1) if(dp[n][i]) ans.pb(i);

    cout << ans.size() <<endl;

    for(auto x:ans) cout <<x<<" "; 

}