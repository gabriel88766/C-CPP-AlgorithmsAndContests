#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Frac{
    ll a, b, i;
    Frac(){};
    Frac(ll c, ll d){
        a = c;
        b = d;
    }
    bool operator< (const Frac &f)const {
        __int128 x1 = a;
        __int128 x2 = b;
        x1 *= f.b;
        x2 *= f.a;
        return x1 < x2;
    }
    bool operator> (const Frac &f) const{
        __int128 x1 = a;
        __int128 x2 = b;
        x1 *= f.b;
        x2 *= f.a;
        return x1 > x2;
    }
    Frac operator+ (const Frac &f) const{
        ll ra = a * f.b + f.a * b;
        ll rb = b * f.b;
        ll g = gcd(ra, rb);
        ra /= g;
        rb /= g;
        return Frac(ra, rb);
    }
};


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll k, n,  m;
    cin >> k >> n >> m;
    ll s = 0;
    vector<ll> a(k+1), b(k+1);
    for(int i=1;i<=k;i++){
        cin >> a[i];
        ll lo = 0, hi = m;
        while(lo != hi){
            ll mid = lo + (hi - lo + 1)/2;
            //check if mid / m < a[i] / n
            if(mid * n < a[i] * m) lo = mid;
            else hi = mid - 1;
        }
        b[i] = lo;
        s += lo;
    }
    // cout << m-s << endl;
    priority_queue<Frac> pq;
    for(int i=1;i<=k;i++){
        Frac f1 = {a[i], n};
        Frac f2 = {-b[i], m};
        f1 = f1 + f2;
        f1.i = i;
        pq.push(f1);
    }
    assert(m-s <= k);
    for(int i=0;i<m-s;i++){
        auto f = pq.top();
        pq.pop();
        b[f.i]++;
    }
    for(int i=1;i<=k;i++){
        cout << b[i] << " ";
    }
    cout << "\n";
}
