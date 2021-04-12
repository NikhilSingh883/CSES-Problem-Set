#include <bits/stdc++.h> 
using namespace std;
#define ll long long int
#define pb push_back
#define rsz resize
#define endl '\n'
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define pi  pair<ll,ll>
#define f first
#define s second
#define pll pair<ll, ll>
#define vpl vector<pii>
#define vl vector<ll>
#define vll vector<ll, ll>
#define mp make_pair
const ll mxN = 2e5;
const ll mod = 1e9 + 7;
 
ll a[mxN];
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    ll n,X,m;
    cin >> n ;
    map<ll,ll> mp;
    mp[0]++;
    ll s=0,ans=0;
 
    for(int i=0;i<n;i++){
        cin >> m;
        s= (s + m%n +n)%n;
        ans += mp[s];
        mp[s] ++;
    }
 
    cout << ans ;
 
}