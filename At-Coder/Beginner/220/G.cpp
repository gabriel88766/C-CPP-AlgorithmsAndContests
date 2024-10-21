#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Frac{
    ll a, b;
    Frac(){}
    Frac(ll a, ll b){
        if(b < 0){
            b = -b;
            a = -a;
        }
        if(a == 0 && b == 0) return;
        ll g = gcd(abs(a),  abs(b));
        this->a = a / g;
        this->b = b / g;
    }
    Frac(Frac a, Frac b){
        ll num = a.a * b.b;
        ll den = a.b * b.a;
        *this = Frac(num, den);
    }
    bool operator< (const Frac &f) const{
        if(a < 0 && f.a < 0){
            __int128 p1 = a;
            __int128 p2 = b;
            p1 *= f.b;
            p2 *= f.a;
            return p1 > p2;
        }else if(a < 0){
            return true;
        }else if(f.a < 0){
            return false;
        }else{
            __int128 p1 = a;
            __int128 p2 = b;
            p1 *= f.b;
            p2 *= f.a;
            return p1 < p2;
        }
        
    }
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //FIND ALL MEDIATRICS and store in a map
    //all mediatrics of a point are different.
    //mediatrics are defined by 2 points, mid  + dir (90 dg)
    int n;
    cin >> n;
    vector<tuple<int,int,int>> vt(n+1);
    vector<ll> val(n+1);
    for(int i=1;i<=n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        vt[i] = {a, b, c};
        val[i] = c;
    }

    map<pair<Frac,Frac>, vector<pair<int,int>> > mp;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            auto [x1, y1, c1] = vt[i];
            auto [x2, y2, c2] = vt[j];
            Frac cy = Frac(y1 - y2, x1-x2);
            if(cy.b == 0 && cy.a != 1) cy.a = 1;
            ll aa = -(x1+x2) * cy.b - cy.a * (y1+y2);
            ll bb = cy.b * 2;
            Frac cx = Frac(aa, bb);
            if(cx.b == 0 && cx.b != 1) cx.a = 1;
            mp[{cx,cy}].push_back({i, j});
        }
    }
    ll ans = -1;
    for(auto &[k, vec] : mp){
        if(vec.size() >= 2){
            map<pair<Frac,Frac>, ll> mp2;
            for(auto &[a, b] : vec){
                auto [x1, y1, c1] = vt[a];
                auto [x2, y2, c2] = vt[b];
                pair<Frac,Frac> pm;
                pm.first = Frac(x1+x2, 2);
                pm.second = Frac(y1+y2, 2);
                mp2[pm] = max(mp2[pm], val[a] + val[b]);
            }
            vector<ll> pv;
            for(auto [k, v] : mp2) pv.push_back(v);
            sort(pv.begin(), pv.end(), greater<ll>());
            if(pv.size() >= 2) ans = max(ans, pv[0] + pv[1]);
        }
    }
    cout << ans << "\n";

}
