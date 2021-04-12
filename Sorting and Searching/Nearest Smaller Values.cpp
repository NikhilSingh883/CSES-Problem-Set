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
 
void prevSmaller(int n){
    stack<int> s;
 
    for(int i=0;i<n;i++){
        
        while(!s.empty() && a[s.top()] >= a[i])
            s.pop();
 
        if(s.empty()) cout << 0 <<" ";
        else cout << s.top() + 1  <<" ";
 
        s.push(i);
    }
}
 
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    ll n;
    cin >> n;
 
    for(int i=0;i<n;i++) cin >> a[i];
 
    prevSmaller(n);
    
 
 
}