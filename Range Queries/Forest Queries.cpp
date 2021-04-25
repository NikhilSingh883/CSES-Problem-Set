#include <bits/stdc++.h> 
using namespace std;
#define ll long long int
#define pb push_back
#define rsz resize
#define endl '\n'
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define pi  pair<int,int>
#define x first
#define y second
#define p(x,y) pair<x, y>
#define tll tuple<ll,ll,ll>
#define v(x) vector<x>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const ll mxN = 2e5+5;
const ll mod = 1e9 + 7;
const ll N = 2e5+5;
const ll oo = 1e15;
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define repf(x,start,end,k) for(auto x = start;x<=end;x+=k)
#define repb(x,start,end,k) for(auto x = start;x>=end;x-=k)
 
ll dp[1001][1001];
 
int main(){
    FAST;
 
    ll n,q,l,r,type,val,m;
    cin >> n >> m;
    char ch;
    rep(i,1,n+1)
        rep(j,1,n+1){
            cin >> ch;
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + (ch=='*');
    }
    ll x1,x2,y1,y2;
    while(m--){
        cin >> x1 >> y1 >> x2 >> y2;

        cout << dp[x2][y2] + dp[x1-1][y1-1] - dp[x2][y1-1] - dp[x1-1][y2] << endl;
    }
 
}