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
 
ll n,x,m; 
ll a[mxN];
 
 
bool cmp(pii a,pii b){
    if(a.f < b.f) 
        return true;
    else if(a.f == b.f){
        return a.s > b.s;
    }
    else 
        return false;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll l,r;
    cin >> n;
 
    vector<pii> v;
 
    for(int i=0;i<n;i++){
        cin >> l >> r;
 
        v.pb({l,r});
    }
    sort(all(v),cmp);
 
    ll ans =0;
    ll time  =0;
    for(auto x:v){
        time += x.f;
 
        ans += (x.s - time);
 
        // cout << x.f <<" "<<x.s<<endl;
    }
 
    cout << ans;
}