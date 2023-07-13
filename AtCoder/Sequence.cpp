#include <bits/stdc++.h>
#include <cctype>
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
const ll MAX = 1e18;
const ll M = 1e9+7;
const ld EPS = 1e-19;
const ll SZ {101};
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
//////////////////////////////////
ll mod_pow(ll b, ll p, ll m) {
    if(!p) return 1;

    ll ans = mod_pow(b,p/2,m);
    ans = mod(ans*ans,m);

    if(p&1) ans = mod(ans*b,m);
    return ans;
}
const ll P = 1e9+7;
ll inv(ll a) {
    return mod_pow(a,P-2,P);
}
ll Fact[100010];
ll C(ll n, ll k) {
    if(n<k) return 0;
    return ( ((Fact[n]*inv(Fact[k]))%P) * inv(Fact[n-k]) ) % P;
}
void ini_fact() { // O(n)
    Fact[0]=1;
    for(ll i{1}; i<100010; i++)
        Fact[i] = (Fact[i-1]*i) % P;
}
ll comb(ll n, ll r) {
    ll ans{1}, div{1};
    for(ll i{r+1}; i<=n; i++) {
        ans *= i;
        ans /= div;
        div++;
    }
    return ans%P;
}
///////////////////////////////////////////////// ===== Solution ===== /////////////////////////////////////////////////
void fast() {
    ll n; cin >> n;
    vll v1(n); for(auto &i:v1) cin >> i;
    vll v2(v1);

    ll ans1{};
    if(v1.front()<=0) ans1+=abs(v1[0])+1, v1[0]=1;
    for(ll i{1}; i<n; i++) {
        v1[i] += v1[i-1];
        if(i&1) {
            if(v1[i]>=0)  ans1+=v1[i]+1, v1[i]=-1;
        }
        else {
            if(v1[i]<=0) ans1+=abs(v1[i])+1, v1[i]=1;
        }
    }

    ll ans2{};
    if(v2[0]>=0)  ans2+=v2[0]+1, v2[0]=-1;
    for(ll i{1}; i<n; i++) {
        v2[i] += v2[i-1];
        if(i&1) {
            if(v2[i]<=0) ans2+=abs(v2[i])+1, v2[i]=1;
        }
        else {
            if(v2[i]>=0)  ans2+=v2[i]+1, v2[i]=-1;
        }
    }

    cout << min(ans1,ans2);
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

