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
 
ll n,x,p; 
ll a[mxN];
 
 
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll l,r;
    cin >> n >> x;
    ll sum=0,m=0;
 
    map<ll,pll> mp;
 
    for(int i=0;i<n;i++) cin >> a[i];
 
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            mp[a[i]+a[j]] ={i,j};
 
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++){
            sum = a[i]+a[j];
 
            if(mp.find(x-sum) != mp.end()){
                pll p = mp[x-sum];
 
                if(p.f != i && p.f != j && p.s != i && p.s != j){
                    cout << i+1 <<" "<<j+1<<" "<<p.f+1<<" "<<p.s+1;
                    return 0;
                }
            }
        }
 
    cout <<"IMPOSSIBLE";
}