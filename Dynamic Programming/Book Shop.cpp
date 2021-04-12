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

ll book(v(ll) price,v(ll) pages,ll n,ll X){

    ll dp[X+1];
    memset(dp,0,sizeof dp);
    
    rep(i,0,n)
        repb(j,X,price[i],1)
            dp[j] = max(dp[j],pages[i] + dp[j-price[i]]);
    
    return dp[X];
}
 
int main(){
    FAST;

    ll n,X;
    cin >>n >> X;
  
    v(ll) pri(n),pag(n);

    rep(i,0,n) cin >> pri[i];
    rep(i,0,n) cin >> pag[i];

    cout << book(pri,pag,n,X);

}