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
 
int main(){
    FAST;

    ll n,m;cin >> n >> m;
    vector<vector<ll>> dp (n+1,vector<ll>(m+1));

    repf(i,0,n,1)
        repf(j,0,m,1){
            if(i==j) dp[i][j] = 0;
            else dp[i][j] = LLONG_MAX;

            rep(k,1,i) dp[i][j] = min(dp[i][j],1 + dp[k][j] + dp[i-k][j]);
            rep(k,1,j) dp[i][j] = min(dp[i][j],1 + dp[i][k] + dp[i][j-k]);
        }
    
    cout << dp[n][m];

}