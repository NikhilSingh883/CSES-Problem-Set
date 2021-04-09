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
#define vi vector<ll>
#define vii vector<ll, ll>
#define pii pair<ll, ll>
#define mp make_pair
const ll mxN = 2e5;
const ll mod = 1e9 + 7;
 
ll n,x; 
ll a[mxN];
 
 
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll l,r;
    cin >> n;
    ll sum=0,m=0;
 
    for(int i=0;i<n;i++){
        cin >> x;
        sum += x;
        m = max(m,x);
    }
 
    cout << max(sum,2LL*m);
}