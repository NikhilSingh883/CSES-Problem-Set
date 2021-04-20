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

ll ways(ll n){
    ll sum = (n*(n+1))/2;
    if(sum%2) return 0;
    else sum/=2;

    ll dp[n+1][sum+1];
    memset(dp,0,sizeof dp);
    dp[0][0] = 1;

    rep(i,1,n)
        repf(j,0,sum,1){
            if(j < i) dp[i][j] = dp[i-1][j];
            else dp[i][j] = (dp[i-1][j] + dp[i-1][j-i])%mod;
    }

    return dp[n-1][sum]%mod;
}

int main(){
    FAST;

    ll n;
    cin >> n;

    cout << ways(n);
}