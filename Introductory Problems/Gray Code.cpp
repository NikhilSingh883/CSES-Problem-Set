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
#define vl vector<ll>
#define vll vector<ll, ll>
#define mp make_pair
const ll mxN = 2e5;
const ll mod = 1e9 + 7;
const ll N = 1005;
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
 
int main(){
 
    ll n;
    cin >> n;
     
    for(int i=0;i<pow(2,n);i++){
        ll X = (i/2)^i;
        string str;
 
        for(int j=n-1;j>=0;j--)
            if(1<<j & X) str += '1';
            else str += '0';
 
        cout << str << endl;
    }
 
}