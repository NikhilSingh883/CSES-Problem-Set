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

ll ways(ll sum){
    v(ll) dice{1,2,3,4,5,6};

    v(ll) dp(sum+1,0);

    dp[0] = 1;

    repf(i,1,sum,1)
        for(ll x: dice)
            if(i>=x)
                dp[i] = (dp[i-x]%mod + dp[i]%mod)%mod;

    return dp[sum];
        
}
 
int main(){
    FAST;

    ll n;cin >> n;

    cout << ways(n) << endl;

}