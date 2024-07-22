//not actually the tree, but a code to find nearest p/q with denominator up to N.
//tested on 333G - atcoder.
//in python: Fraction('1.4142135623730950488016887242097').limit_denominator(1000000000000)
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1'234'567'890; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//precision error
bool aux_find(ll p, ll q, long double x, int s){
    if(s == 1) return (q*x > p);
    else return (q*x < p);
}

//works good to sqrt. tested on PE 192
bool aux_find2(__int128 p, __int128 q, long double x, int s){
    //for x = sqrt(n) for some n integer.
    ll n = x*x+0.001;
    assert(p <= 1e18); //no overflow
    __int128 ans = (p*p)/(q*q);
    if(s == 1) return ans < n;
    else return ans >= n;
}

bool aux_find3(__int128 p, __int128 q, __int128 num, __int128 den, int s){
    //p/q < num/den if s == 1
    __int128 l = p*den;
    __int128 r = q * num;
    if(s == 1) return l <= r;
    else return l >= r;
}

bool checkeq(__int128 p, __int128 q, __int128 num, __int128 den){
    //p/q = num/den 
    __int128 l = p * den;
    __int128 r = q * num;
    return l == r;
}

//find the p/q <= x with limited q max.
//experimental!
//if s == 1, find lower, if s == -1, find higher
//this version doesn't work for irrational numbers, change aux_find;
//example for sqrt is aux_find2
pair<ll, ll> findpq(ll numf, ll denf, int s = 1, ll den = 10'000'000'000LL){
    ll pl = 0;
    ll ql = 1;
    ll pr = 1;
    ll qr = 0;
    if(s == -1){swap(pl, pr); swap(ql, qr);}
    ll pm = 0, qm = 0;
    while(true){
        if(ql + qr > den) break;
        ll c = 0;
        //den * jp <= 1e18
        for(ll jp = 100'000'000; jp >= 1; jp >>= 1){
            while(ql+qr*(c+jp) <= den && aux_find3(pl + (c+jp)*pr, ql + (c+jp)*qr, numf, denf, s)) c += jp;
        }
        pm = pl + c*pr;
        qm = ql + c*qr;
        if(checkeq(pm, qm, numf, denf)) break;
        if(c == 0){
            //makes the algorithm linear sometimes. (c==0)
            //check the best next (pr + c*pl)/(qr + c*ql) > numf/denf 
            for(ll jp = 100'000'000; jp >= 1; jp >>= 1){
                while(qr+ql*(c+jp) <= den && aux_find3(pr + (c+jp)*pl, qr + (c+jp)*ql, numf, denf, -s)) c += jp;
            }
            qr += c*ql;
            pr += c*pl;
        }else{
            qr += qm;
            pr += pm;
            ql = qm;
            pl = pm;
        }
    }
    return {pm, qm};
}

// holds true if p1/q1 + p2/q2 < num/den  => p2/q2 is a better approximation
bool spcmp(__int128 p1, __int128 q1, __int128 p2, __int128 q2, __int128 num, __int128 den){
    __int128 n2 = p1*q2 + p2*q1;
    __int128 d2 = 2*q2*q1; 
    return num*d2 > den*n2;//possible overflow, check if 2*q1*q2*num may be greater than 1.7*10^38
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test inpu
    string s;
    ll n;
    cin >> s >> n;
    string s2 = s.substr(2, s.size()-2);
    int p = s2.size();
    ll den = 1;
    for(int i=0;i<p;i++) den *= 10;
    ll num = stol(s2);
    auto [p1, q1] = findpq(num, den, 1, n);
    auto [p2, q2] = findpq(num, den, -1, n);
    if(spcmp(p1, q1, p2, q2, num, den)) cout << p2 << " " << q2 << "\n";
    else cout << p1 << " " << q1 << "\n";
}   