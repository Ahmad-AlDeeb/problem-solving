#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<unordered_set>
#include<map>
#include<bitset>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define F first
#define S second
#define dd double
#define ll long long
#define ld long double
#define pb push_back
#define all(v) v.begin(), v.end()
const ll inf = 1e17;
const ll M = 1e9+7;
ll power(ll x, ll y) {
    ll ans{1};
    while(y) {
        if(y&1) ans = ((ans%M)*(x%M)) % M;
        x = ((x%M) * (x%M)) %M;
        y/=2;
    }
    return ans;
}
vector<ll> di {1,-1,1,-1};
vector<ll> dj {1,1,-1,-1};



int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    while(t--) {
        ll n,q; cin >> n >> q;
        vector<ll>vec(n); for(auto &i:vec) cin >> i;
        vector<ll>my_sum(vec);
        for(ll i{1}; i<n; i++)
            my_sum[i] += my_sum[i-1];

        while(q--) {
            ll l,r,k; cin >> l >> r >> k; l--; r--;
            ll minus;
            if(!l) minus = my_sum[r];
            else minus = my_sum[r] - my_sum[l-1];
            ll cnt = l-r+1;
            if((my_sum.back() - minus + (cnt*k)) & 1)
                cout << "YES";
            else cout << "NO";
            cout << endl;
        }
    }
}
