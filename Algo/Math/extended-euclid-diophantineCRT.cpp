//problem AX + BY = C, find X and Y => AX == C mod(B) => X == C/A mod(B)
ll gcd_euclid(ll a, ll b, ll &x, ll &y){ //solves ax+by = g where g = gcd(a,b)
    if(b == 0){ //meaning 1 * a - 0 * 0 = a, (gcd)
        x = 1; y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd_euclid(b, a % b, x1, y1); //if b > a then this step reverses it
    x = y1;
    y = x1 - y1 * (a/b); 
    return d;
}

bool find_xy(ll a, ll b, ll c, ll &x, ll &y){ //first solution for x >= 0, if x > 0, make '<=' in the if.
    ll g = gcd_euclid(abs(a), abs(b), x, y);
    if(c % g) return false;
    if(a < 0) x = -x;
    if(b < 0) y = -y;
    x = (x * c/g)  % (abs(b)/g); //if risk of overflow, make x positive (if(x < 0) x %= m, x += m;) and apply mulmod
    if(x < 0) x += abs(b)/g;
    y = (c - a*x) / b;
    return true;
}

//This code below come from 
//https://github.com/imeplusplus/icpc-notebook/blob/master/math/extended_euclid.cpp
bool crt_auxiliar(ll a, ll b, ll m1, ll m2, ll &ans){
    ll x, y;
    if(!find_xy(m1, m2, b - a, x, y)) return false;
    ll lcm = m1 / __gcd(m1, m2) * m2;
    ans = ((a + x % (lcm / m1) * m1) % lcm + lcm) % lcm;
    return true;
}

// find ans such that ans = a[i] mod b[i] for all 0 <= i < n or return false if not possible
// ans + k * lcm(b[i]) are also solutions
bool crt(int n, ll a[], ll b[], ll &ans){
    if(!b[0]) return false;
    ans = a[0] % b[0];
    ll l = b[0];
    for(int i = 1; i < n; i++){
    if(!b[i]) return false;
        if(!crt_auxiliar(ans, a[i] % b[i], l, b[i], ans)) return false;
        l *= (b[i] / __gcd(b[i], l));
    }
    return true;
}