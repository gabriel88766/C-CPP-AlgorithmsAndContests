#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Frac{
    ll a, b;
    Frac(ll c, ll d){a = c; b = d; }
    bool operator< (Frac c){ return a*c.b < b*c.a;}
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    set<int> posw, poss;
    for(int i=0;i<=30;i++){
        for(int j=0;j<=30;j++){
            if(i == j && j == 0) continue;
            int tt = a*i*100 + b*j*100;
            if(tt > f) break;
            else posw.insert(tt);
        }
    }
    for(int i=0;i<=3000;i++){
        for(int j=0;j<=3000;j++){
            if(i == j && j == 0) continue;
            int tt = c*i + d*j;
            if(tt > f) break;
            else poss.insert(tt);
        }   
    }
    Frac best = Frac(0, a*100);
    Frac maxf = Frac(e, 100);
    for(auto x : posw){
        for(auto y : poss){
            if(x+y > f) break;
            Frac cur = Frac(y,x+y);
            Frac aux = Frac(y,x);
            if(maxf < aux) break;
            if(best < cur){
                best = cur;
            }
        }
    }
    cout << best.b << " " << best.a;
}
