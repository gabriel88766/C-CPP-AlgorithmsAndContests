#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Frac{
    ll a, b;
    Frac(ll a, ll b){
        if(b < 0){
            b = -b;
            a = -a;
        }
        ll g = gcd(abs(a), abs(b));
        if(b == 0) a = abs(a);
        this->a = a/g;
        this->b = b/g;
    }
    bool operator== (const Frac &u){
        return a == u.a && b == u.b;
    }
    bool operator< (const Frac &u) const {
        return a*u.b < b*u.a;
    }
};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<pair<int,int>> vp(n);
    for(int i=0;i<n;i++){
        cin >> vp[i].first >> vp[i].second;
    }
    if(n == 1 || n == 2) cout << "YES\n";
    else{
        //first, 0 and 1 in same line
        Frac f1(vp[1].second - vp[0].second, vp[1].first - vp[0].first);
        bool ok = false;
        vector<int> l2;
        for(int i=2;i<n;i++){
            Frac f2(vp[i].second - vp[0].second, vp[i].first - vp[0].first);
            if(f1 == f2);//ok
            else{
                l2.push_back(i);
            }
        }
        if(l2.size() <= 2) ok = true;
        else{
            Frac f3(vp[l2[1]].second - vp[l2[0]].second, vp[l2[1]].first - vp[l2[0]].first);
            bool cok = true;
            for(int i=2;i<l2.size();i++){
                Frac f4(vp[l2[i]].second - vp[l2[0]].second, vp[l2[i]].first - vp[l2[0]].first);
                if(f3 == f4); //ok
                else{
                    cok = false;
                }
            }
            if(cok) ok = true;
        }
        //second, 0 and 1 in different lines
        vector<Frac> v1, v2;
        for(int i=2;i<n;i++){
            Frac fx1(vp[i].second - vp[0].second, vp[i].first - vp[0].first);
            Frac fx2(vp[i].second - vp[1].second, vp[i].first - vp[1].first);
            v1.push_back(fx1);
            v2.push_back(fx2);
        }
        //suppose 2 in same line as 0
        set<Frac> sx;
        for(int i=1;i<v1.size();i++){
            if(v1[0] == v1[i]) continue;
            else sx.insert(v2[i]);
        }
        if(sx.size() == 1) ok = true;
        sx.clear();
        //suppose 2 in same line as 1
        for(int i=1;i<v1.size();i++){
            if(v2[0] == v2[i]) continue;
            else sx.insert(v1[i]);
        }
        if(sx.size() == 1) ok = true;
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
