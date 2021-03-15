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
const ll N = 1e6+5;
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define repf(x,start,end,k) for(auto x = start;x<=end;x+=k)
#define repb(x,start,end,k) for(auto x = start;x>=end;x-=k)
v(ll) C(N+1,0);
 
void solve(){
    ll n,x;
    cin >> n;
 
    rep(i,0,n){
        cin >> x;
        C[x]++;
    }
 
    repb(i,N,0,1){
        ll d=0;
        repf(j,i,N,i)
            d += C[j];
 
        if(d > 1){
            cout << i;
            return;
        }
    }
}
 
int main(){
    FAST;
    solve();

}