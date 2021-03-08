#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
const ll mxN = 2e5;
const ll mod = 1e9 + 7;
const ll N = 1005;
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x-=-))


int main(){
 
    ll t;
    cin >> t;

    while(t--){
        ll row,col;
        cin >> row >> col;

        ll num,ans;

        if(row>=col){
            if(row%2==0){
                num = row * row;
                ans = num - col + 1;
            }
            else {
                num = 1 + (row-1)*(row-1);
                ans = num + col -1;
            }
        }
        else {
            if(col%2){
                num = col*col;
                ans = num -row + 1;
            }
            else {
                num = 1 + (col-1)*(col-1);
                ans = num + row-1;
            }
        }

        cout << ans << endl;
        
    }
}