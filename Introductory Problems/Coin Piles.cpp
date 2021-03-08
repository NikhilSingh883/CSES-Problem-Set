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
 
    ll t;
    cin >> t;

    while(t--){
        ll a,b;
        cin >>a >>b;

        
        ll d = max(a,b) - min(a,b);

        d--;

        if(a>=b) {
            a-=2*d;
            b-=d;
        }
        else{
            b -=2*d;
            a-=d;
        }
        
        if(a < 0 || b <0){
            cout << "NO" << endl;
            continue;
        }
        if(a==b){ 
            if(a%3==0)
                cout << "YES" << endl;
            else 
                cout << "NO" << endl;
        }
        else if((a%3==0 && b%3) || (a%3 && b%3==0))
            cout << "NO" << endl;
        else if(a%3 && b%3)
            cout << "YES" << endl;

    }

}