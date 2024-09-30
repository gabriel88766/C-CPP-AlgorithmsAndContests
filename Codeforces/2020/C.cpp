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
    int t;
    cin >> t;
    while(t--){
        ll a = 0, b, c, d;
        cin >> b >> c >> d;
        ll res = b - c;
        for(int i=0;i<=62;i++){
            ll cur = 1LL << i;
            bool bt = (cur & b ? true : false);
            bool ct = (cur & c ? true : false);
            if(!bt && ct){
                res += cur;
            }
        }
        if(res <= d){
            for(int i=0;i<=62;i++){
                ll cur = 1LL << i;
                bool bt = (cur & b ? true : false);
                bool ct = (cur & c ? true : false);
                if(bt && ct){
                    if((d-res) & cur){
                        res += cur;
                    }else a |= cur;
                }
                if(!bt && !ct){
                    if((d-res) & cur){
                        res += cur;
                        a |= cur;
                    }
                }
            }
        }
        if(res == d) cout << a << "\n";
        else cout << "-1\n";
    }
}
