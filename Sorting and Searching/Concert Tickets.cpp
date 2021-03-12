#include <bits/stdc++.h> 
using namespace std;
#define ll long long int
#define pb push_back
#define endl '\n'
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define pii  pair<int,int>
#define f first
#define s second
#define pll pair<ll, ll>
#define v(x) vector<x>
#define mp make_pair
const ll mod = 1e9 + 7;
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))

bool comp(pll a,pll b){
    return a.first > b.first;
}

int main(){

    ll n,m,k;
    cin >> n >> m;
    multiset<ll,greater<ll>> tick;

    while(n--){
        cin >> k;
        tick.insert(k);
    }

    while (m--)
    {   cin >> k;
        auto it = tick.lower_bound(k);

        if(it == tick.end()) cout << "-1" << endl;
        else{
            cout << *it << endl;
            tick.erase(it);
        }
    }
    
    
}