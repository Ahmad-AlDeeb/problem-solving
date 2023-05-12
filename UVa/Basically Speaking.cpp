#include<iostream>
#include <cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<sstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<long long, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define F first
#define S second
#define dd double
#define ll long long
#define ld long double
#define pb push_back
#define all(v) v.begin(), v.end()
const ll inf = 1e18;
const ll M = 1e9+7;
const ll SZ = 200005;
vector<ll> di {0,0,1,-1};
vector<ll> dj {1,-1,0,0};
string letters{" abcdefghijklmnopqrstuvwxyz"};
const ld PI = 3.14159265358979323846;

ll power(ll x, ll y) {
    ll ans{1};
    while(y) {
        if(y&1) ans = ((ans%inf)*(x%inf)) % inf;
        x = ((x%inf) * (x%inf)) %inf;
        y/=2;
    }
    return ans;
}
ll gcd(ll a, ll b) {
    if(b != 0) return gcd(b, a%b);
    else return a;
}
ll lcm(ll a, ll b) {
    return a*b / gcd(a,b);
}
ld distance(ll x1, ll y1, ll x2, ll y2) {
    return sqrt(pow((x1-x2),2) + pow((y1-y2),2));
}
vector<ll> p_fact(ll x) { // 1e12
    vector<ll> p;
    if(!x || x==1) return p;

    ll i{2};
    for(; i*i <= x; i++) {
        if(x%i == 0) p.pb(i);
        while(x%i == 0) x /= i;
    }
    if(x != 1) p.push_back(x);
    return p;
}
bool is_int(dd double_num) {
    int int_num = double_num;
    return int_num == double_num;
}
bool is_prime(ll x) {
    for(ll i{2}; i*i<=x; i++)
        if(x%i == 0) return false;
    return true;
}
int comp_double(ld a, ld b) {
    if(fabs(a-b) <= 1e-10) return -1;
    return a>b? 1:0;
}
vector<ll> sieve(ll n) {
    vector<bool>primes(n+1,true);
    for(ll i{2}; i*i<=n; i++)
        if(primes[i])
            for(ll j{i*i}; j<=n; j+=i)
                primes[j]=false;

    vector<ll>ans;
    for(ll i{2}; i<=n; i++)
        if(primes[i]) ans.pb(i);
    return ans;
}
void coordinate_compress(vector<ll>&axis, ll start=2, ll step=2) {
    set<ll> s (axis.begin(), axis.end());
    map<ll,ll> index;

    ll i{};
    for(auto val:s)
        index[val] = start + (step * i++);

    for(auto &val:axis)
        val = index[val];
}
void coordinate_compress(vector<ll> &axis, vector<ll> &values, map<ll,ll> &index, ll start=2, ll step=2) {
    for(auto &val:axis)
        index[val] = 0;
    values.resize(start + step*axis.size());

    ll i{};
    for(auto &p:index) {
        p.S = start + (step * i++);
        values[p.S] = p.F;
    }

    for(auto &val:axis)
        val = index[val];
}
ll BS(ll left, ll right, ll val, bool first) {
    while(left < right) {
        ll mid = left + (right - left + 1) / 2;
        if(mid < val) left = mid + 1;
        else if(mid > val) right = mid - 1;
        else {
            if(first) right = mid;
            else left = mid;
        }
    }
    return left;
}
ld BS(ld left, ld right, ld val) {
    while(fabs(right-left) > 10e-7) {
        ld mid = (left+right)/2;
        if(mid < val) left = mid;
        else right = mid;
    }
    return left;
}
vector<ll> get_divisors(ll x) {
    vector<ll>div;
    for(int i{1}; i*i<=x; i++)
        if(x%i == 0) {
            div.pb(i);
            if(i*i != x) div.pb(x/i);
        }
    return div;
}
vector<vector<ll>> get_multiplies(ll x) { // 2*1e6
    vector<vector<ll>> multi(x+1);
    for(ll div{}; div<=x; div++)
        for(ll i{div}; i<=x; i+=div)
            multi[i].pb(div);
    return multi;
}
/////////////////////////////////////////////////////////////////////////////////////
map<char,ll> dig;
map<ll,char> letter;

void fast() {
    dig['0']=0, dig['1']=1, dig['2']=2, dig['3']=3, dig['4']=4, dig['5']=5, dig['6']=6, dig['7']=7, dig['8']=8, dig['9']=9,
    dig['A']=10, dig['B']=11, dig['C']=12, dig['D']=13, dig['E']=14, dig['F']=15;
    letter[10]='A', letter[11]='B', letter[12]='C', letter[13]='D', letter[14]='E', letter[15]='F';

    string num; ll from,to;
    while(cin >> num >> from >> to) {
        cout << right << setw(7);
        bool leading{true};
        string new_num;
        for(auto c:num) {
            if(c!='0') leading=false;
            if(c=='0' && leading) continue;
            new_num.pb(c);
        }
        num = new_num;
        if(num.empty()) {cout << 0 << endl; continue;}


        if(from != 10) {
            ll base10{};
            for(ll i=num.size()-1, exp{}; i>=0; i--)
                base10 += power(from,exp++) * dig[num[i]];
            num = to_string(base10);
        }
        if(to != 10) {
            string converted;
            ll n = stoi(num);
            while(n) {
                ll digit = n%to;
                if(digit > 9)
                    converted += letter[digit];
                else converted += to_string(digit);
                n /= to;
            }
            reverse(all(converted));
            num = converted;
        }

        if(num.size()<=7) cout << num;
        else cout << "ERROR";
        cout << endl;
    }
}
/////////////////////////////////////////////////////////////////////////////////////
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); freopen("error.txt", "w", stderr);
#endif
    ll tc{1};
//    cin >> tc;
    while(tc--) {
        fast();
//        cout << endl;
    }
}
