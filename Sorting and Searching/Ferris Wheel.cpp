#include <bits/stdc++.h> 
using namespace std;
#define ll long long int
#define pb push_back
#define endl '\n'
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define pii  pair<int,int>
#define f first
#define s second
#define pll pair<ll, ll>
#define vpl vector<pll>
#define v(x) vector<x>
#define mp make_pair
const ll mod = 1e9 + 7;
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))


int main(){

    ll n,m,k;
    cin >> n >> m;

    v(ll) a(n);

    rep(i,0,n) cin >> a[i];


    sort(all(a));

    ll i=0,j=n-1;
    ll ans =0;
    
    while(i<=j){
        if(i==j){
            i++;j--;
            continue;
        }
        if(a[i] + a[j] <= m){
            i++;j--;
        }
        else
            j--;
        
        ans++;

    }

    cout << ans <<endl;

}