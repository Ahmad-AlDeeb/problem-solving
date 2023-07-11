void coordinate_compress(vll &axis, ll start=2, ll step=2) {
    set<ll> s (axis.begin(), axis.end());
    map<ll,ll> index;

    ll i{};
    for(auto val:s)
        index[val] = start + (step * i++);

    for(auto &val:axis)
        val = index[val];
}
void coordinate_compress(vll &axis, vll &values, map<ll,ll> &index, ll start=2, ll step=2) {
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
pair<ld,ld> quad(ld a, ld b, ld c) {
    ld sq = sqrt(pow(b,2LL)-4*a*c);
    return {-b+(sq)/2*a, -b-(sq)/2*a};
}
// Difference between 2 squares
ll a,b;
void get_squares(ll n) {
    for(ll i = sqrt(n); i >= 1; i--)
        if(n%i == 0) {
            ll c = i;   //a-b
            ll d = n/i; //a+b
            if((c+d)%2 == 0 && (c-d)%2 == 0) {
                a = (c + d) / 2;
                b = (d - c) / 2;
                return;
            }
        }
}