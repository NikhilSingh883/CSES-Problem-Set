

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
#define v(x) vector<x>
#define mp make_pair
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const ll mxN = 2e5;
const ll mod = 1e9 + 7;
const ll N = 6;
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define repf(x,start,end,k) for(auto x = start;x<=end;x+=k)
#define repb(x,start,end,k) for(auto x = start;x>=end;x-=k)
bool cmp(pll a,pll b){
    return a.first > b.first;
}
int main(){   

    FAST;
    ll n,x,m,left,right;
    cin >> x >> n;

    multiset<ll> len ={x};
    set<ll> points = {0,x};

    rep(i,0,n){
        cin >> m;

        auto it = points.upper_bound(m);

        left = *prev(it);
        right = *it;

        len.erase(len.find(right-left));
        len.insert(m-left);
        len.insert(right-m);

        points.insert(it,m);

        cout << *len.rbegin() <<" ";

    }

}