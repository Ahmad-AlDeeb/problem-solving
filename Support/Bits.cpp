// Int to binary conversion
string binary = bitset<32>(n).to_string(); // 1st way
// or by dividing n by 2 and pushing back the remainder till n becomes 0 (2nd way)
// or (3rd way)
void print_bits(ll n, ll size) {
    if(!size) return;
    print_bits(n>>1, size-1);
    cout << (n&1);
}
void get_all_subsets(int size) {
    for(int i{}; i<(1<<size); i++) {
        print_bits(i,size);
        cout << endl;
    }
}
ll gray_code(ll n) {
    return n ^ (n>>1);
}
void get_all_subsets_gray(ll size) {
    for(ll i{}; i<(1<<size); i++) {
        print_bits(gray_code(i),size);
        cout << endl;
    }
}
void get_all_submasks(ll n) {
    for(ll sub{n}; sub; sub = (sub-1)&n)
        print_bits(sub, ones_cnt(n));
    // for reverse: ~sub & n = sub^n
}

/////////// count bits ////////////
ll bits_count(ll n) {
    return (ll)log2(n)+1;
}
ll ones_cnt(ll n) { // or use __builtin_popcount()
    ll cnt{};
    while(n) {
        n &= (n-1);
        cnt++;
    }
    return cnt;
}


// Other Important operations //
ll get_bit(ll n, ll i) {
    return ((n>>i) & 1);
}
ll set_bit1(ll num, int i) {
    return num | (1<<i);
}
ll set_bit0(ll num, int i) {
    return num & ~(1<<i);
}
ll flip_bit(ll num, int i) {
    return num ^ (1<<i);
}

///////// BIGGER Array for bigger visited numbers ! ////////////
bool VIS[10000000000/8];
void set_vis(ll n) {
    set_bit1(VIS[n>>3], VIS[1<<(n&7)]);
}
bool is_vis(ll n) {
    return get_bit(VIS[n>>3], VIS[1<<(n&7)]);
}

///////////////////// Bitset ///////////////////
ll n {10};
bitset<6> x (n);
x.set();
x.flip();
x.count();
x.any();
x.none();
x.test(1);
x.to_ullong();
// logic operators & assignment works!
cout << x << endl;
cout << x.to_string() << endl;
for(ll i=x.size()-1; i>=0; i--)
    cout << x[i];

///////// Get all subsets in strings to try all combination /////////
vector<string>subsets;
void print_bits(ll n, ll size) {
    reverse(all(sub));
    subsets.pb(sub);
    string sub;
    for(ll i{}; i<size; i++)
        sub += to_string(1 & (n>>i));
}
void get_subsets(ll size) {
    for(ll i{}; i<(1<<size); i++)
        print_bits(i,size);
}

///////////////////// My New Function ///////////////////
ll get_fullset(ll n) {
    for(ll i{};;i++)
        if(pow(2,i) > n)
            return pow(2,i)-1;
}
