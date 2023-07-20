#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define ld long double
#define F first
#define S second
#define vll vector<long long>
#define pb push_back
#define all(v) v.begin(), v.end()
///////////////////////////////////
const vll di {0,0,1,-1};
const vll dj {1,-1,0,0};
const string letters{"abcdefghijklmnopqrstuvwxyz"};
const ll MAX = 1e18;
const ll M = 1e9+7;
const ld EPS = 1e-19;
const ll SZ {101};
const ld PI = 3.14159265358979323846;
ll pow(ll x, ll y) {
    ll ans{1};
    while(y) {
        if(y&1) ans *= x;
        x *= x;
        y /= 2;
    }
    return ans;
}
ll big_pow(ll x, ll y) {
    ll ans{1};
    while(y) {
        if(y&1) ans = ((ans%M)*(x%M)) % M;
        x = ((x%M) * (x%M)) %M;
        y/=2;
    }
    return ans;
}
bool is_int(ld num) {
    return num == (ll)num;
}
int cmp_d(ld a, ld b) {
    if(fabs(a-b) <= EPS) return -1;
    return a>b? 1:0;
}
ll mod(ll x, ll m){
    return (x%m +m) % m;
}
///////////////////////////////////////////////// ===== Solution ===== /////////////////////////////////////////////////
ll n,k;
bool valid(ll x, vll &v) {
    ll sum{};
    for(ll i{}; i<n; i++)
        sum += min(v[i],x);
    return sum >= k*x;
}
void fast() {
    cin >> k >> n;
    vll v(n); for(auto &i:v) cin >> i;

    ll l{},r = 50000000000, ans{};
    while(l<=r) {
        ll mid = l+(r-l)/2;
        if(valid(mid,v)) l=mid+1, ans=mid;
        else r=mid-1;
    }
    cout << ans;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ll tc{1};
//    cin >> tc;
    while(tc--) {
        fast();
//        cout << endl;
    }
}
