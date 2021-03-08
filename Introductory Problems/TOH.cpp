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

void towerOfHanoi(ll n,ll A,ll B,ll C){
    if(n==1){
        cout << A <<" "<<B << endl;
        return;
    }
    towerOfHanoi(n-1,A,C,B);
    cout << A <<" "<<B << endl;
    towerOfHanoi(n-1,C,B,A);

}

int main(){
 
    ll n;
    cin >> n;
    ll A = 1,B=3,C=2;
    
    cout << pow(2,n) - 1 << endl;
     towerOfHanoi(n,A,B,C);

}