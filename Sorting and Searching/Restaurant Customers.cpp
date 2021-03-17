

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
  
int main(){   
    int n; 
    cin >> n;
        vector<pi> vals;
        for (int i = 0; i < n; i++) {
                int l, r; 
            cin >> l >> r;
            vals.pb(mp(l, 1));
            vals.pb(mp(r, -1));
        }
 
 
    sort(all(vals)); 
 
 
    int sum = 0;
        int ans = 0;
        for (auto x : vals) {
                sum += x.s;
            ans = max(ans, sum);
        }
        cout << ans << '\n';
}