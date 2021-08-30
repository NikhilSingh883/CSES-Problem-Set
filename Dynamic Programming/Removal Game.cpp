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
map<string,ll> dp;

ll func(ll i, ll j, vector<vector<ll>> &dp, v(ll) &a){
    if(i>j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    return dp[i][j]=max(
        a[i]+min(func(i+2,j,dp,a),
                    func(i+1,j-1,dp,a)
                ),
        a[j]+min(func(i,j-2,dp,a),
                    func(i+1,j-1,dp,a)
                )
    );
}

int main(){
    FAST;

    ll n;
    cin >> n;

    v(ll) coins(n);
    rep(i,0,n) cin >> coins[i];
    vector<vector<ll>> dp(n, vector<ll>(n,-1)); 

    cout << func(0,n-1,dp,coins);

}