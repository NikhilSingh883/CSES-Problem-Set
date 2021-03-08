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
#define vpl vector<pll>
#define v(x) vector<x>
#define s(x) set<x>
#define mp make_pair
const ll mxN = 2e5;
const ll mod = 1e9 + 7;
const ll N = 1005;
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
s(string) per;

void permutation(ll idx,string p,ll n){

    per.insert(p);

    if(idx==n) return;

    for(int i=idx;i<n;i++){
        swap(p[i],p[idx]);
        permutation(idx+1,p,n);
        swap(p[i],p[idx]);
    }
}
int main(){
 
    ll n;
    string str;
    cin >> str;
    n = str.size();

    permutation(0,str,n);

    cout << per.size() << endl;

    for(auto it:per) cout << it << endl;
 
}