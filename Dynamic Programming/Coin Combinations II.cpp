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

ll minCoins(v(ll) coins,ll sum,ll n){

    v(ll) dp(sum+1,0);
    dp[0] = 1;

    for (auto c : coins) 
        for(int i=c;i<=sum;i++){
                dp[i] += dp[i-c];
                dp[i]%=mod;
    }
    return dp[sum];
}
 
int main(){
    FAST;

    ll n;cin >> n;
    ll sum;cin >> sum;

    v(ll) coins(n);

    rep(i,0,n) cin >> coins[i];

    cout << minCoins(coins,sum,n) << endl;

}