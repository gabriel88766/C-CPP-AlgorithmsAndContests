#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input

    string x1, y1, r1;
    cin >> x1 >> y1 >> r1;
    auto fix = [&](string s){
        int app = 4;
        bool hpt = false;
        string rv;
        for(int j=0;j<s.size();j++){
            if(s[j] == '.') hpt = true;
            else{
                if(hpt){
                    app--;
                }
                rv += s[j];
            }
        }
        while(app--) rv += '0';
        return stoll(rv);
    };
    ll x, y, r;
    x = fix(x1);
    y = fix(y1);
    r = fix(r1);
    auto sqr = [&](ll x){
        return x*x;
    };
    
    ll ans = 0;
    for(ll i = -200001;i<=200001;i++){
        ll cn = i * 10000;
        ll dist = abs(cn - x);
        if(dist > r) continue;
        ll ymx = -200001, ymn = 200001;
        for(ll d = 200000; d >= 1; d >>= 1){
            while((ymx + d) * 10000 < y || sqr((ymx + d) * 10000 - y) + sqr(cn - x) <= r * r) ymx += d;
            while((ymn - d) * 10000 > y || sqr(y - (ymn - d) * 10000) + sqr(cn - x) <= r * r) ymn -= d;
        }
        if(ymx >= ymn) ans += ymx - ymn + 1;
    }
    cout << ans << "\n";
}
