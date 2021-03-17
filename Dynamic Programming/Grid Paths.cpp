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

ll paths(v(string) grid,ll n){
 
	if(grid[0][0]=='*') return 0;
	
    ll dp[n][n];
    memset(dp,0,sizeof dp);
	dp[0][0] = 1;
 
	for(int i=1;i<n;i++){
		if(grid[i][0] =='.')
			dp[i][0] += dp[i-1][0];
		else break;
	}
 
	for(int i=1;i<n;i++){
		if(grid[0][i] =='.')
			dp[0][i] += dp[0][i-1];
		else break;
	}
 
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			if(grid[i][j]=='.'){
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
				dp[i][j]%=mod;
			}
		}
	}
 
	return dp[n-1][n-1]%mod;
}
 
int main(){
    FAST;

    ll n;cin >> n;

    v(string) p(n);
    rep(i,0,n) cin >> p[i];

    cout << paths(p,n);

}