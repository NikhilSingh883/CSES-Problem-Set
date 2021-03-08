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

    vl a,b;

    ll sum = (n*(n+1))/2;

    if(sum%2) cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        ll s1=0,s2=0;

        for(int i=n;i>0;i--){
            if(s1<=s2){
                s1 += i;
                a.pb(i);
            }
            else{
                s2 += i;
                b.pb(i);
            }
        }

        cout << a.size() << endl;
        for(auto x:a) cout <<x <<" ";
        cout << endl;
        cout << b.size() << endl;
        for(auto x:b) cout <<x <<" ";

    }

}