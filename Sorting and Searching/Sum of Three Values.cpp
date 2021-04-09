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
#define pii pair<ll, ll>
#define vpi vector<pii>
#define vi vector<ll>
#define vii vector<ll, ll>
#define mp make_pair
const ll mxN = 2e5;
const ll mod = 1e9 + 7;
 
ll n,x,p; 
ll a[mxN];
 
 
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll l,r;
    cin >> n >> x;
    ll sum=0,m=0;
    vpi v;
 
    for(ll i=0;i<n;i++){
        cin >> p;
        v.pb({p,i+1});
    }
 
    sort(all(v));
    
    for(int i=0;i<n-2;i++){
        l = i+1;
        r = n-1;
 
        while(l<r){
            if(v[i].f + v[l].f +v[r].f  ==  x){
                cout << v[i].s <<" " << v[l].s<<" " << v[r].s ;
                return 0;
            }
            else if(v[i].f + v[l].f +v[r].f  >  x)
                r--;
            else 
                l++;
        }
    }
    cout <<"IMPOSSIBLE";
}