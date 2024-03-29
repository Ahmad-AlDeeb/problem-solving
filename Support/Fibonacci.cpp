const ld G_pos = (1+sqrt(5))/2;
const ld G_neg = (1-sqrt(5))/2;
ll fib(ll n) {
    return ( pow(G_pos,n) - pow(G_neg,n) ) / (ld)sqrt(5);
}
ll pisano(ll m) {
    vll v {0,1};
    while(true) {
        v.pb( (v[v.size()-1]+v[v.size()-2])%m );
        v.pb( (v[v.size()-1]+v[v.size()-2])%m );

        bool equal{true};
        for(ll i{},j=v.size()/2; i<v.size()/2 ; i++,j++)
            if(v[i]!=v[j]) {equal=false; break;}
        if(equal) return (ll)v.size()/2;
    }
}
