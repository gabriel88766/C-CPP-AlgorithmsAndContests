//Cipolla's algorithm.
//usually works in O(log n)
//but it's not proved.
ll binpow(ll a, ll b, ll m){
    a %= m;
    ll ans = 1;
    while(b){
        if(b & 1) ans = (a * ans) % m;
        a = (a*a) % m;
        b >>= 1;
    }
    return ans;
}

// a^((p-1)/2) mod p;
int legendrex(ll a, ll p){
    if(a < 0) a = (a % p) + p;
    ll val = binpow(a, (p-1)/2, p);
    return val > 1 ? -1 : val;
}

//finds n, n^2 == x mod p
ll cipolla(ll x, ll p){
    if(legendrex(x, p) == -1) return -1; //not a quadratic residue
    ll fn = -1;
    for(ll i=1; i < p;i++){ //this is fast
        if(legendrex(i*i - x, p) == -1){
            fn = i;
            break;
        }
    }
    if(fn == -1) assert(false);
    ll w = fn * fn - x;
    ll b = (p+1)/2;
    pair<ll, ll> ans = {1, 0};
    pair<ll, ll> mx = {fn, 1LL};
    auto multiply = [&](pair<ll, ll> a, pair<ll, ll> b){
        ll in = a.first * b.first + ((a.second * b.second) % p) * w;
        in %= p;
        ll re = (a.first * b.second + a.second * b.first) % p;
        return make_pair(in, re);
    };
    while(b){
        if(b & 1){
            ans = multiply(ans, mx);
        }
        mx = multiply(mx, mx);
        b >>= 1;
    }
    assert(ans.second == 0);
    ll fx = ans.first;
    if(fx < 0) fx += p;
    return fx;
}